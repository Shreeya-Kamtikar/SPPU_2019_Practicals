#include<iostream>
#include<graphics.h>
using namespace std;

class clipping
{
	public:
		int LEFT = 1;
		int RIGHT = 2;
		int TOP = 8;
		int BOTTOM = 4;
		int x1, y1, x2, y2, xd, yd, xh, yh, x, y;
		int temp;
		float m;
		int getcode(int x, int y);
		void process();
};

int clipping::getcode(int x, int y)
{
	int code = 0;
	if(y>yh)
		code |= TOP;
	if(y<yd)
		code |= BOTTOM;
	if(x>xh)
		code |= RIGHT;
	if(x<xd)
		code |= LEFT;
	return code;
}

void clipping::process()
{
	int code1, code2;
	cout << "Enter the top left coordinates of window: " << endl;
	cin >> xd >> yd;
	cout << "Enter the bottom right coordinates of window: " << endl;
	cin >> xh >> yh;
	rectangle(xd, yd, xh, yh);
	
	cout << "Enter the line coordinates: " << endl;
	cout << "Enter the starting coordinates: " ;
	cin >> x1 >> y1;
	cout << "Enter the ending coordinates: " ;
	cin >> x2 >> y2;
	line(x1, y1, x2, y2);
	delay(10);
	
	code1 = getcode(x1, y1);
	code2 = getcode(x2, y2);
	
	int flag = 0;
	while(1)
	{
		m = (float) (y2-y1)/(x2-x1);
		if((code1 == 0) && (code2 == 0))
		{
			flag =1;
			break;
		}
		else if((code1 & code2)!=0)
			break;
		else
		{
			if(code1==0)
				temp = code2;
			else
				temp = code1;
				if(temp & TOP)
				{
					x = x1 + (yh-y1)/m;
					y = yh;
				}
				else if(temp & BOTTOM)
				{
					x = x1 + (yd-y1)/m;
					y = yd;
				}
				else if(temp & RIGHT)
				{
					y = y1 + m*(xh-x1);
					x = xh;
				}
				else if(temp & LEFT)
				{
					y = y1 + m*(xd-x1);
					x = xd;
				}
				if (temp == code1)
				{
					x1 = x;
					y1 = y;
					code1 = getcode(x1, y1);
				}
				else
				{
					x2 = x;
					y2 = y;
					code2 = getcode(x2, y2);
				}
		}
	}
	getch();
	cleardevice();
	rectangle(xd, yd, xh, yh);
	if (flag == 1)
		line(x1,y1,x2,y2);
	getch();
	closegraph();
}

int main()
{
	int gd, gm;
	gd = DETECT;
	initgraph(&gd, &gm, NULL);
	clipping c1;
	c1.process();
	return 0;
	
}
