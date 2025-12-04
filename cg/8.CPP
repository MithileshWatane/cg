
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int x, y, x1, y1, x2, y2;
    int scl_fctr_x, scl_fctr_y;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Change path according to your installation

    printf("\t\t\t******Scaling*******\n");

    printf("\nEnter first coordinate of Triangle (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter second coordinate of Triangle (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter third coordinate of Triangle (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw original triangle in WHITE
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);

    printf("\nEnter scaling factor (sx sy): ");
    scanf("%d %d", &scl_fctr_x, &scl_fctr_y);

    // Apply scaling
    x = x * scl_fctr_x;
    y = y * scl_fctr_y;

    x1 = x1 * scl_fctr_x;
    y1 = y1 * scl_fctr_y;

    x2 = x2 * scl_fctr_x;
    y2 = y2 * scl_fctr_y;

    // Draw scaled triangle in RED
    setcolor(RED);
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);

    getch();
    closegraph();

    return 0;
}
