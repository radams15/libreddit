ARCH ?= -arch ppc
TARGET ?= -mmacosx-version-min=10.4 -isysroot /Developer/SDKs/MacOSX10.4u.sdk
CC=gcc

CJSON_SRC=lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c

B64_SRC=lib/librequest/lib/b64.c/buffer.c lib/librequest/lib/b64.c/decode.c lib/librequest/lib/b64.c/encode.c

REQ_SRC=lib/librequest/src/main/res.c lib/librequest/src/main/header.c lib/librequest/src/main/request_generic.c
REDDIT_SRC=src/Reddit.c src/Post.c src/List.c src/Subreddit.c src/Comment.c

INCLUDES=-Ilib/librequest/include -Iinclude -Ilib/cJSON -Ilib/librequest/lib/b64.c/

libreddit.dylib:
	${CC} -fPIC -dynamiclib ${ARCH} ${TARGET} -o libreddit.dylib ${INCLUDES} ${CJSON_SRC} ${B64_SRC} ${REQ_SRC} lib/librequest/src/main/backends/darwin/request.m ${REDDIT_SRC} -framework Foundation
 
libreddit.so:
	${CC} -fPIC -shared -o libreddit.so ${INCLUDES} ${CJSON_SRC} ${B64_SRC} ${REQ_SRC} lib/librequest/src/main/backends/curl/request.c ${REDDIT_SRC} `pkg-config --libs --cflags libcurl`
	
clean:
	rm -rf *.dylib *.so
