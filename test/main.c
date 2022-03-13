#include <stdio.h>

#include <Reddit.h>

#include "SECRETS.h"

void post_got(Post_t* post, void* ptr){
    printf("Post '%s' by '%s' in 'r/%s' ====> %s\n", post->title, post->author, post->subreddit, post_url(post));
}

int main() {
    Reddit_t* reddit = reddit_new_with_token(USERNAME, "68425471-goisRMj2Ot2xqjJXp1PLS8dl2kWIPw");

    reddit_get_hot(reddit, 100, NULL, post_got, NULL);

    return 0;
}
