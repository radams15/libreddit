//
// Created by Rhys on 13/03/2022.
//

#include "Net.h"

#include <string.h>
#include <stdlib.h>

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(1);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

const char* net_get(const char* url, int use_proxy, const char* proxy, struct curl_slist* headers) {
    CURL *curl;
    CURLcode res;

    char* real_url;
    if(use_proxy){
        unsigned long len = strlen(proxy) + strlen(url) + 8;
        real_url = calloc(len, sizeof(char));

        sprintf(real_url, "%s%s", proxy, url);
    }else{
        real_url = strdup(url);
    }

    curl = curl_easy_init();
    if(curl) {
        struct string s;
        init_string(&s);

        if(headers != NULL){
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }

        curl_easy_setopt(curl, CURLOPT_URL, real_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);

        free(real_url);

        return s.ptr;
    }

    return NULL;
}

const char *
net_post_auth(const char *url, int use_proxy, const char *proxy, const char *data, struct curl_slist *headers,
              const char *username, const char *password) {
    CURL *curl;
    CURLcode res;

    char* real_url;
    if(use_proxy){
        unsigned long len = strlen(proxy) + strlen(url) + 8;
        real_url = calloc(len, sizeof(char));

        sprintf(real_url, "%s%s", proxy, url);
    }else{
        real_url = strdup(url);
    }

    curl = curl_easy_init();
    if(curl) {
        struct string s;
        init_string(&s);

        if(headers != NULL){
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }

        curl_easy_setopt(curl, CURLOPT_URL, real_url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);

        free(real_url);

        return s.ptr;
    }

    return NULL;
}
