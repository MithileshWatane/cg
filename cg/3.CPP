#include <graphics.h>
#include <conio.h>
#include <dos.h>   // <-- for delay()


void main()
{
    int gd = DETECT, gm;
    int x, y, i;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");   // Path to BGI folder

    x = getmaxx() / 2;   // center of screen (X coordinate)
    y = getmaxy() / 2;   // center of screen (Y coordinate)

    setbkcolor(WHITE);   // background color

    for (i = 1; i <= 8; i++)
    {
        setcolor(i);                // change outline color
        setfillstyle(i, i);         // different fill styles & colors
        circle(x, y, i * 20);       // draw circle
        floodfill(x, y, i);         // fill circle with color
        delay(200);                 // small delay for animation
    }

    getch();
    closegraph();
}


