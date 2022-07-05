//
// Created by Rhys on 14/03/2022.
//

#ifndef LIBREDDIT_SUBREDDIT_H
#define LIBREDDIT_SUBREDDIT_H

#include "Post.h"

#include <string>

class Reddit;

class Subreddit {
public:
    std::string name;
    unsigned long subs;
    Reddit* reddit;

    Subreddit(Reddit* reddit, std::string name, std::string url);
    Subreddit(Reddit* reddit, std::string name);

    int get_posts(std::string type, unsigned long limit, std::string before, post_cb callback, void *ptr);

    std::vector<Post*> get_posts_list(std::string type, unsigned long limit, std::string after);

    int get_posts_t(std::string type, unsigned long limit, std::string after, post_cb callback, void *ptr);

private:
    std::string url;
};

#endif //LIBREDDIT_SUBREDDIT_H
