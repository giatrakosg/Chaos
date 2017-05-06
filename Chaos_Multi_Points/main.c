#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include "utils.h"
#include "geometry.h"

#define MAX_LOOPS 30000
#define SIM_TIME 15 /* Time in seconds that the simulation will appear on screen */
#define OFFSET 100

int main(int argc ,char *argv[]) {

    srand(time(NULL));
    int points ,select = 0,elap_time;
    printf("Give number of points \n" );
    scanf("%d",&points );
    printf("Choose mode (0 or 1)\n");
    scanf("%d",&select );
    printf("Choose time (in seconds) that programm lasts \n" );
    scanf("%d",&elap_time);

    if (points < 3) {
        printf("Sorry there must be at least 2 points \n" );
        return 1 ;
    }
    const int TIME_PER_LOOP = (elap_time * 10000000) / (MAX_LOOPS / 100) ;
    struct timespec req;
    req.tv_nsec = TIME_PER_LOOP ;
    req.tv_sec = 0 ;

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");
    setbkcolor(15);
    struct point mat[points];
    int i ,prev = 0;
    struct point center ;
    struct point trace ;

    center.x = getmaxx() / 2 ;
    center.y = getmaxy() / 2 ;

    init_shape(mat,points,center,&trace,OFFSET);
    putpixel(trace.x,trace.y,BLUE);
    print_shape(mat,points);
    outtext("OK..\n");
    getchar();
    for (i = 0; i < MAX_LOOPS; i++) {
        prev = rules(mat,&trace,points,select,prev);
        assert(!(prev && !select));
        putpixel(trace.x,trace.y,RED);
        nanosleep(&req,NULL);
    }

    outtext("Finished");
    getchar();

    closegraph();

    return 0;
}
