//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <Reddit.h>
#include <Net.h>

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define header_free curl_slist_free_all

struct curl_slist* get_headers(Reddit_t* reddit){
    struct curl_slist* out = NULL;

    out = curl_slist_append(out, "User-Agent: libredd/0.0.1");

    if(reddit->authenticated){
        char* auth = calloc(strlen(reddit->token)+64, sizeof(char));
        sprintf(auth, "Authorization: bearer %s", reddit->token);
        curl_slist_append(out, auth);
    }

    return out;
}

int login(Reddit_t* reddit, const char *username, const char *password, const char *client_id, const char *secret){
    char* data = calloc(strlen(username)+strlen(password)+64, sizeof(char));

    sprintf(data, "grant_type=password&username=%s&password=%s", username, password);

    struct curl_slist* headers = get_headers(reddit);

    const char* raw = net_post_auth("https://www.reddit.com/api/v1/access_token", reddit->use_proxy, reddit->proxy, data, headers, client_id, secret);

    header_free(headers);
    free(data);

    cJSON* json = cJSON_Parse(raw);

    if(cJSON_GetArraySize(json) == 0){
        cJSON_free(json);

        return EXIT_FAILURE;
    }

    reddit->token = cJSON_GetStringValue(cJSON_GetObjectItem(json, "access_token"));

    return EXIT_SUCCESS;
}



Reddit_t* reddit_new(const char *username, const char *password, const char *client_id, const char *secret) {
    Reddit_t* out = malloc(sizeof(Reddit_t));

    out->use_proxy = 0;
    out->proxy = strdup("http://therhys.co.uk/yt/proxy.php?url=");

    if(login(out, username, password, client_id, secret) == EXIT_SUCCESS){
        out->authenticated = 1;
        return out;
    }

    fprintf(stderr, "Failed to login to reddit.");

    out->authenticated = 0;

    return out;
}

Reddit_t* reddit_new_with_token(const char *username, const char* token) {
    Reddit_t* out = malloc(sizeof(Reddit_t));

    out->use_proxy = 0;
    out->proxy = strdup("http://therhys.co.uk/yt/proxy.php?url=");

    out->authenticated = 1;

    out->token = strdup(token);

    return out;
}

int reddit_get_hot(Reddit_t *reddit, size_t limit, const char *before, post_cb callback, void* ptr) {
    struct curl_slist* headers = get_headers(reddit);

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
            strcat(url, "&before=");
        } else if (limit == -1) {
            strcat(url, "?before=");
        }

        strcat(url, before);
    }

    const char* raw = net_get(url, reddit->use_proxy, reddit->proxy, headers);

    header_free(headers);

    cJSON* json = cJSON_Parse(raw);

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

        post->type = cJSON_GetStringValue(cJSON_GetObjectItem(child, "type"));
        post->id = cJSON_GetStringValue(cJSON_GetObjectItem(child_data, "id"));

        callback(post, ptr);
    }

    return EXIT_SUCCESS;
}
