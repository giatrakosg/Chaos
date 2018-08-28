# Triangle Game
 The game this program simulates works as follows.
 Given three points 
 
 1.Choose a point within the triangle they form.
 
 2.Choose a number from 1 to 3 .
 
 3.Move half the distance from the starting point to the random point of the triangle
 
 4.Set starting point to new point
 
 5.Continue
 
 ## Compilation

Run the following command on terminal while on the ChaosTriangle directory(LINUX ONLY)

    $make

 ## Programm
 
 The programm without given command line arguments initializes the triangle in the center of the screen with 
an OFFSET of 200 pixels.
You can choose to randomly select the starting points by running the following command in terminal:

    $./Chaos_triangle -s SEED

where SEED : is the seed the random function will use 

 ## Observations
 
 After running the game for 30,000 iterations the [sierpinski triangle](https://en.wikipedia.org/wiki/Sierpinski_triangle) is created in the default triangle.
 As well  as for random starting triangles
 
