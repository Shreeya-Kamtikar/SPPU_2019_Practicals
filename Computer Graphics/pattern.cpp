#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pattern
{
	public:
		int len, x1, y1, x2, y2, cx, cy;
		float dx, dy, x, y, d, r;
		void DDA(int x1, int y1, int x2, int y2);
		void Bresenham(int cx, int cy, float r);
};

void pattern::DDA(int x1, int y1, int x2, int y2)
{
	if(abs(x2-x1)>=abs(y2-y1))
		len = abs(x2-x1);
	else
		len = abs(y2-y1);
	dx = (x2-x1)/len;
	dy = (y2-y1)/len;
	int i = 1;
	x = x1;
	y = y1;
	x = x + 0.5;
	y = y + 0.5;
	while(i<len)
	{
		putpixel(x, y, RED);
		x = x + dx;
		y = y + dy;
		i = i + 1;
		//delay(50);
	}
}

void pattern::Bresenham(int cx, int cy, float r)
{
	int x, y;
	d = 3 - (2*r);
	x = 0;
	y = r;
	putpixel(x,y,RED);
	while(y>=x)
	{
		if(d<=0)
		{
			d = d+(4*x)+6;
			x++;
		}
		else
		{
			d = d+4*(x-y)+10;
			x++;
			y--;
		}	
		putpixel(x+cx, y+cy, RED);
		putpixel(x+cx, -y+cy, RED);
		putpixel(-x+cx, y+cy, RED);
		putpixel(-x+cx, -y+cy, RED);
		putpixel(y+cy, x+cx, RED);
		putpixel(y+cy, -x+cx, RED);
		putpixel(-y+cy, x+cx, RED);
		putpixel(-y+cy, -x+cx, RED);
		delay(10);
	}	
}

int main()
{
	int gd, gm;
	gd = DETECT;
	pattern p, p1;
	initgraph(&gd, &gm, NULL);
	p.DDA(0,0,100,0);
	p.DDA(0,0,0,100);
	p.DDA(100,0,100,100);
	p.DDA(100,100,0,100);
	p.DDA(50,0,100,50);
	p.DDA(100,50,50,100);
	p.DDA(50,100,0,50);
	p.DDA(0,50,50,0);
	p.Bresenham(50,50,35);
	
	//p1.DDA(102,150,198,150);
	//p1.DDA(150,236,198,150);
	//p1.DDA(102,150,150,236);
	p1.Bresenham(150,150,28.5);
	p1.Bresenham(150,150,57);

	
	getch();
	closegraph();
}
