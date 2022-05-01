//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <Reddit.h>
#include <request.h>

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void* iptr(int res){
    int* out = malloc(sizeof(int));
    *out = res;

    return (void*) out;
}

Headers_t* get_headers(Reddit_t* reddit){
    Headers_t* out = NULL;

    out = headers_append(out, "User-Agent", "libredd/0.0.1");

    if(reddit->authenticated){
        char* auth = calloc(strlen(reddit->token)+32, sizeof(char));
        sprintf(auth, "bearer %s", reddit->token);
        headers_append(out, "Authorization", auth);
        free(auth);
    }

    return out;
}

int login(Reddit_t* reddit, const char *username, const char *password, const char *client_id, const char *secret){
    char* data = calloc(strlen(username)+strlen(password)+64, sizeof(char));

    sprintf(data, "grant_type=password&username=%s&password=%s", username, password);

    Headers_t* headers = get_headers(reddit);

    Res_t* raw = req_post_auth("https://www.reddit.com/api/v1/access_token", reddit->use_proxy, reddit->proxy, data, headers, client_id, secret);

    headers_free(headers);
    free(data);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return EXIT_FAILURE;
    }

    reddit->token = cJSON_GetStringValue(cJSON_GetObjectItem(json, "access_token"));

    return EXIT_SUCCESS;
}

Reddit_t* reddit_new(const char* username, const char *password, const char *client_id, const char *secret) {
    Reddit_t* out = malloc(sizeof(Reddit_t));

    out->use_proxy = 0;
    out->proxy = strdup("http://http.therhys.co.uk/yt/proxy.php?url=");
    out->authenticated = 0;

    if(login(out, username, password, client_id, secret) == EXIT_SUCCESS){
        out->authenticated = 1;
        return out;
    }

    fprintf(stderr, "Failed to login to reddit.");

    out->authenticated = 0;

    return out;
}

int reddit_get_login_status(Reddit_t* reddit){
    Headers_t* headers = get_headers(reddit);

    char* url = calloc(512, sizeof(char));

    strcpy(url, "https://oauth.reddit.com/api/v1/scopes");

    Res_t* raw = req_get(url, reddit->use_proxy, reddit->proxy, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        res_free((void*) raw);

        return UNAUTHENTICATED;
    }

    res_free((void*) raw);

    return AUTHENTICATED;
}

Reddit_t* reddit_new_with_token(const char *username, const char* token) {
    Reddit_t* out = malloc(sizeof(Reddit_t));

    out->use_proxy = 0;
    out->authenticated = 1; // Just so that get_headers uses the token anyway.

    out->token = strdup(token);

    out->proxy = strdup("http://http.therhys.co.uk/yt/proxy.php?url=");

    out->authenticated = reddit_get_login_status(out);

    return out;
}

Post_t* process_post(cJSON* child){
    cJSON* child_data = cJSON_GetObjectItem(child, "data");

    Post_t* post = malloc(sizeof(Post_t));

    post->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
    post->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author_fullname"));
    post->subreddit = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "subreddit"));
    post->text = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "selftext"));
    post->upvotes = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "ups"));
    post->downvotes = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "downs"));
    post->score = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));

    post->type = cJSON_GetStringValue(cJSON_GetObjectItem(child, "kind"));
    post->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));

    const char* thumb = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "thumbnail"));
    if(strcmp(thumb, "self") != 0){
        post->thumbnail = thumb;
    }else{
        post->thumbnail = NULL;
    }

    return post;
}

struct get_post_hot_args {
    Reddit_t *reddit;
    unsigned long limit;
    const char *before;
    post_cb callback;
    void* ptr;
};

void* reddit_get_posts_hot_helper(struct get_post_hot_args* args) {
    Headers_t* headers = get_headers(args->reddit);

    char* url = calloc(512, sizeof(char));

    strcpy(url, "https://oauth.reddit.com/hot");

    if(args->limit != -1){
        strcat(url, "?limit=");
        char* limit_a = calloc(8, sizeof(char));
        sprintf(limit_a, "%zu", args->limit);
        strcat(url, limit_a);
        free(limit_a);
    }

    if(args->before != NULL) {
        if (args->limit != -1) {
            strcat(url, "&after=");
        } else if (args->limit == -1) {
            strcat(url, "?after=");
        }

        strcat(url, args->before);
    }

    Res_t* raw = req_get(url, args->reddit->use_proxy, args->reddit->proxy, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return EXIT_FAILURE;
    }

    cJSON* data = cJSON_GetObjectItem(json, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;
    cJSON_ArrayForEach(child, children){
        Post_t* post = process_post(child);

        args->callback(post, args->ptr);
    }

    res_free(raw);

    return iptr(EXIT_SUCCESS);
}

int reddit_get_posts_hot(Reddit_t *reddit, unsigned long limit, const char *before, post_cb callback, void* ptr) {
    struct get_post_hot_args args = {
            reddit,
            limit,
            before,
            callback,
            ptr
    };

    return reddit_get_posts_hot_helper(&args);
}



struct subreddit_get_posts_args {
    Reddit_t *reddit;
    Subreddit_t *subreddit;
    const char* type;
    unsigned long limit;
    const char *before;
    post_cb callback;
    void* ptr;
};

void* subreddit_get_posts_helper(struct subreddit_get_posts_args* args) {
    Headers_t* headers = get_headers(args->reddit);

    char* url = calloc(512+strlen(args->type), sizeof(char));

    sprintf(url, "https://oauth.reddit.com/r/%s/%s", args->subreddit->name, args->type);

    if(args->limit != -1){
        strcat(url, "?limit=");
        char* limit_a = calloc(8, sizeof(char));
        sprintf(limit_a, "%zu", args->limit);
        strcat(url, limit_a);
        free(limit_a);
    }

    if(args->before != NULL) {
        if (args->limit != -1) {
            strcat(url, "&after=");
        } else if (args->limit == -1) {
            strcat(url, "?after=");
        }

        strcat(url, args->before);
    }

    Res_t* raw = req_get(url, args->reddit->use_proxy, args->reddit->proxy, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return EXIT_FAILURE;
    }

    cJSON* data = cJSON_GetObjectItem(json, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;
    cJSON_ArrayForEach(child, children){
        Post_t* post = process_post(child);

        args->callback(post, args->ptr);
    }

    res_free(raw);

    return iptr(EXIT_SUCCESS);
}

int subreddit_get_posts(Reddit_t *reddit, Subreddit_t *subreddit, const char* type, unsigned long limit, const char *before, post_cb callback,
                        void *ptr) {
    struct subreddit_get_posts_args args = {
            reddit,
            subreddit,
            type,
            limit,
            before,
            callback,
            ptr
    };

    return subreddit_get_posts_helper(&args);
}

List_t* reddit_get_subbed_list(Reddit_t *reddit) {
    List_t* out = LIST(Subreddit_t, (freer_cb) subreddit_free);

    Headers_t* headers = get_headers(reddit);

    Res_t* raw = req_get("https://oauth.reddit.com/subreddits/mine/subscriber?limit=500", reddit->use_proxy, reddit->proxy, headers);

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

        const char* url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
        const char* name = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "display_name"));

        Subreddit_t* sub = subreddit_new(name);
        sub->url = url;

        list_append(out, sub);
    }

    res_free(raw);

    return out;
}

void process_listing(cJSON* listing, comment_cb callback, void* ptr, Comment_t* parent){
    cJSON* data = cJSON_GetObjectItem(listing, "data");
    cJSON* children = cJSON_GetObjectItem(data, "children");

    cJSON* child;

    cJSON_ArrayForEach(child, children) {
        //printf("%s\n", cJSON_Print(cJSON_GetObjectItem(child, "data"))); // the first returned is t3 that is post info. The rest are t1 which are comments.
        const char* kind = cJSON_GetStringValue(cJSON_GetObjectItem(child, "kind"));
        cJSON* child_data = cJSON_GetObjectItem(child, "data");

        if(strcmp(kind, "t3") == 0){
            Comment_t* out = (Comment_t*) malloc(sizeof(Comment_t));

            out->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
            out->url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
            out->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author_fullname"));
            //out->body = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, ""));
            out->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));
            out->score = cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));
            out->thumbnail = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "thumbnail"));

            callback(out, ptr, 1);
        }else if(strcmp(kind, "t1") == 0){
            Comment_t* out = (Comment_t*) malloc(sizeof(Comment_t));
            out->no_children = 0;
            out->children = malloc(0);

            out->title = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "title"));
            out->url = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "url"));
            out->author = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "author_fullname"));
            out->body = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "body"));
            out->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));
            out->score = (unsigned long) cJSON_GetNumberValue(cJSON_GetObjectItem(child_data, "score"));

            cJSON* replies = cJSON_GetObjectItem(child_data, "replies");

            process_listing(replies, callback, ptr, out);

            if(parent != NULL){
                parent->no_children++;
                parent->children = realloc(parent->children, (parent->no_children)*sizeof(Comment_t*));

                parent->children[parent->no_children-1] = out;
            }else{
                callback(out, ptr, 0);
            }

        }
    }
}

struct post_get_comments_args {
    Reddit_t* reddit;
    Post_t* post;
    unsigned long limit;
    const char* after;
    comment_cb callback;
    void* ptr;
};

void* post_get_comments_helper(struct post_get_comments_args* args) {
    Headers_t* headers = get_headers(args->reddit);

    char* url = calloc(512+strlen(args->post->id), sizeof(char));

    sprintf(url, "https://oauth.reddit.com/comments/%s", args->post->id);

    if(args->limit != -1){
        strcat(url, "?limit=");
        char* limit_a = calloc(8, sizeof(char));
        sprintf(limit_a, "%zu", args->limit);
        strcat(url, limit_a);
        free(limit_a);
    }


    Res_t* raw = req_get(url, args->reddit->use_proxy, args->reddit->proxy, headers);

    headers_free(headers);

    cJSON* json = cJSON_Parse(raw->data);

    cJSON* listing;
    cJSON_ArrayForEach(listing, json){
        process_listing(listing, args->callback, args->ptr, NULL);
    }

    res_free(raw);

    return iptr(EXIT_SUCCESS);
}

int post_get_comments(Reddit_t* reddit, Post_t* post, unsigned long limit, const char* after, comment_cb callback, void* ptr) {
    struct post_get_comments_args args = {
            reddit,
            post,
            limit,
            after,
            callback,
            ptr
    };

    return post_get_comments_helper(&args);
}

void list_adder(void* item, void* ptr){
    list_append((List_t*) ptr, item);
}

List_t* reddit_get_posts_hot_list(Reddit_t *reddit, unsigned long limit, const char *after) {
    List_t* out = LIST(Post_t, post_free);

    reddit_get_posts_hot(reddit, limit, after, list_adder, (void*) out);

    return out;
}

List_t* subreddit_get_posts_list(Reddit_t *reddit, Subreddit_t *subreddit, const char *type, unsigned long limit,
                                 const char *after) {
    List_t* out = LIST(Post_t, post_free);

    subreddit_get_posts(reddit, subreddit, type, limit, after, list_adder, (void*) out);

    return out;
}

#if ENABLE_THREADING
int reddit_get_posts_hot_t(Reddit_t *reddit, unsigned long limit, const char *after, post_cb callback, void *ptr) {
    pthread_t thread;

    struct get_post_hot_args* args = malloc(sizeof(struct get_post_hot_args));
    args->reddit = reddit;
    args->limit = limit;
    args->before = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, &reddit_get_posts_hot_helper, args);

    return res;
}

int subreddit_get_posts_t(Reddit_t *reddit, Subreddit_t *subreddit, const char *type, unsigned long limit,
                          const char *after, post_cb callback, void *ptr) {
    pthread_t thread;

    struct subreddit_get_posts_args* args = malloc(sizeof(struct subreddit_get_posts_args));
    args->reddit = reddit;
    args->subreddit = subreddit;
    args->type = type;
    args->limit = limit;
    args->before = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, &subreddit_get_posts, args);

    return res;
}

int post_get_comments_t(Reddit_t *reddit, Post_t *post, unsigned long limit, const char *after, comment_cb callback,
                        void *ptr) {
    pthread_t thread;

    struct post_get_comments_args* args = malloc(sizeof(struct post_get_comments_args));
    args->reddit = reddit;
    args->post = post;
    args->limit = limit;
    args->after = after;
    args->callback = callback;
    args->ptr = ptr;

    int res = pthread_create(&thread, NULL, &post_get_comments_helper, args);

    return res;
}
#endif