cmake_minimum_required(VERSION 3.00)
project(reddit C)

set(CMAKE_C_STANDARD 99)

option(BUILD_TEST "Builds a test app" ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

add_library(reddit SHARED test/main.c src/Reddit.c headers/Reddit.h src/Net.c src/Net.h test/SECRETS.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c src/Post.c headers/Post.h src/List.c headers/List.h src/Subreddit.c headers/Subreddit.h headers/defs.h)

target_include_directories(reddit PRIVATE ${CURL_INCLUDE_DIRS} headers lib/cJSON)
target_link_libraries(reddit PRIVATE ${CURL_LIBRARIES})

if(BUILD_TEST)
    add_executable(redd test/main.c)
    target_link_libraries(redd PRIVATE reddit)
    target_include_directories(redd PRIVATE headers)
endif()
