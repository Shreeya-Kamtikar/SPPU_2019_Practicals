#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int gd, gm;
    int x, y;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    x = getmaxx();
    y = getmaxy();
    putpixel(x/2, y/2, RED);
    circle(300,100,50);
    line(225,50,375,50);
    line(225,50,300,25);
    line(375,50,300,25);
    circle(300,250,100);
    circle(280,95,5);
    circle(320,95,5);
    line(295,105,315,115);
    line(295,115,315,115);
    line(280,347,280,400);
    line(320,347,320,400);
    line(230,180,150,100);
    line(370,180,450,100);
    
    getch();
    closegraph();
}
	
