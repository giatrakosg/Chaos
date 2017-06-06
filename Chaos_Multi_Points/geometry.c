#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "utils.h"
void get_r(struct point *t,struct point a,float r) {
    t->x = min_2(t->x,a.x) + (r * (max_2(t->x,a.x) - min_2(t->x,a.x)));
    t->y = min_2(t->y,a.y) + (r * (max_2(t->y,a.y) - min_2(t->y,a.y)));

}
void get_middle(struct point *t,struct point a) {
    t->x = (a.x + t->x) / 2 ;
    t->y = (a.y + t->y) / 2 ;

}
void get_parameters(struct line *y,struct point a,struct point b) {
    if(a.x == b.x) {
        y->B = 1 ;
        y->A = 0 ;
        y->C = -a.x ;
    }
    else {
        y->A = 1 ;
        y->B = -(((double) a.y - b.y) / (a.x - b.x));
        y->C = -a.y - (y->B * a.x) ;
    }

}

void get_trace_triangle(struct point *t,struct point p1,struct point p2,struct point p3) {
    /* Returns value within triangle */
    struct line y12 ;
    struct line y13 ;
    struct line y23 ;

    get_parameters(&y12,p1,p2);
    get_parameters(&y13,p1,p3);
    get_parameters(&y23,p2,p3);

    /* Choose a random point in y12 and a random point in y23 */
    /* Create line between them */
    /* Choose random x between the 2 points */
    /* Calculate y of x in the line above */
    /* Return the values */

    struct point r1 ; /* part of y12 */
    if(y12.A == 0) {
        r1.x = -(y12.C);
        r1.y = rand_int(min_2(p1.y,p2.y),max_2(p1.y,p2.y));
    }
    else {
        r1.x = rand_int(min_2(p1.x,p2.x),max_2(p1.x,p2.x));
        r1.y = -y12.C - (y12.B * r1.x) ;
    }
    struct point r2 ; /* part of y23 */
    if(y23.A == 0) {
        r2.x = -(y23.C);
        r2.y = rand_int(min_2(p3.y,p2.y),max_2(p3.y,p2.y));
    }
    else {
        r2.x = rand_int(min_2(p3.x,p2.x),max_2(p3.x,p2.x));
        r2.y = -y23.C - (y23.B * r2.x);
    }
     struct line yr ;
     get_parameters(&yr,r1,r2);

    if(yr.A == 0) {
        t->x = -(yr.C);
        t->y = rand_int(min_2(r1.y,r2.y),max_2(r1.y,r1.y));
    }
    else {
        t->x = rand_int(min_2(r1.x,r2.x),max_2(r1.x,r2.x));
        t->y = -yr.C - (yr.B * t->x);
    }

}
void init_shape(struct point *a,int size,struct point center,struct point *trace,int offset){
    if(size == 3) {
        a[0].x = center.x - offset ;
        a[0].y = center.y - offset ;

        a[1].x = center.x + offset ;
        a[1].y = center.y - offset ;

        a[2].x = center.x ;
        a[2].y = center.y + offset ;
        get_trace_triangle(trace,a[0],a[1],a[2]);
    }
    else if(size == 4) {
        a[0].x = center.x ;
        a[0].y = center.y - offset ;

        a[1].x = center.x - offset ;
        a[1].y = center.y ;

        a[2].x = center.x ;
        a[2].y = center.y + offset ;

        a[3].x = center.x + offset ;
        a[3].y = center.y ;

        fy_shuff(a,4);
        get_trace_triangle(trace,a[0],a[1],a[2]);
    }
    else if(size == 5) {
        a[0].x = center.x - offset ;
        a[0].y = center.y - offset ;

        a[1].x = center.x + offset ;
        a[1].y = center.y - offset ;

        a[2].x = center.x - offset - 10 ;
        a[2].y = center.y + offset ;

        a[3].x = center.x + offset;
        a[3].y = center.y + offset ;

        a[4].x = center.x ;
        a[4].y = center.y - (2 * offset) ;

        /* To get trace for the pentagon choose 3 points randomly and get trace of their triangle */
        /* Fisher yates shuffle points */
        /* Get first 3 */
        fy_shuff(a,5);
        get_trace_triangle(trace,a[0],a[1],a[2]);
    }

}
int rules(struct point *mat,struct point *trace,int size,int mode,int prev,float r) {
    /* Mode 0 is default move towards middle */
    /* Mode 1 is can't go to previous direction */
    int k ;
    if (mode == 0) {
        k = rand_int(0,size - 1);
        get_r(trace,mat[k],r);
        return 0 ;
    }
    if (mode == 1) {
        k = rand_int(0,size - 1);
        while(k == prev) {
            k = rand_int(0,size - 1);
        }
        prev = k ;
        get_r(trace,mat[k],r);
        return prev ;
    }
    return 1 ;
}
