#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
class koch
{
	public:
		int dx, dy;
		void curve(int iter, int x1, int y1, int x5, int y5);
};

void koch::curve(int iter, int x1, int y1, int x5, int y5)
{
	int x2, y2, x3, y3, x4, y4;
	if(iter==0)
	{
		setcolor(RED);
		line(x1,y1,x5,y5);
	}
	else
	{
		delay(10);
		dx = (x5-x1)/3;
		dy = (y5-y1)/3;
		x2 = x1 + dx;
		y2 = y1 + dy;
		x3 = int(0.5*(x1+x5) + sqrt(3)*(y1-y5)/6);
		y3 = int(0.5*(y1+y5) + sqrt(3)*(x5-x1)/6);
		x4 = 2*dx + x1;
		y4 = 2*dy + y1;
		curve(iter-1,x1,y1,x2,y2);
		curve(iter-1,x2,y2,x3,y3);
		curve(iter-1,x3,y3,x4,y4);
		curve(iter-1,x4,y4,x5,y5);
	}
} 

int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
    int it;
    koch k;
    cout<<"Please enter the number of iterations: "<<endl;
    cin>>it;
    k.curve(it,200,70,70,330);
	k.curve(it,330,330,200,70);
	k.curve(it,70,330,330,330);
    getch();
    closegraph();
}

