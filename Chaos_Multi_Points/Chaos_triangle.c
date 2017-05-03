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

    int points ;

    printf("Give number of points \n" );
    scanf("%d",&points );
    struct point mat[points];

    init_shape()

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");


    center.x = getmaxx() / 2 ;
    center.y = getmaxy() / 2 ;

    struct point start ;


    for (i = 0; i < MAX_LOOPS; i++) {

        nanosleep(&req,NULL);
    }

    getchar();
    closegraph();

    return 0;
}
