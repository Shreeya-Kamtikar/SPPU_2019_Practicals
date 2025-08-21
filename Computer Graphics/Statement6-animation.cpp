#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
    int gd,gm,i,j,xm,ym;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
    xm=getmaxx();
    cout << xm << endl;
    cout << ym;
    ym=getmaxy();
	for (i=0;i<400;i++)
    {
   	line(0,440,1500,440);
	for (j=0;j<100;j++)
   	{
   		if (i%2==0)
   		{
   			line(100+i,410,110+i,440);
   			line(100+i,410,90+i,440);
   		}
   		else
   		{
   			line(100+i,410,95+i,440);
   			line(100+i,410,105+i,440);
   		}
   		circle(100+i,300,20);
   		line(100+i,320,100+i,410);
   		line(100+i,350,120+i,384);
   		line(100+i,350,110+i,320);
   		line(110+i,283,110+i,235);
   		 
		line(50+i,235,170+i,235);
   		line(110+i,205,50+i,235);
   		line(170+i,235,110+i,205);
   		 
   		outtextxy(rand()%xm,rand()%(ym-60),"|");
		setcolor(WHITE);
   	 }
   	 delay(20);
   	 cleardevice();
    }
    getch();
    closegraph();
}

