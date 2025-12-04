#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h> 
#include <dos.h>   

int main()
{
    int gd = DETECT, gm;
    float x, y, dx, dy, steps;
    int x0, y0, x1, y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(BLACK);   // better contrast
    cleardevice();       // clear screen

    printf("Enter starting coordinates (x0, y0): ");
    scanf("%d %d", &x0, &y0);

    printf("Enter ending coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    dx = dx / steps;
    dy = dy / steps;

    x = x0;
    y = y0;

    for (int i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), RED);
        x += dx;
        y += dy;
        delay(5);  // so you can see drawing animation
    }

    getch();
    closegraph();
    return 0;
}
