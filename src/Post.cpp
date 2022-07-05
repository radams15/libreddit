//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <Post.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

std::string post_fullname(Post* post) {
    char* out = (char*) calloc(post->id.length()+post->type.length()+1, sizeof(char));

    sprintf(out, "%s_%s", post->type.c_str(), post->id.c_str());

    return out;
}

std::string post_url(Post* post) {
    char* out = (char*) calloc(strlen(post->id.c_str())+64, sizeof(char));

    sprintf(out, "https://reddit.com/%s", post->id.c_str());

    return out;
}

#define CONTAINS(haystack, needle) (strstr(haystack.c_str(), needle) != NULL)

int post_is_img(Post* post) {
    return CONTAINS(post->url, ".png")
        || CONTAINS(post->url, ".jpg")
        || CONTAINS(post->url, ".gif");
}
