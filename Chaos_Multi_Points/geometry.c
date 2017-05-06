#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "utils.h"

void get_middle(struct point *t,struct point a) {
    t->x = (a.x + t->x) / 2 ;
    t->y = (a.y + t->y) / 2 ;

}
void get_slope(struct line *y,struct point a,struct point b) {
        y->l = ((a.y - b.y) / (a.x - b.x)) ;
}
void get_yintercept(struct line *y,struct point a) {
    y->b = a.y - (y->l * a.x) ;
}
void get_trace_triangle(struct point *t,struct point p1,struct point p2,struct point p3) {
    /* Returns value within triangle */
    struct line y12 ;
    struct line y13 ;
    struct line y23 ;

    get_slope(&y12,p1,p2);
    get_slope(&y13,p1,p3);
    get_slope(&y23,p2,p3);

    get_yintercept(&y12,p1);
    get_yintercept(&y13,p3);
    get_yintercept(&y23,p2);

    /* Choose a random point in y12 and a random point in y23 */
    /* Create line between them */
    /* Choose random x between the 2 points */
    /* Calculate y of x in the line above */
    /* Return the values */

    struct point r1 ;
    struct point r2 ;

    r1.x = rand_int(min_2(p1.x,p2.x),max_2(p1.x,p2.x));
    r1.y = (y12.l * r1.x) + y12.b ;

    r2.x = rand_int(min_2(p2.x,p3.x),max_2(p2.x,p3.x));
    r2.y = (y23.l * r2.x) + y23.b ;


    struct line yr ;
    get_slope(&yr,r1,r2);
    get_yintercept(&yr,r1);

    t->x = rand_int(min_2(r1.x,r2.x),max_2(r1.x,r2.x));
    t->y = (yr.l * t->x) + yr.b ;

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
        a[0].x = center.x - offset ;
        a[0].y = center.y - offset ;

        a[1].x = center.x + offset ;
        a[1].y = center.y - offset ;

        a[2].x = center.x - offset;
        a[2].y = center.y + offset ;

        a[3].x = center.x + offset;
        a[3].y = center.y + offset ;
        trace->x = rand_int(min_4(a[0].x,a[1].x,a[2].x,a[3].x),max_4(a[0].x,a[1].x,a[2].x,a[3].x));
        trace->y = rand_int(min_4(a[0].y,a[1].y,a[2].y,a[3].y),max_4(a[0].y,a[1].y,a[2].y,a[3].y));
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
int rules(struct point *mat,struct point *trace,int size,int mode,int prev) {
    /* Mode 0 is default move towards middle */
    /* Mode 1 is can't go to previous direction */
    int k ;
    if (mode == 0) {
        k = rand_int(0,size - 1);
        get_middle(trace,mat[k]);
        return 0 ;
    }
    if (mode == 1) {
        k = rand_int(0,size - 1);
        while(k == prev) {
            k = rand_int(0,size - 1);
        }
        prev = k ;
        get_middle(trace,mat[k]);
        return prev ;
    }
    return 1 ;
}
