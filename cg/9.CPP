#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int x1 = 100, y1 = 200;
    int x2 = 150, y2 = 100;
    int x3 = 200, y3 = 200;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  // check path

    // Draw X and Y axes
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy()); // Y-axis
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2); // X-axis

    printf("Before Reflection (Triangle in 2nd Quadrant)");

    // Draw original triangle in YELLOW
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();

    printf("\nAfter Reflection about X-axis");

    // Reflection about X-axis → (x, y) → (x, -y)
    setcolor(RED);
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    line(x2, getmaxy() - y2, x3, getmaxy() - y3);
    line(x3, getmaxy() - y3, x1, getmaxy() - y1);

    getch();
    closegraph();
    return 0;
}
