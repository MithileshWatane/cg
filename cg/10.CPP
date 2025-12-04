#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PI 3.14159

int main()
{
    int gd = DETECT, gm;
    float theta = 0, x0, y0, r = 80, rad1, rad2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;

    while (!kbhit())
    {
        // Fan boundary
        setcolor(WHITE);
        circle(x0, y0, r + 10);
        circle(x0, y0, r);

        // Convert to radians
        rad1 = theta * PI / 180;
        rad2 = (theta + 90) * PI / 180;

        // Draw blades
        setcolor(YELLOW);
        line(x0, y0, x0 + r * sin(rad1), y0 + r * cos(rad1));
        line(x0, y0, x0 + r * sin(rad2), y0 + r * cos(rad2));
        line(x0, y0, x0 - r * sin(rad1), y0 - r * cos(rad1));
        line(x0, y0, x0 - r * sin(rad2), y0 - r * cos(rad2));

        // Fan stand
        setcolor(LIGHTBLUE);
        line(x0, y0 + r + 10, x0, y0 + r + 80);
        rectangle(x0 - 30, y0 + r + 80, x0 + 30, y0 + r + 100);

        // Rotate
        theta -= 8;
        delay(70);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}

