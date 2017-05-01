#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include "utils.h"
#include <time.h>

#define MAX_LOOPS 30000
#define OFFSET 200
#define SIM_TIME 15 /* Time in seconds that the simulation will appear on screen */

int main(int argc ,char *argv[]) {

    int i ,k ;

    struct point p1 , p2 ,p3 ;
    struct point center ;

    const int TIME_PER_LOOP = (SIM_TIME * 10000000) / (MAX_LOOPS / 100) ;
    struct timespec req;
    req.tv_nsec = TIME_PER_LOOP ;
    req.tv_sec = 0 ;

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");
    center.x = getmaxx() / 2 ;
    center.y = getmaxy() / 2 ;

    if (argc > 2) {
        srand(atoi(argv[2]));
        init_point(&p1,getmaxx(),getmaxy());
        init_point(&p2,getmaxx(),getmaxy());
        init_point(&p3,getmaxx(),getmaxy());
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
        nanosleep(&req,NULL);
    }

    getchar();
    closegraph();

    return 0;
}
