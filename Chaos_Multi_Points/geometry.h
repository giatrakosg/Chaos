#ifndef __GEO__
#define __GEO__

struct point {
    int x ;
    int y ;
};

struct line {
    double l ;
    int b ;
};
void get_middle(struct point *,struct point );
void get_yintercept(struct line *,struct point ) ;
void get_slope(struct line *,struct point ,struct point ) ;
void get_trace_triangle(struct point *,struct point ,struct point ,struct point );
void init_point(struct point *,int ,int );
void init_r_triangle(struct point *,struct point *,struct point *);
void init_shape(struct point *,int ,struct point ,struct point *,int );
int rules(struct point *,struct point *,int ,int ,int );

#endif
