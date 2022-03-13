cmake_minimum_required(VERSION 3.21)
project(libreddit C)

set(CMAKE_C_STANDARD 99)

option(BUILD_TEST "Builds a test app" ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

add_library(libreddit SHARED test/main.c src/Reddit.c headers/Reddit.h src/Net.c headers/Net.h test/SECRETS.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c src/Post.c headers/Post.h src/List.c headers/List.h)

target_include_directories(libreddit PRIVATE ${CURL_INCLUDE_DIRS} headers lib/cJSON)
target_link_libraries(libreddit PRIVATE ${CURL_LIBRARIES})

if(BUILD_TEST)
    add_executable(redd test/main.c)
    target_link_libraries(redd PRIVATE libreddit)
    target_include_directories(redd PRIVATE headers)
endif()
