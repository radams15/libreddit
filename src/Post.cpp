//
// Created by Rhys on 13/03/2022.
//

#define PRIVATE

#include <Post.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

std::string Post::fullname() {
    return type + "_" + id;
}

std::string Post::full_url() {
    return "https://reddit.com/" + id;
}

#define CONTAINS(haystack, needle) ((haystack).find(needle) != std::string::npos)
bool Post::is_img() {
    return CONTAINS(url, ".png")
        || CONTAINS(url, ".jpg")
        || CONTAINS(url, ".gif");
}
