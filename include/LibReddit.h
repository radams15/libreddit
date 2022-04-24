








typedef void(* freer_cb)(void*);

typedef struct List{
    void** data;
    unsigned long length;
    freer_cb freer;



} List_t;

List_t* list_new(unsigned long elem_size, freer_cb freer);

void list_append(List_t *lst, void* data);

void list_free(List_t* lst);



typedef struct Post{
    const char* title;
    const char* author;
    const char* subreddit;
    const char* text;
    const char* thumbnail;
    unsigned long upvotes;
    unsigned long downvotes;
    unsigned long score;
    const char* id;



} Post_t;

typedef void (*post_cb)(Post_t*, void*);

const char* post_fullname(Post_t* post);
const char* post_url(Post_t* post);



typedef struct Subreddit {
    const char* name;
    unsigned long subs;



} Subreddit_t;

Subreddit_t* subreddit_new(const char* name);

void subreddit_free(Subreddit_t* subreddit);









typedef struct Comment {
    const char* title;
    const char* author;
    const char* body;
    unsigned long score;
    const char* id;
    const char* thumbnail;
    const char* url;
    struct Comment** children;
    unsigned long no_children;
} Comment_t;

typedef void (*comment_cb)(Comment_t*, void*, int);

void comment_free(Comment_t* comment);


typedef struct Reddit{
    const char* username;
    int authenticated;

} Reddit_t;

Reddit_t* reddit_new(const char* username, const char* password, const char* client_id, const char* secret);
Reddit_t* reddit_new_with_token(const char *username, const char* token);

int reddit_get_posts_hot(Reddit_t* reddit, unsigned long limit, const char* after, post_cb callback, void* ptr);

List_t* reddit_get_subbed_list(Reddit_t* reddit);

int reddit_get_login_status(Reddit_t* reddit);

int subreddit_get_posts(Reddit_t* reddit, Subreddit_t* subreddit, const char* type, unsigned long limit, const char* after, post_cb callback, void* ptr);

int post_get_comments(Reddit_t* reddit, Post_t* post, unsigned long limit, const char* after, comment_cb callback, void* ptr);
