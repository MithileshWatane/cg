#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>


class BresenhamCircle
{
    int a, b, r;  // center (a,b) and radius r

public:
    void getInput();
    void drawCircle();
};

void BresenhamCircle::getInput()
{
    printf("ENTER CENTER AND RADIUS\n");
    printf("Enter center (a b): ");
    scanf("%d %d", &a, &b);
    printf("Enter radius r: ");
    scanf("%d", &r);
}

void BresenhamCircle::drawCircle()
{
    int gd = DETECT, gm;
    int x = 0, y = r;
    int p = 1 - r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  // Change path as per your installation

    // Draw the initial points
    putpixel(a + x, b + y, RED);
    putpixel(a + x, b - y, RED);
    putpixel(a - x, b + y, RED);
    putpixel(a - x, b - y, RED);
    putpixel(a + y, b + x, RED);
    putpixel(a + y, b - x, RED);
    putpixel(a - y, b + x, RED);
    putpixel(a - y, b - x, RED);

    while (x < y)
    {
        x++;
        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }

        // Draw all eight octants
        putpixel(a + x, b + y, RED);
        putpixel(a + x, b - y, RED);
        putpixel(a - x, b + y, RED);
        putpixel(a - x, b - y, RED);
        putpixel(a + y, b + x, RED);
        putpixel(a + y, b - x, RED);
        putpixel(a - y, b + x, RED);
        putpixel(a - y, b - x, RED);

        delay(10);  // optional: see the circle being drawn
    }

    getch();
    closegraph();
}

int main()
{
    BresenhamCircle c;
    c.getInput();
    c.drawCircle();
    return 0;
}
