//
// Created by Rhys on 23/03/2022.
//

#ifndef REDDIT_COMMENT_H
#define REDDIT_COMMENT_H

#include "API.h"

typedef struct Comment {
    const char* title;
    const char* author;
    const char* body;
    unsigned long score;
    const char* id;
    const char* thumbnail;
    const char* url;
    void** children;
    unsigned long no_children;
} Comment_t;

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*comment_cb)(Comment_t *, void *, int);

LIBRARY_API void comment_free(Comment_t *comment);

#ifdef __cplusplus
}
#endif

#endif //REDDIT_COMMENT_H
