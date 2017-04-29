#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main(void) {
    int gd = DETECT, gm;
    /* initialization of graphic mode */
    initgraph(&gd, &gm, "");
    line(100,100,200, 200);
    getch();
    closegraph();
    return 0;
}
