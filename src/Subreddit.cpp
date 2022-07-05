//
// Created by Rhys on 14/03/2022.
//

#define PRIVATE

#include <Subreddit.h>

#include "Reddit.h"

#include <pthread.h>
#include <vector>
#include "cJSON.h"
#include "request.h"

typedef void*(*pthread_cb)(void*);

Subreddit::Subreddit(Reddit *reddit, std::string name, std::string url) {
    this->name = name;
    this->reddit = reddit;
    this->url = url;
}


Subreddit::Subreddit(Reddit *reddit, std::string name) {
    this->name = name;
    this->reddit = reddit;

    this->url = "/r/" + this->name + "/";
}

void sub_list_adder(void* item, void* ptr){
    ((std::vector<Subreddit*>*)ptr)->push_back((Subreddit*) item);
}

struct subreddit_get_posts_args {
    Reddit* reddit;
    Subreddit* subreddit;
    std::string type;
    unsigned long limit;
    std::string after;
    post_cb callback;
    void* ptr;
};

void* subreddit_get_posts_helper(struct subreddit_get_posts_args* args) {
    Headers_t* headers = args->reddit->get_headers();

    std::string url = "https://oauth.reddit.com/r/" + args->subreddit->name + "/" + args->type;

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

    return (void*) EXIT_SUCCESS;
}

int Subreddit::get_posts(std::string type, unsigned long limit, std::string before, post_cb callback,
                         void *ptr) {
    subreddit_get_posts_args args = {
            reddit,
            this,
            type,
            limit,
            before,
            callback,
            ptr
    };

    subreddit_get_posts_helper((struct subreddit_get_posts_args*) &args);

    return (int) EXIT_SUCCESS;
}

std::vector<Post*> Subreddit::get_posts_list(std::string type, unsigned long limit, std::string after) {
    std::vector<Post*> out;

    get_posts(type, limit, after, (post_cb) sub_list_adder, (void*) &out);

    return out;
}

int Subreddit::get_posts_t(std::string type, unsigned long limit, std::string after, post_cb callback, void *ptr) {
    pthread_t thread;

    subreddit_get_posts_args* args = (subreddit_get_posts_args*) malloc(sizeof(subreddit_get_posts_args));
    args->reddit = reddit;
    args->subreddit = this;
    args->type = type;
    args->limit = limit;
    args->after = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, (pthread_cb) &subreddit_get_posts_helper, args);

    return res;
}