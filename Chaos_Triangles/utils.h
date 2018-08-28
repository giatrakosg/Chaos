#ifndef __UTILS__
#define __UTILS__

struct point {
    int x ;
    int y ;
};

struct line {
    int l ;
    int b ;
};


int max_2(int ,int );
int min_2(int ,int );
int min3(int ,int ,int );
int rand_int(int ,int );

// geometry functions

//
struct point get_middle(struct point ,struct point );
void get_yintercept(struct line *,struct point ) ;
void get_slope(struct line *,struct point ,struct point ) ;
void get_trace(struct point *,struct point ,struct point ,struct point );
void init_point(struct point *,int ,int );
void init_r_triangle(struct point *,struct point *,struct point *);

#endif
