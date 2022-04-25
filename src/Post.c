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

    sprintf(out, "%s_%s", post->type, post->id);

    return out;
}

const char* post_url(Post_t *post) {
    char* out = calloc(strlen(post->id)+64, sizeof(char));

    sprintf(out, "https://reddit.com/%s", post->id);

    return out;
}

void post_free(Post_t *post) {
    free(post->id);
    free(post->type);
    free(post->author);
    free(post->subreddit);
    free(post->thumbnail);
    free(post->title);
    free(post);
}
