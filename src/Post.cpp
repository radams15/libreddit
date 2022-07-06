//
// Created by Rhys on 13/03/2022.
//

#include <Post.h>

#include "Reddit.h"
#include "Comment.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <pthread.h>
#include "cJSON.h"
#include "request.h"

#include <iostream>

#include "FileUtils.h"

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

#define GET_STR(json, key) cJSON_GetObjectItem(child_data, key) != NULL? cJSON_GetStringValue(cJSON_GetObjectItem(child_data, key)) : "ERROR"
#define GET_NUM(json, key) cJSON_GetObjectItem(child_data, key) != NULL? cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, key)) : 0

            out->title = GET_STR(child_data, "title");
            out->url = GET_STR(child_data, "url");
            out->author = GET_STR(child_data, "author_fullname");
            out->body = GET_STR(child_data, "body");
            out->id = GET_STR(child_data, "id");
            out->score = (unsigned long) GET_NUM(child_data, "score");

            cJSON* replies = cJSON_GetObjectItem(child_data, "replies");

            process_comment_listing(replies, callback, ptr, out);

            if(parent != NULL){
                parent->children.push_back(out);
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

std::string Post::get_image_path() {
    if(!is_img()){
        return "";
    }

    std::string uid = id + "." + FileUtils::get_extension(url);

    std::string save_path = FileUtils::get_cache_path() + "/" + uid;

    if(!FileUtils::exists(save_path)){
        int fail = req_get_dl(url.c_str(), save_path.c_str(), 0, "", subreddit->reddit->get_headers());
        if(fail){
            std::cerr << "Failed to download: " << save_path << std::endl;
            return "";
        }
    }

    return save_path;
}

std::string Post::get_thumb_path() {
    if(thumbnail.empty()){
        return "";
    }

    if(thumbnail == "nsfw" || thumbnail == "spoiler"){
        return FileUtils::get_cache_path() + "/" + thumbnail + ".png";
    }

    std::string uid = id + "_thumb." + FileUtils::get_extension(thumbnail);

    std::string save_path = FileUtils::get_cache_path() + "/" + uid;

    if(!FileUtils::exists(save_path)){
        int fail = req_get_dl(thumbnail.c_str(), save_path.c_str(), 0, "", subreddit->reddit->get_headers());
        if(fail){
            std::cerr << "Failed to download: " << save_path << std::endl;
            return "";
        }
    }

    return save_path;
}


void comments_list_adder(Comment* item, void* ptr, int is_title){
    ((std::vector<Comment*>*)ptr)->push_back(item);
}

std::vector<Comment *> Post::get_comments_list(unsigned long limit, std::string after) {
    std::vector<Comment *> out;

    get_comments(limit, after, comments_list_adder, (void*) &out);

    return out;
}