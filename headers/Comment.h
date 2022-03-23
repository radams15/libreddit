//
// Created by Rhys on 23/03/2022.
//

#ifndef REDDIT_COMMENT_H
#define REDDIT_COMMENT_H

#include <defs.h>

typedef struct Comment {
    const char* author;
    const char* body;
    size_t score;
    const char* id;
} Comment_t;

typedef void (*comment_cb)(Comment_t*, void*);

void comment_free(Comment_t* comment);

#endif //REDDIT_COMMENT_H
