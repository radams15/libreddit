//
// Created by Rhys on 23/03/2022.
//

#include <Comment.h>
#include <stdlib.h>

void comment_free(Comment_t *comment) {
    free(comment->title);
    free(comment->author);
    free(comment->id);
    free(comment->body);
    free(comment->thumbnail);
    free(comment->url);
}
