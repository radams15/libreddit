//
// Created by Rhys on 13/03/2022.
//

#include <Reddit.h>
#include <request.h>

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <vector>

#include "Subreddit.h"

int strlen(std::string str){
    return str.length();
}

struct Headers* Reddit::get_headers(){
    Headers_t* out = NULL;

    out = headers_append(out, "User-Agent", "libredd/0.0.1");

    if(authenticated){
        std::string auth = "bearer " + token;
        headers_append(out, "Authorization", auth.c_str());
    }

    return out;
}

int Reddit::login(std::string username, std::string password, std::string client_id, std::string secret){
    Headers_t* headers = get_headers();

    std::string data = "grant_type=password&username="+username+"&password="+password;

    Res_t* raw = req_post_auth("https://www.reddit.com/api/v1/access_token", 0, NULL, data.c_str(), headers, client_id.c_str(), secret.c_str());

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return EXIT_FAILURE;
    }

    token = cJSON_GetStringValue(cJSON_GetObjectItem(json, "access_token"));

    return EXIT_SUCCESS;
}

Reddit::Reddit(std::string username, std::string password, std::string client_id, std::string secret) {
    authenticated = 0;

    if(login(username, password, client_id, secret) == EXIT_SUCCESS){
        authenticated = true;
    }else {
        fprintf(stderr, "Failed to login to reddit.");
    }
}

int Reddit::get_login_status(){
    Headers_t* headers = get_headers();

    std::string url = "https://oauth.reddit.com/api/v1/scopes";

    Res_t* raw = req_get(url.c_str(), false, NULL, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        res_free(raw);

        return UNAUTHENTICATED;
    }

    res_free(raw);

    return AUTHENTICATED;
}

Reddit::Reddit(std::string username, std::string token) {
    authenticated = true; // Just so that get_headers uses the token anyway.

    this->token = token;

    authenticated = get_login_status();
}

Post* process_post(Reddit* reddit, cJSON* child){
    cJSON* child_data = cJSON_GetObjectItem(child, "data");

    Post* post = new Post();

    post->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
    post->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author"));
    post->subreddit = new Subreddit(reddit, cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "subreddit")));
    post->text = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "selftext"));
    post->url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
    post->upvotes = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "ups"));
    post->downvotes = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "downs"));
    post->score = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));

    post->type = cJSON_GetStringValue(cJSON_GetObjectItem(child, "kind"));
    post->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));

    std::string thumb = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "thumbnail"));
    if(thumb == "self"){
        post->thumbnail = "";
    }else{
        post->thumbnail = thumb;
    }

    return post;
}

struct get_post_hot_args {
    Reddit* reddit;
    unsigned long limit;
    std::string after;
    post_cb callback;
    void* ptr;
};

void* reddit_get_posts_hot_helper(struct get_post_hot_args* args) {
    Headers_t* headers = args->reddit->get_headers();

    std::string url ="https://oauth.reddit.com/hot";

    if(args->limit != -1){
        url += "?limit=" + std::to_string(args->limit);
    }

    if(! args->after.empty()) {
        if (args->limit != -1) {
            url += "&after=" + std::to_string(args->limit);
        } else if (args->limit == -1) {
            url += "?after=" + std::to_string(args->limit);
        }

        url += args->after;
    }

    Res_t* raw = req_get(url.c_str(), 0, NULL, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return (void*) EXIT_FAILURE;
    }

    cJSON* data = cJSON_GetObjectItem(json, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;
    cJSON_ArrayForEach(child, children){
        Post* post = process_post(args->reddit, child);

        args->callback(post, args->ptr);
    }

    res_free(raw);

    return (void*)EXIT_SUCCESS;
}

int Reddit::get_posts_hot(unsigned long limit, std::string before, post_cb callback, void* ptr) {
    struct get_post_hot_args args = {
            this,
            limit,
            before,
            callback,
            ptr
    };

    reddit_get_posts_hot_helper((struct get_post_hot_args*) &args);

    return (int) EXIT_SUCCESS;
}


std::vector<Subreddit*> Reddit::get_subbed_list() {
    std::vector<Subreddit*> out;

    Headers_t* headers = get_headers();

    Res_t* raw = req_get("https://oauth.reddit.com/subreddits/mine/subscriber?limit=500", 0, NULL, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return out;
    }

    cJSON* data = cJSON_GetObjectItem(json, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;
    cJSON_ArrayForEach(child, children) {
        cJSON *child_data = cJSON_GetObjectItem(child, "data");

        std::string url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
        std::string name = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "display_name"));

        Subreddit* sub = new Subreddit(this, name, url);

        out.push_back(sub);
    }

    res_free(raw);

    return out;
}

void post_list_adder(void* item, void* ptr){
    ((std::vector<Post*>*)ptr)->push_back((Post*) item);
}

std::vector<Post*> Reddit::get_posts_hot_list(unsigned long limit, std::string after) {
    std::vector<Post*> out;

    get_posts_hot(limit, after, (post_cb) post_list_adder, (void*) &out);

    return out;
}

typedef void*(*pthread_cb)(void*);

#if ENABLE_THREADING

int reddit_get_posts_hot_t(Reddit *reddit, unsigned long limit, std::string after, post_cb callback, void *ptr) {
    pthread_t thread;

    get_post_hot_args* args = (get_post_hot_args*) malloc(sizeof(get_post_hot_args));
    args->reddit = reddit;
    args->limit = limit;
    args->after = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, (pthread_cb) &reddit_get_posts_hot_helper, args);

    return res;
}

#endif