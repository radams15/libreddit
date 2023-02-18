//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_REDDIT_H
#define LIBREDDIT_REDDIT_H

// https://www.reddit.com/dev/api/

#include <List.h>
#include <Post.h>
#include <Subreddit.h>
#include <Comment.h>

#include "API.h"

#ifdef __cplusplus
extern "C"{
#endif

#define AUTHENTICATED 1
#define UNAUTHENTICATED 0

typedef struct Reddit{
    const char* username;
    int authenticated;
#ifdef PRIVATE
    const char* client_id;
    const char* client_secret;
    const char* password;
    const char* token;
#endif
} Reddit_t;

LIBRARY_API Reddit_t* reddit_new(const char* username, const char* password, const char* client_id, const char* secret);
LIBRARY_API Reddit_t* reddit_new_with_token(const char *username, const char* token);

LIBRARY_API int reddit_get_posts_hot(Reddit_t* reddit, unsigned long limit, const char* after, post_cb callback, void* ptr);
LIBRARY_API int reddit_get_posts_hot_t(Reddit_t* reddit, unsigned long limit, const char* after, post_cb callback, void* ptr);
LIBRARY_API List_t* reddit_get_posts_hot_list(Reddit_t* reddit, unsigned long limit, const char* after);
LIBRARY_API Post_t*  reddit_get_post_by_id(Reddit_t* reddit, const char* id);

LIBRARY_API List_t* reddit_get_subbed_list(Reddit_t* reddit);

LIBRARY_API int reddit_get_login_status(Reddit_t* reddit);

LIBRARY_API int subreddit_get_posts(Reddit_t* reddit, Subreddit_t* subreddit, const char* type, unsigned long limit, const char* after, post_cb callback, void* ptr);
LIBRARY_API int subreddit_get_posts_t(Reddit_t* reddit, Subreddit_t* subreddit, const char* type, unsigned long limit, const char* after, post_cb callback, void* ptr);
LIBRARY_API List_t* subreddit_get_posts_list(Reddit_t* reddit, Subreddit_t* subreddit, const char* type, unsigned long limit, const char* after);

LIBRARY_API int post_get_comments(Reddit_t* reddit, Post_t* post, unsigned long limit, const char* after, comment_cb callback, void* ptr);
LIBRARY_API int post_get_comments_t(Reddit_t* reddit, Post_t* post, unsigned long limit, const char* after, comment_cb callback, void* ptr);

#ifdef __cplusplus
}
#endif

#endif //LIBREDDIT_REDDIT_H
