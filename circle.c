#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main(void) {
   int gd = DETECT,gm;
   int x ,y ,radius=80;
   int i ;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;

   outtextxy(x-100, 50, "CIRCLE Using Graphics in C");
   /* Draw circle on screen */
   for ( i = 0; i < 10; i++) {
       circle(x, y, radius);
       x -= 10 ;
       y += 5 ;
       radius += 10 ;
       getch();

   }

   getch();
   closegraph();
   return 0;
}
