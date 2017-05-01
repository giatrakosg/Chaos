#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include "utils.h"
#define MAX_LOOPS 30000
#define OFFSET 200


int main(int argc ,char *argv[]) {
    int gd = DETECT,gm;
    int i ,k ;
    struct point p1 , p2 ,p3 ;
    struct point center ;
    initgraph(&gd, &gm, "");
    center.x = getmaxy() / 2 ;
    center.y = getmaxy() / 2 ;
    if (argc > 2) {
        srand(atoi(argv[2]));
        p1.x = rand_int(1,getmaxy());
        p1.y = rand_int(1,getmaxy());

        p2.x = rand_int(1,getmaxy());
        p2.y = rand_int(1,getmaxy());

        p3.x = rand_int(1,getmaxy());
        p3.y = rand_int(1,getmaxy());

    }
    else {
        srand(time(NULL));

        p1.x = center.x ;
        p1.y = center.y + OFFSET ;

        p2.x = center.x - OFFSET ;
        p2.y = center.y - OFFSET ;

        p3.x = center.x + OFFSET ;
        p3.y = center.y - OFFSET ;

    }

    struct point start ;


    /* Print triangle */

    putpixel(p1.x,p1.y,RED);
    putpixel(p2.x,p2.y,RED);
    putpixel(p3.x,p3.y,RED);

    get_trace(&start,p1,p2,p3);
    putpixel(start.x,start.y,GREEN);

    //line(p1.x,p1.y,p2.x,p2.y);
    //line(p1.x,p1.y,p3.x,p3.y);
    //line(p2.x,p2.y,p3.x,p3.y);


    for (i = 0; i < MAX_LOOPS; i++) {
        k = rand_int(0,2) ;
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
