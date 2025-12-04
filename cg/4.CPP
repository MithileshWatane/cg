#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include <dos.h>   // <-- for delay()


void main()
{
    int gd = DETECT, gm;
    // Initialize graphics mode. Adjust the path to the BGI directory if different
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 

    int x_max = getmaxx();
    int y_max = getmaxy();

    while(!kbhit()) // Loop until a key is pressed
    {
        // Generate random coordinates, radius, fill pattern, and color for the circle
        int x = random(x_max);
        int y = random(y_max);
        int r = random(50) + 10; // Radius between 10 and 59
        int fill_pattern = random(12); // Fill pattern from 0 to 11
        int color = random(getmaxcolor() + 1); // Color from 0 to max color value

        // Set drawing color, draw the circle, set fill style, and flood fill the circle
        setcolor(color);
        circle(x, y, r);
        setfillstyle(fill_pattern, color);
        floodfill(x, y, color);

        delay(100); // Pause for 100 milliseconds
    }

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode
}