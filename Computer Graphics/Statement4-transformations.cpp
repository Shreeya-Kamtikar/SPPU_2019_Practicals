#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class transformation
{
    public:
    double a[5][5];
    double c[5][5];
    int n;
    void insert();
    void display();
    void multiply(double b[5][5]);
};

void transformation :: insert()
{
    int i,j,k;
    cout<<"enter number of edges: "<<endl;
    cin>>n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-1;j++)
        {
            cin>>a[i][j];
        }
        a[i][2]=1;
    }
    for (k=0;k<n-1;k++)
    {
        line(a[k][0],a[k][1],a[k+1][0],a[k+1][1]);
    }
    line(a[n-1][0],a[n-1][1],a[0][0],a[0][1]);
}
void transformation :: multiply(double b[5][5])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
}
void transformation :: display()
{
   
    for (int k=0;k<n-1;k++)
    {
        line(c[k][0],c[k][1],c[k+1][0],c[k+1][1]);
    }
    line(c[n-1][0],c[n-1][1],c[0][0],c[0][1]);
}
   



int main()
{
    int gd,gm;
    initgraph(&gd,&gm,NULL);
    gd=DETECT;
    double b[5][5];
    int choice;
    do
    {
    	cout<<"Enter 1 for translation"<<endl;
    	cout<<"Enter 2 for rotation "<<endl;
    	cout<<"Enter 3 for scaling"<<endl;
    	cout<<"Enter 4 to exit"<<endl;
    	cout<<"Enter your choice"<<endl;
    	cin>>choice;
    	transformation t;
    	t.insert();
    	switch(choice)
    	{
    	    case 1:
    	    	int tx,ty;
    	    	cout<<"Enter the tx value"<<endl;
    	    	cin>>tx;
    	    	cout<<"Enter the ty value"<<endl;
    	    	cin>>ty;
    	    	b[0][0] = b[1][1] = b[2][2] = 1;
    	    	b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
    	    	b[2][0]=tx;
    	    	b[2][1]=ty;
    	    	t.multiply(b);
    	    	t.display();
    	    	break;
    	    case 3:
    	    	int sx,sy;
    	    	cout<<"Enter the sx value"<<endl;
    	    	cin>>sx;
    	    	cout<<"Enter the sy value"<<endl;
    	    	cin>>sy;
    	    	b[0][0]=sx;
    	    	b[1][1]=sy;
       			b[2][2]=1;
        		b[0][1]=b[0][2]=b[1][0]=b[1][2]=b[2][0]=b[2][1]=0;
        		t.multiply(b);
        		t.display();
        		break;
        	case 2:
        		float deg, theta;
        		cout<<"enter the angle of rotation: ";
        		cin>>deg;
				theta = deg * (3.14/180);
        		b[0][0]=b[1][1]=cos(theta);
       		 	b[0][1]=sin(theta);
        		b[1][0]=-sin(theta);
        		b[2][2]=1;
        		b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
				t.multiply(b);
	    	    t.display();
	    	    break; 
    	}
	}while(choice!=4);
    getch();
    closegraph();
}
