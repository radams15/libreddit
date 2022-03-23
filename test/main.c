#include <stdio.h>

#define PRIVATE

#include <Reddit.h>
#include <unistd.h>

#include "SECRETS.h"

char* last;

void post_got(Post_t* post, void* ptr){
    printf("Post '%s' by '%s' in 'r/%s' ====> %s\n", post->title, post->author, post->subreddit, post_fullname(post));

    last = (char*) post_fullname(post);
}

int main() {
    Reddit_t* reddit = reddit_new(USERNAME, PASSWD, CID, SECRET);

    if(reddit->authenticated == UNAUTHENTICATED){
        fprintf(stderr, "Failed to login!\n");
    }

	printf("Tok: %s\n", reddit->token);

    Subreddit_t* subreddit = subreddit_new("cpp");

    subreddit_get_posts(reddit, subreddit, "hot", 100, NULL, post_got, NULL);

    usleep(1000*500);

    printf("\n\n\n");

    subreddit_get_posts(reddit, subreddit, "hot", 100, last, post_got, NULL);

    return 0;
}
