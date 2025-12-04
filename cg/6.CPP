#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x <= x1)
    {
        putpixel(x, y, 7); // 7 = white color
        x++;
        if (p >= 0)
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            p = p + 2 * dy;
        }
        delay(1); // optional: see animation
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    int x0, y0, x1, y1;

    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI"); // Check your BGI path

    printf("Enter coordinates of first point: ");
    scanf("%d %d", &x0, &y0);

    printf("Enter coordinates of second point: ");
    scanf("%d %d", &x1, &y1);

    drawline(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
