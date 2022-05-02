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
    free(post->url);
    free(post->title);
    free(post);
}

#define CONTAINS(haystack, needle) (strstr(haystack, needle) != NULL)

int post_is_img(Post_t *post) {
    return CONTAINS(post->url, ".png")
        || CONTAINS(post->url, ".jpg")
        || CONTAINS(post->url, ".gif");
}
