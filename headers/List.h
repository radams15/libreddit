//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_LIST_H
#define LIBREDDIT_LIST_H

#include <stddef.h>

typedef struct List{
    void* data;
    size_t length;
#ifdef PRIVATE
    size_t elem_size;
#endif
} List_t;

List_t* list_new(size_t elem_size);

void list_append(List_t *lst, void* data);

#endif //LIBREDDIT_LIST_H
