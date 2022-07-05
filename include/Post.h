//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_POST_H
#define LIBREDDIT_POST_H

#include <string>

#include "Comment.h"

class Subreddit;

class Post{
public:
    std::string title;
    std::string author;
    Subreddit* subreddit;
    std::string text;
    std::string thumbnail;
    std::string url;
    unsigned long upvotes;
    unsigned long downvotes;
    unsigned long score;
    std::string id;
    std::string type;

    int get_comments(unsigned long limit, std::string after, comment_cb callback, void* ptr);

    int get_comments_t(unsigned long limit, std::string after, comment_cb callback, void *ptr);

    std::string fullname();
    std::string full_url();

    bool is_img();
};

typedef void (*post_cb)(Post*, void*);

#endif //LIBREDDIT_POST_H
