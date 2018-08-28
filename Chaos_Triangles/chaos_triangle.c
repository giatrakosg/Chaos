#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include <time.h>

#include "utils.h"

#define MAX_LOOPS 30000
#define OFFSET 200
#define SIM_TIME 10 /* Time in seconds that the simulation will appear on screen */

int main(int argc ,char *argv[]) {
    printf("\n \
    Choose Color :     \n  \
    BLACK           0  \n  \
    BLUE            1  \n  \
    GREEN           2  \n  \
    CYAN            3  \n  \
    RED             4  \n  \
    MAGENTA         5  \n  \
    BROWN           6  \n  \
    LIGHTGRAY       7  \n  \
    DARKGRAY        8  \n  \
    LIGHTBLUE       9  \n  \
    LIGHTGREEN      10 \n  \
    LIGHTCYAN       11 \n  \
    LIGHTRED        12 \n  \
    LIGHTMAGENTA    13 \n  \
    YELLOW          14 \n  \
    WHITE           15 \n  \
    RANDOM          16 \n  \
    ");
    int option ;
    scanf("%d",&option);


    struct point p1 , p2 ,p3 ;
    struct point center ;

    const int TIME_PER_LOOP = (SIM_TIME * 10000000) / (MAX_LOOPS / 100) ;
    struct timespec req;
    req.tv_nsec = TIME_PER_LOOP ;
    req.tv_sec = 0 ;

    // initialization functions used by the library
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");

    // find the center of the screen 
    center.x = getmaxx() / 2 ;
    center.y = getmaxy() / 2 ;

    // if -s option use the given seed and select randomly the triangle
    if (argc > 2) {
        srand(atoi(argv[2]));
        init_r_triangle(&p1,&p2,&p3);
    }
    // create the default triangle
    /* &---------&
     *  \       /
     *   \     /
     *    \   /
     *     \ / 
     *      &
     */
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

    // calculate random starting point inside triangle
    get_trace(&start,p1,p2,p3);
    putpixel(start.x,start.y,GREEN);

    int color = option ;
    for (int i = 0; i < MAX_LOOPS; i++) {
        int k = rand_int(0,2) ;
        // choose a random edge , and move the starting point towards the middle of 
        // the two points
        if (k == 0) {
            start = get_middle(start,p1);
        }
        if (k == 1) {
            start = get_middle(start,p2);
        }
        if (k == 2) {
            start = get_middle(start,p3);
        }
        if (option == 16)
        {
           color = rand_int(0,15) ;
        }
        putpixel(start.x,start.y,color);
        // sleep time per loop 
        nanosleep(&req,NULL);
    }

    // wait for user to close the window by pressing any key
    getchar();
    closegraph();

    return 0;
}
