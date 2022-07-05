%module libreddit

%{
#include "../include/Reddit.h"
#include "../include/Post.h"
#include "../include/Subreddit.h"
#include "../include/Comment.h"
%}

%include "std_vector.i"

%include "../include/Reddit.h"
%include "../include/Post.h"
%include "../include/Subreddit.h"
%include "../include/Comment.h"