#ifndef __UTILS__
#define __UTILS__

struct point {
    int x ;
    int y ;
};

struct line {
    double l ;
    int b ;
};


int max_2(int ,int );
int min_2(int ,int );
int min3(int ,int ,int );
int rand_int(int ,int );
void get_middle(struct point *,struct point );
void get_yintercept(struct line *y,struct point a) ;
void get_slope(struct line *y,struct point a,struct point b) ;

#endif
