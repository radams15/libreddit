//
// Created by Rhys on 14/03/2022.
//

#define PRIVATE

#include <Subreddit.h>

#include <stdlib.h>
#include <string.h>


Subreddit_t* subreddit_new(const char *name) {
    Subreddit_t* out = malloc(sizeof(Subreddit_t));

    out->name = strdup(name);

    return out;
}

void subreddit_free(Subreddit_t *subreddit) {
    free((void*) subreddit->name);
    free(subreddit);
}

