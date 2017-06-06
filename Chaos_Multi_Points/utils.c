#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "utils.h"

#define OFFSET 100

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
int rand_int(int min,int max) {
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
void init_point(struct point *a,int xmax,int ymax) { /* Initialize point */
    a->x = rand_int(1,xmax);
    a->y = rand_int(1,ymax);
}
void init_r_triangle(struct point *p1,struct point *p2,struct point *p3) { /* Initialize random triangle */
    struct line y ;

    init_point(p1,getmaxx(),getmaxy());
    init_point(p2,getmaxx(),getmaxy());
    init_point(p3,getmaxx(),getmaxy());

    get_parameters(&y,*p1,*p2);

    if( (y.A * p3->y) + (y.B * p3->x) + y.C == 0) {
        init_r_triangle(p1,p2,p3);
    }
}
void print_shape(struct point *mat,int size) {
    int i ;
    for (i = 0; i <size; i++) {
        putpixel(mat[i].x,mat[i].y,RED);
    }
}
void fy_shuff(struct point *a,int length) {
    int i ,k ;
    for (i = 0; i < length - 1; i++) {
        k = rand_int(0,length - 1 - i);
        swap_points(&a[i],&a[k + i]);
    }
}
void swap_points(struct point *a,struct point *b) {
    struct point tmp ;
    tmp = *a ;
    *a = *b ;
    *b = tmp ;
}
int min_4(int a,int b,int c,int d) {
    int mat[4] = {a , b ,c ,d} ;
    int i ;
    int min = mat[0] ;
    for ( i = 1; i < 4; i++) {
        if (mat[i] < min) {
            min = mat[i] ;
        }
    }
    return min ;
}
int max_4(int a ,int b,int c,int d ) {
    int mat[4] = {a , b ,c ,d} ;
    int i ;
    int max = mat[0] ;
    for ( i = 1; i < 4; i++) {
        if (mat[i] < max) {
            max = mat[i] ;
        }
    }
    return max ;

}
/*void init_shape_v2(int points) {
    struct line lines[points] ;
    int i ;
    for(i = 0 ;i < points ;i++) {
        lines[i].l = tan((360.0 / points) * (i + 1));
        lines[i].b = center.y - lines.l * center.x ;
        mat[i] = solve_line_circle(lines[i],center,radius)
    }


}*/
