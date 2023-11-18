#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pattern{
public:
int x1,y1,x2,y2;
int xc,yc;
float r;
void ddaLine();
void bresenhamCircle();
void drawcircle(int x,int y);
};

void pattern::ddaLine()
{
    cin>>x1;
    cin>>y1;
    cin>>x2;
    cin>>y2;
	int dx=x2-x1;
	int dy=y2-y1;
	int steps=dx>dy?dx:dy;
	float xinc=dx/(float)steps;
	float yinc=dy/(float)steps;
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,15);
		x+=xinc;
		y+=yinc;
	}
}

void pattern::drawcircle(int x,int y)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc-y,yc-x,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc+y,yc-x,WHITE);
}

void pattern::bresenhamCircle(){
    cin>>xc;
    cin>>yc;
    cin>>r;
    putpixel(xc,yc,RED);
    int x = 0, y = r;
    int d = 3 - (2*r);
    while(y>=x){
        x++;
        if(d>=0){
            y--;
            d = d + 4*(x - y) + 10;
        }
        else{
            d = d+4*x+6;
        }
        drawcircle(x,y);
        delay(5);
    }
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	pattern p;
	cout<<"Enter Coordinates of 1 line(x1,y1,x2,y2): "<<endl;
	p.ddaLine();
	cout<<"Enter Coordinates of 2 line(x1,y1,x2,y2): "<<endl;
    p.ddaLine();
	cout<<"Enter Coordinates of 3 line(x1,y1,x2,y2): "<<endl;
    p.ddaLine();
    cout<<"Enter Coordinates of inner Circle(xc,yc,r): "<<endl;
    p.bresenhamCircle();
    cout<<"Enter Coordinates of outer Circle(xc,yc,r): "<<endl;
    p.bresenhamCircle();
	getch();
	closegraph();
	return 0;
}
