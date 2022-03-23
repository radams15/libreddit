//
// Created by Rhys on 23/03/2022.
//

#include <Comment.h>
#include <stdlib.h>

void comment_free(Comment_t *comment) {
    free(comment->author);
    free(comment->id);
    free(comment->body);
}
