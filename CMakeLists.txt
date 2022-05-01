cmake_minimum_required(VERSION 2.8)
project(reddit C)

set(CMAKE_C_STANDARD 99)

option(BUILD_TEST "Builds a test app" OFF)
option(ENABLE_THREADING "Enables threading methods using pthread" ON)

add_subdirectory(lib/librequest)

add_library(reddit SHARED src/Reddit.c include/Reddit.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c src/Post.c include/Post.h src/List.c include/List.h src/Subreddit.c include/Subreddit.h src/Comment.c include/Comment.h)

target_include_directories(reddit PRIVATE ${LIBREQ_HEADERS} include lib/cJSON)
target_link_libraries(reddit PRIVATE request)

message("Headers: ${LIBREQ_HEADERS}")

if(ENABLE_THREADING)
    target_compile_definitions(reddit PRIVATE ENABLE_THREADING)
endif()

if(BUILD_TEST)
    add_executable(redd test/main.c include/API.h)
    target_link_libraries(redd PRIVATE reddit)
    target_include_directories(redd PRIVATE include)
endif()
