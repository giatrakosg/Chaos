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
void get_middle(struct point *,struct point );
void get_yintercept(struct line *,struct point ) ;
void get_slope(struct line *,struct point ,struct point ) ;
void get_trace(struct point *,struct point ,struct point ,struct point );
void init_point(struct point *,int ,int );
void init_r_triangle(struct point *,struct point *,struct point *);
void print_shape(struct point *,int ) ;
int max_4(int ,int ,int ,int );
int min_4(int ,int ,int ,int );
void init_shape(struct point *,int ,struct point ,struct point *,int );

#endif
