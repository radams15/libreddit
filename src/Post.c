//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <Post.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char* post_fullname(Post_t *post) {
    char* out = calloc(strlen(post->id)+strlen(post->type)+1, sizeof(char));

    sprintf(out, "%s%s", post->id, post->type);

    return out;
}

const char* post_url(Post_t *post) {
    char* out = calloc(strlen(post->id)+64, sizeof(char));

    sprintf(out, "https://reddit.com/%s", post->id);

    return out;
}
