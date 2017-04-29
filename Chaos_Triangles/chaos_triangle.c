#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include "utils.h"
#define MAX_LOOPS 30000
#define OFFSET 200

struct point {
    int x ;
    int y ;
};

struct line {
    double l ;
    int b ;
};



void get_trace(struct point *t,struct point p1,struct point p2,struct point p3) {
    /* Returns value within triangle */
    struct line y12 ;
    struct line y13 ;
    struct line y23 ;

    

}
int get_rand_interval(int max) { /* creates random in [0 ,max) interval */
    /* Cut the space from 0 to 1 to max equal-parts and generate random number
       from 0 to 1 ,choose the number that it ends up in */
    double k = rand() / ((double) RAND_MAX) ,i ;
    for (i = 1.0; i <= max; i++) {
        if ((((double) i - 1) / max < k) && (k < ((double) (i )) / max)) {
            return ((int) i - 1) ;
        }
    }
}

int main(void) {
    srand(time(NULL));
    int gd = DETECT,gm;
    int x ,y ,k ;
    int i ;
    struct point p1 , p2 ,p3 ,trace;
    struct point center ;
    initgraph(&gd, &gm, "");
    center.x = getmaxy() / 2 ;
    center.y = getmaxy() / 2 ;

    struct point start ;
    p1.x = center.x ;
    p1.y = center.y + OFFSET ;

    p2.x = center.x - OFFSET ;
    p2.y = center.y - OFFSET ;

    p3.x = center.x + OFFSET ;
    p3.y = center.y - OFFSET ;

    /* Print triangle */
//    putpixel(center.x,center.y,GREEN);
    putpixel(p1.x,p1.y,RED);
    putpixel(p2.x,p2.y,RED);
    putpixel(p3.x,p3.y,RED);

    get_trace(&start,p1,p2,p3);
    putpixel(start.x,start.y,GREEN);
    line(p1.x,p1.y,start.x,start.y);
    sleep(3);
    //line(p1.x,p1.y,p2.x,p2.y);
    //line(p1.x,p1.y,p3.x,p3.y);
    //line(p2.x,p2.y,p3.x,p3.y);


    for (i = 0; i < MAX_LOOPS; i++) {
        k = get_rand_interval(3) ;
        if (k == 0) {
            get_middle(&start,p1);
        }
        if (k == 1) {
            get_middle(&start,p2);
        }
        if (k == 2) {
            get_middle(&start,p3);
        }
        putpixel(start.x,start.y,BLUE);
        //sleep(1);
    }

    getchar();
    closegraph();

    return 0;
}
