cmake_minimum_required(VERSION 2.8)
project(reddit C)

set(CMAKE_C_STANDARD 99)

option(BUILD_TEST "Builds a test app" ON)

add_subdirectory(lib/libreq)

add_library(reddit SHARED test/main.c src/Reddit.c headers/Reddit.h test/SECRETS.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c src/Post.c headers/Post.h src/List.c headers/List.h src/Subreddit.c headers/Subreddit.h headers/defs.h src/Comment.c headers/Comment.h)

target_include_directories(reddit PRIVATE ${LIBREQ_HEADERS} headers lib/cJSON)
target_link_libraries(reddit PRIVATE request)

message("Headers: ${LIBREQ_HEADERS}")

if(BUILD_TEST)
    add_executable(redd test/main.c)
    target_link_libraries(redd PRIVATE reddit)
    target_include_directories(redd PRIVATE headers)
endif()
