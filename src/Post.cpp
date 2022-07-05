//
// Created by Rhys on 13/03/2022.
//

#include <Post.h>

#include "Reddit.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <pthread.h>
#include "cJSON.h"
#include "request.h"

typedef void*(*pthread_cb)(void*);

std::string Post::fullname() {
    return type + "_" + id;
}

std::string Post::full_url() {
    return "https://reddit.com/" + id;
}

#define CONTAINS(haystack, needle) ((haystack).find(needle) != std::string::npos)
bool Post::is_img() {
    return CONTAINS(url, ".png")
        || CONTAINS(url, ".jpg")
        || CONTAINS(url, ".gif");
}


void process_comment_listing(cJSON* listing, comment_cb callback, void* ptr, Comment* parent){
    cJSON* data = cJSON_GetObjectItem(listing, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;

    cJSON_ArrayForEach(child, children) {
        //printf("%s\n", cJSON_Print(cJSON_GetObjectItem(child, "data"))); // the first returned is t3 that is post info. The rest are t1 which are comments.
        std::string kind = cJSON_GetStringValue(cJSON_GetObjectItem(child, "kind"));
        cJSON* child_data = cJSON_GetObjectItem(child, "data");

        if(kind == "t3") {
            Comment* out = new Comment;

            out->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
            out->url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
            out->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author_fullname"));
            //out->body = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, ""));
            out->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));
            out->score = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));
            out->thumbnail = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "thumbnail"));

            callback(out, ptr, 1);
        }else if(kind == "t1") {
            Comment* out = new Comment;
            out->no_children = 0;
            out->children = (void**) malloc(0);

            out->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
            out->url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
            out->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author_fullname"));
            out->body = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "body"));
            out->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));
            out->score = (unsigned long) cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));

            cJSON* replies = cJSON_GetObjectItem(child_data, "replies");

            process_comment_listing(replies, callback, ptr, out);

            if(parent != NULL){
                parent->no_children++;
                parent->children = (void**) realloc(parent->children, (parent->no_children)*sizeof(Comment*));

                parent->children[parent->no_children-1] = out;
            }else{
                callback(out, ptr, 0);
            }

        }
    }
}

struct post_get_comments_args {
    Post* post;
    unsigned long limit;
    std::string after;
    comment_cb callback;
    void* ptr;
};

void* post_get_comments_helper(struct post_get_comments_args* args) {
    Headers_t* headers = args->post->subreddit->reddit->get_headers();

    std::string url = "https://oauth.reddit.com/comments/" + args->post->id;

    if(args->limit != -1){
        url += "?limit=" + std::to_string(args->limit);
    }

    Res_t* raw = req_get(url.c_str(), 0, NULL, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    cJSON* listing;
    cJSON_ArrayForEach(listing, json){
        process_comment_listing(listing, args->callback, args->ptr, NULL);
    }

    res_free(raw);

    return (void*)EXIT_SUCCESS;
}


int Post::get_comments(unsigned long limit, std::string after, comment_cb callback, void* ptr) {
    struct post_get_comments_args args = {
            this,
            limit,
            after,
            callback,
            ptr
    };

    post_get_comments_helper((struct post_get_comments_args*) &args);

    return EXIT_SUCCESS;
}

int Post::get_comments_t(unsigned long limit, std::string after, comment_cb callback, void *ptr) {
    pthread_t thread;

    post_get_comments_args* args = (post_get_comments_args*) malloc(sizeof(post_get_comments_args));
    args->post = this;
    args->limit = limit;
    args->after = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, (pthread_cb) &post_get_comments_helper, args);

    return res;
}