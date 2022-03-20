//
// Created by Rhys on 13/03/2022.
//

#ifndef LIBREDDIT_NET_H
#define LIBREDDIT_NET_H

#include <curl/curl.h>

#ifdef __cplusplus
extern "C"{
#endif

const char* net_get(const char* url, int use_proxy, const char* proxy, struct curl_slist* headers);
const char* net_post_auth(const char* url, int use_proxy, const char* proxy, const char* data, struct curl_slist* headers, const char* username, const char* password);

#ifdef __cplusplus
}
#endif

#endif //LIBREDDIT_NET_H
