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

    //printf("OK!\n");

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

int reddit_get_posts_hot(Reddit_t *reddit, size_t limit, const char *before, post_cb callback, void* ptr) {
    Headers_t* headers = get_headers(reddit);

    char* url = calloc(512, sizeof(char));

    strcpy(url, "https://oauth.reddit.com/hot");

    if(limit != -1){
        strcat(url, "?limit=");
        char* limit_a = calloc(8, sizeof(char));
        sprintf(limit_a, "%zu", limit);
        strcat(url, limit_a);
        free(limit_a);
    }

    if(before != NULL) {
        if (limit != -1) {
            strcat(url, "&after=");
        } else if (limit == -1) {
            strcat(url, "?after=");
        }

        strcat(url, before);
    }

    Res_t* raw = req_get(url, reddit->use_proxy, reddit->proxy, headers);

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

        callback(post, ptr);
    }

    res_free(raw);

    return EXIT_SUCCESS;
}


int subreddit_get_posts(Reddit_t *reddit, Subreddit_t *subreddit, const char* type, size_t limit, const char *before, post_cb callback,
                            void *ptr) {
    Headers_t* headers = get_headers(reddit);

    char* url = calloc(512+strlen(type), sizeof(char));

    sprintf(url, "https://oauth.reddit.com/r/%s/%s", subreddit->name, type);

    if(limit != -1){
        strcat(url, "?limit=");
        char* limit_a = calloc(8, sizeof(char));
        sprintf(limit_a, "%zu", limit);
        strcat(url, limit_a);
        free(limit_a);
    }

    if(before != NULL) {
        if (limit != -1) {
            strcat(url, "&after=");
        } else if (limit == -1) {
            strcat(url, "?after=");
        }

        strcat(url, before);
    }

    Res_t* raw = req_get(url, reddit->use_proxy, reddit->proxy, headers);

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

        callback(post, ptr);
    }

    res_free(raw);

    return EXIT_SUCCESS;
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
