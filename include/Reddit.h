//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_REDDIT_H
#define LIBREDDIT_REDDIT_H

// https://www.reddit.com/dev/api/

#include <Post.h>
#include <Subreddit.h>
#include <Comment.h>

#include <string>

#define AUTHENTICATED 1
#define UNAUTHENTICATED 0

class Reddit {
public:
    bool authenticated;

    Reddit(std::string username, std::string password, std::string client_id, std::string secret);
    Reddit(std::string username, std::string token);

    struct Headers* get_headers();

    int get_posts_hot(unsigned long limit, std::string before, post_cb callback, void* ptr);

    std::vector<Subreddit*> get_subbed_list();
    std::vector<Post*> get_posts_hot_list(unsigned long limit, std::string after);

private:
    std::string token;

    int login(std::string username, std::string password, std::string client_id, std::string secret);
    int get_login_status();
};

#endif //LIBREDDIT_REDDIT_H
