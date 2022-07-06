//
// Created by Rhys on 06/07/2022.
//

#ifndef REDDIT_CLIENT_H
#define REDDIT_CLIENT_H

#include <string>
#include "Reddit.h"

class Client {
private:
    Reddit* reddit;
public:
    Client(std::string path="");

    Reddit* getReddit();
};


#endif //REDDIT_CLIENT_H
