#include <graphics.h>
#include <conio.h>
#include <stdio.h>   // for printf

int main()   // use int main(), not void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  // check your folder path

    setbkcolor(GREEN);

    printf("\t\t\t\n\nLINE");
    line(50, 40, 190, 40);

    printf("\t\t\n\n\n\nRECTANGLE");
    rectangle(125, 115, 215, 165);

    printf("\t\t\t\n\n\n\n\n\n\nARC");
    arc(120, 200, 0, 180, 30);   // correct order: start_angle, end_angle, radius

    printf("\t\n\n\n\nCIRCLE");
    circle(120, 270, 30);

    printf("\t\n\n\n\nELLIPSE");
    ellipse(120, 350, 0, 360, 30, 20);

    getch();
    closegraph();
    return 0;
}
