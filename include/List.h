//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_LIST_H
#define LIBREDDIT_LIST_H

#include "API.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef void(* freer_cb)(void*);

typedef struct List{
    void** data;
    unsigned long length;
    freer_cb freer;
#ifdef PRIVATE
    unsigned long elem_size;
#endif
} List_t;

LIBRARY_API List_t* list_new(unsigned long elem_size, freer_cb freer);

LIBRARY_API void list_append(List_t *lst, void* data);

LIBRARY_API void* list_get(List_t* lst, int id);

LIBRARY_API void list_free(List_t* lst);

#define LIST(type, freer) list_new(sizeof(type), freer)

#define LIST_FREE(lst, type) for(unsigned long i=0 ; i<lst->length ; i++){ lst->freer((type *)lst->data[i]); }

#ifdef __cplusplus
}
#endif

#endif //LIBREDDIT_LIST_H
