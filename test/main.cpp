#include <stdio.h>

#define PRIVATE

#include <Reddit.h>
#include <unistd.h>
#include <string.h>

#include "SECRETS.h"

void post_got(Post* post, void* ptr){
    printf("Post '%s' by '%s' in 'r/%s'\n", post->title.c_str(), post->author.c_str(), post->subreddit);
    if(post_is_img(post)){
        printf("\tImage: %s\n", post->url.c_str());
    }
}

void comment_recurse(Comment* comment, int level){
    printf("Comment by '%s' ====> '%s'\n\n--------------------------------------\n", comment->author.c_str(), comment->body.c_str());

    for(int i=0 ; i<comment->no_children ; i++){
        Comment* child = (Comment*) comment->children[i];
        for(int x=0 ; x<level ; x++) {
            printf("\t");
        }
        comment_recurse(child, level+1);
    }
}

void comment_got(Comment* comment, void* ptr, int is_title){
    if(is_title){
        printf("Title Page: %s (%s) - thumbnail: %s\n\n", comment->title.c_str(), comment->url.c_str(), comment->thumbnail.c_str());
    }else {
        comment_recurse(comment, 1);
    }
}

int main() {
    Reddit reddit(USERNAME, PASSWD, CID, SECRET);

    if(reddit.authenticated == UNAUTHENTICATED){
        fprintf(stderr, "Failed to login!\n");
    }

    reddit.get_posts_hot(100, "", post_got, NULL);

    /*Post_t post;
    post.id = strdup("t8o6cr");
    post.subreddit = strdup("gnome");

    post_get_comments(reddit, &post, -1, NULL, comment_got, NULL);*/

    return 0;
}
