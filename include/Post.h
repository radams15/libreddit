//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_POST_H
#define LIBREDDIT_POST_H

#include "API.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Post{
    const char* title;
    const char* author;
    const char* subreddit;
    const char* text;
    const char* thumbnail;
    unsigned long upvotes;
    unsigned long downvotes;
    unsigned long score;
    const char* id;
#ifdef PRIVATE
    const char* type;
#endif
} Post_t;

LIBRARY_API typedef void (*post_cb)(Post_t*, void*);

LIBRARY_API const char* post_fullname(Post_t* post);
LIBRARY_API const char* post_url(Post_t* post);

LIBRARY_API void post_free(Post_t* post);

#ifdef __cplusplus
}
#endif

#endif //LIBREDDIT_POST_H
