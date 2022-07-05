cmake_minimum_required(VERSION 2.8)
project(reddit C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)

option(BUILD_TEST "Builds a test app" ON)
option(ENABLE_THREADING "Enables threading methods using pthread" ON)

add_subdirectory(lib/librequest)

add_library(reddit SHARED src/Reddit.cpp include/Reddit.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c src/Post.cpp include/Post.h src/Subreddit.cpp include/Subreddit.h src/Comment.cpp include/Comment.h)

target_link_libraries(reddit PRIVATE request)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_compile_definitions(reddit PUBLIC NO_EXPORT)

message("Headers: ${LIBREQ_HEADERS}")

if(ENABLE_THREADING)
    target_compile_definitions(reddit PRIVATE ENABLE_THREADING)
endif()

if(BUILD_TEST)
    add_executable(redd test/main.cpp)
    target_link_libraries(redd PRIVATE reddit)
    target_include_directories(redd PRIVATE include)
endif()

include_directories(${LIBREQ_HEADERS} include lib/cJSON lib/librequest/include lib/)