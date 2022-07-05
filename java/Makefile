CJSON_SRC=../lib/cJSON/cJSON.c ../lib/cJSON/cJSON_Utils.c

B64_SRC=../lib/librequest/lib/b64.c/buffer.c ../lib/librequest/lib/b64.c/decode.c ../lib/librequest/lib/b64.c/encode.c

REQ_SRC=../lib/librequest/src/main/res.c ../lib/librequest/src/main/header.c ../lib/librequest/src/main/request_generic.c
REDDIT_SRC=../src/Reddit.cpp ../src/Post.cpp ../src/Subreddit.cpp ../src/Comment.cpp

INCLUDES=-I../lib/librequest/include -I../include -I../lib/cJSON -I../lib/librequest/lib/b64.c/

linux: libreddit.so
darwin: libreddit.dylib
mac: libreddit.dylib

swig:
	swig -c++ -java Reddit.i

libreddit.so: swig
	gcc -fPIC -shared -o libreddit.so ${INCLUDES} ${CJSON_SRC} ${B64_SRC} ${REQ_SRC} ../lib/librequest/src/main/backends/curl/request.c ${REDDIT_SRC} `pkg-config --libs --cflags libcurl` -lstdc++

libreddit.dylib: swig
	gcc -fPIC -dynamiclib -o libreddit.dylib ${INCLUDES} ${CJSON_SRC} ${B64_SRC} ${REQ_SRC} ../lib/librequest/src/main/backends/darwin/request.m ${REDDIT_SRC} -framework Foundation -lstdc++