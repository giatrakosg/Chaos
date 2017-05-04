#include "utils.h"
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int max_2(int a ,int b ) {
    if (a > b) {
        return a ;
    }
    return b ;
}
int min_2(int a ,int b ) {
    if (a < b) {
        return a ;
    }
    return b ;
}
int min3(int a,int b,int c) {
    if (a < b) {
        if (a < c) {
            return a ;
        }
        if (a > c) {
            return c ;
        }
    }
    else
        if (b > c) {
            return c ;
        }
        else
            return b ;
}
int rand_int(int min,int max)
{
    int r;
    const int range = 1 + max - min;
    const int buckets = RAND_MAX / range;
    const int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}
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
void get_trace(struct point *t,struct point p1,struct point p2,struct point p3) {
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
void init_point(struct point *a,int xmax,int ymax) { /* Initialize point */
    a->x = rand_int(1,xmax);
    a->y = rand_int(1,ymax);
}
void init_r_triangle(struct point *p1,struct point *p2,struct point *p3) { /* Initialize random triangle */
    struct line y ;

    init_point(p1,getmaxx(),getmaxy());
    init_point(p2,getmaxx(),getmaxy());
    init_point(p3,getmaxx(),getmaxy());

    get_slope(&y,*p1,*p2);
    get_yintercept(&y,*p1);

    if( (y.l * p3->x + y.b) == p3->y) {
        init_r_triangle(p1,p2,p3);
    }
}
/*void init_shape(struct point *mat,int size,int xmax,int ymax) {
    int i ;
    for ( i = 0; i < size; i++) {
        init_point(&mat[i],xmax,ymax);
    }
}*/
void print_shape(struct point *mat,int size) {
    int i ;
    for (i = 0; i <size; i++) {
        putpixel(mat[i].x,mat[i].y,RED);
    }
}
void init_shape(struct point *a,int size,struct point center,int OFFSET){
    if(size == 3) {
        a[0].x = center.x - OFFSET ;
        a[0].y = center.y - OFFSET ;

        a[1].x = center.x + OFFSET ;
        a[1].y = center.y - OFFSET ;

        a[2].x = center.x ;
        a[2].y = center.y + OFFSET ;
    }
    else if(size == 4) {
        a[0].x = center.x - OFFSET ;
        a[0].y = center.y - OFFSET ;

        a[1].x = center.x + OFFSET ;
        a[1].y = center.y - OFFSET ;

        a[2].x = center.x - OFFSET;
        a[2].y = center.y + OFFSET ;

        a[3].x = center.x + OFFSET;
        a[3].y = center.y + OFFSET ;
    }
    else if(size == 5) {
        a[0].x = center.x - OFFSET ;
        a[0].y = center.y - OFFSET ;

        a[1].x = center.x + OFFSET ;
        a[1].y = center.y - OFFSET ;

        a[2].x = center.x - OFFSET;
        a[2].y = center.y + OFFSET ;

        a[3].x = center.x + OFFSET;
        a[3].y = center.y + OFFSET ;

        a[4].x = center.x ;
        a[4].y = center.y ;
    }

}
