//
// Created by Rhys on 14/03/2022.
//

#ifndef LIBREDDIT_SUBREDDIT_H
#define LIBREDDIT_SUBREDDIT_H

#include "API.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Subreddit {
    const char* name;
    unsigned long subs;
#ifdef PRIVATE
    const char* url;
#endif
} Subreddit_t;

LIBRARY_API Subreddit_t* subreddit_new(const char* name);

LIBRARY_API void subreddit_free(Subreddit_t* subreddit);

#ifdef __cplusplus
}
#endif

#endif //LIBREDDIT_SUBREDDIT_H
