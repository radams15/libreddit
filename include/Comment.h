//
// Created by Rhys on 23/03/2022.
//

#ifndef REDDIT_COMMENT_H
#define REDDIT_COMMENT_H

typedef struct Comment {
    const char* title;
    const char* author;
    const char* body;
    unsigned long score;
    const char* id;
    const char* thumbnail;
    const char* url;
    struct Comment** children;
    unsigned long no_children;
} Comment_t;

typedef void (*comment_cb)(Comment_t*, void*, int);

void comment_free(Comment_t* comment);

#endif //REDDIT_COMMENT_H