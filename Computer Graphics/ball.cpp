#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;

int main()
{
	int gd,gm;
	gd = DETECT;
	initgraph(&gd,&gm,NULL);
	int i,y;
	for(i=0;i<450;i+=5)
	{
		y = 50 * sin(i * 3.141/180);
		setcolor(WHITE);
		circle(100+i,240+y,20);
		line(0,310,2000,310);
		//floodfill(100+i,240+y,BLUE);
		delay(100);
		
		cleardevice();
	}
	getch();
	closegraph();
	return 0;
}
