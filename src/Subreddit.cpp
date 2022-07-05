//
// Created by Rhys on 14/03/2022.
//

#define PRIVATE

#include <Subreddit.h>

Subreddit::Subreddit(Reddit *reddit, std::string name, std::string url) {
    this->name = name;
    this->reddit = reddit;
    this->url = url;
}


Subreddit::Subreddit(Reddit *reddit, std::string name) {
    this->name = name;
    this->reddit = reddit;

    this->url = "/r/" + this->name + "/";
}
