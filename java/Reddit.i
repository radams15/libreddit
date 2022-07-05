%module libreddit

%{
#include "../include/Reddit.h"
#include "../include/Post.h"
#include "../include/Subreddit.h"
#include "../include/Comment.h"
%}

%include "std_vector.i"
%include "std_string.i"

%template(PostVector) std::vector<Post*>;
%template(SubredditVector) std::vector<Subreddit*>;

%include "../include/Reddit.h"
%include "../include/Post.h"
%include "../include/Subreddit.h"
%include "../include/Comment.h"