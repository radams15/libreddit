//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_POST_H
#define LIBREDDIT_POST_H

#include <string>
#include <vector>

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
    std::vector<Comment*> get_comments_list(unsigned long limit, std::string after);

    std::string fullname();
    std::string full_url();

    std::string get_save_path();
    std::string get_cache_path();
    std::string get_image_path();

    std::string get_thumb_path();

    bool is_img();
};

typedef void (*post_cb)(Post*, void*);

#endif //LIBREDDIT_POST_H
