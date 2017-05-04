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

    struct point center ;
    struct point trace ;
/*    const int TIME_PER_LOOP = (SIM_TIME * 10000000) / (MAX_LOOPS / 100) ;
    struct timespec req;
    req.tv_nsec = TIME_PER_LOOP ;
    req.tv_sec = 0 ;
*/
    int points ;

    printf("Give number of points \n" );
    scanf("%d",&points );

    struct point mat[points];
    int k ,i ;

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");

    center.x = getmaxx() / 2 ;
    center.y = getmaxy() / 2 ;

    init_shape(mat,points,center,OFFSET);
    print_shape(mat,points);

    for (i = 0; i < MAX_LOOPS; i++) {
        k = rand_int(0,points - 1);
        get_middle(&trace,mat[k]);
        putpixel(trace.x,trace.y,BLUE);
    }

    getchar();
    closegraph();

    return 0;
}
