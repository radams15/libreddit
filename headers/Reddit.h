//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_REDDIT_H
#define LIBREDDIT_REDDIT_H

#include <List.h>
#include <Post.h>

typedef struct Reddit{
    const char* username;
    int authenticated;
#ifdef PRIVATE
    int use_proxy;
    const char* proxy;
    const char* client_id;
    const char* client_secret;
    const char* password;
    const char* token;
#endif
} Reddit_t;

Reddit_t* reddit_new(const char* username, const char* password, const char* client_id, const char* secret);
Reddit_t* reddit_new_with_token(const char *username, const char* token);

int reddit_get_hot(Reddit_t* reddit, size_t limit, const char* before, post_cb callback, void* ptr);

#endif //LIBREDDIT_REDDIT_H
