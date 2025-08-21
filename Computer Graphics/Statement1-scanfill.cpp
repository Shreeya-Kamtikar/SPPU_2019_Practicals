#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

class sample
{
	public:
		int i, noe ,k;
		int x[100], y[100];
		int dx, dy, y1, x_int[100], slope[100], temp;
		void poly();
		void scanfill();
};

void sample::poly()
{
	cout << "Enter number of edges of polygon: " << endl;
	cin >> noe;
	cout << "Enter the coordinates of polygon: " << endl;
	for(i=0; i< noe; i++)
	{
		cout << "Enter x coordinate of point " << i+1 << ": ";
		cin >> x[i];
		cout << "Enter y coordinate of point " << i+1 << ": ";
		cin >> y[i];
	}
	x[noe] = x[0];
	y[noe] = y[0];
	
	for(i=0; i<noe; i++)
	{
		line(x[i], y[i], x[i+1], y[i+1]);
	}
}

void sample::scanfill()
{
	for(i=0; i<noe; i++)
	{
		dy = y[i+1] - y[i];
		dx = x[i+1] - x[i];
		if(dx == 0)
			slope[i] = 0;
		else if(dy == 0)
			slope[i] = 1;
		else
			slope[i] = dx/dy;
	}
	for(y1=0; y1<480; y1++)
	{
		k = 0;
		for(i=0; i<noe; i++)
		{
			if(((y[i]<=y1) && (y[i+1] > y1)) || ((y[i] > y1) && (y[i+1] <= y1)))
			{
				x_int[k] = int(x[i]+slope[i]*(y1-y[i]));
				k++;
			}
		}
		// sorting the intersection pts
		for(i=0; i<k-1; i++)
		{
			if(x_int[i] > x_int[i+1])
			{
				x_int[i] = temp;
				x_int[i] = x_int[i+1];
				x_int[i+1] = temp;
			}
		}
		for(i=0; i<k; i+=2)
		{
			line(x_int[i], y1, x_int[i+1], y1);
			setcolor(RED);
			delay(200);
		}
	}

}

int main()
{
	int gd, gm;
	gd = DETECT;
	initgraph(&gd, &gm, NULL);
	sample s;
	s.poly();
	s.scanfill();
	
	getch();
	closegraph();
}
