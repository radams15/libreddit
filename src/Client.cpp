//
// Created by Rhys on 06/07/2022.
//

#include "Client.h"

#include "FileUtils.h"

#include <iostream>

Client::Client(std::string path) {
    if(path == ""){
        path = FileUtils::get_save_path() + "conf.json";
    }

    reddit = NULL;

    if(FileUtils::exists(path)){
        std::string data = FileUtils::read(path);
        cJSON* json = cJSON_Parse(data.c_str());

        const char* username = cJSON_GetStringValue(cJSON_GetObjectItem(json, "username"));
        const char* password = cJSON_GetStringValue(cJSON_GetObjectItem(json, "password"));
        const char* cid = cJSON_GetStringValue(cJSON_GetObjectItem(json, "cid"));
        const char* secret = cJSON_GetStringValue(cJSON_GetObjectItem(json, "secret"));

        reddit = new Reddit(username, password, cid, secret);
    }else{
        std::cerr << "Cannot find save path: " << path << std::endl;
    }
}

Reddit* Client::getReddit() {
    return reddit;
}
