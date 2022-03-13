//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <List.h>

#include <stdlib.h>

List_t* list_new(size_t elem_size) {
    List_t* out = malloc(sizeof(List_t));
    out->elem_size = elem_size;

    out->length = 0;
    out->data = malloc(1);

    return out;
}

void list_append(List_t *lst, void* data) {
    lst->length++;

    lst->data = realloc(lst->data, lst->length*lst->elem_size);
}
