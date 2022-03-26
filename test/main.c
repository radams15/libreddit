#include <stdio.h>

#define PRIVATE

#include <Reddit.h>
#include <unistd.h>
#include <string.h>

#include "SECRETS.h"

void post_got(Post_t* post, void* ptr){
    printf("Post '%s' by '%s' in 'r/%s' ====> %s\n", post->title, post->author, post->subreddit, post_fullname(post));
}

void comment_recurse(Comment_t* comment, int level){
    printf("Comment by '%s' ====> '%s'\n\n--------------------------------------\n", comment->author, comment->body);

    for(int i=0 ; i<comment->no_children ; i++){
        Comment_t* child = comment->children[i];
        for(int x=0 ; x<level ; x++) {
            printf("\t");
        }
        comment_recurse(child, level+1);
    }
}

void comment_got(Comment_t* comment, void* ptr, int is_title){
    if(is_title){
        printf("Title Page: %s (%s) - thumbnail: %s\n\n", comment->title, comment->url, comment->thumbnail);
    }else {
        comment_recurse(comment, 1);
    }
}

int main() {
    Reddit_t* reddit = reddit_new(USERNAME, PASSWD, CID, SECRET);

    if(reddit->authenticated == UNAUTHENTICATED){
        fprintf(stderr, "Failed to login!\n");
    }

	printf("Tok: %s\n", reddit->token);

    /*Subreddit_t* subreddit = subreddit_new("gnome");

    subreddit_get_posts(reddit, subreddit, "hot", 100, NULL, post_got, NULL);*/

    Post_t post;
    post.id = strdup("t8o6cr");
    post.subreddit = strdup("gnome");

    post_get_comments(reddit, &post, -1, NULL, comment_got, NULL);

    return 0;
}
