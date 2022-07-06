//
// Created by Rhys on 23/03/2022.
//

#ifndef REDDIT_COMMENT_H
#define REDDIT_COMMENT_H

class Post;

#include <string>
#include <vector>

struct Comment {
    Post* post;

    std::string title;
    std::string author;
    std::string body;
    unsigned long score;
    std::string id;
    std::string thumbnail;
    std::string url;
    std::vector<Comment*> children;
};

typedef void (*comment_cb)(Comment*, void *, int);

#endif //REDDIT_COMMENT_H
