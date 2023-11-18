#include <iostream>
using namespace std;
#define size 10
class OBST
{
	public:
	int n;
	int a[size];
	int p[size];
	int q[size];
	int w[size][size];
	int c[size][size];
	int r[size][size];
	void in()
	{
		cout<<"Enter the number of nodes :";
		cin>>n;
		cout<<endl<<"Enter the elements :"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<"Enter element number "<<i<<" : ";
			cin>>a[i];
			cout<<endl;
			cout<<"Enter probability of being the root : ";
			cin>>p[i];
			cout<<endl;
		}
		for(int i=0;i<=n;i++)
		{
			cout<<"Enter probability of not being the root : "<<i<<": ";
			cin>>q[i];
			cout<<endl;
		}
	}
	int min(int i, int j)
	{
		int m,k;
		int mini=10000;
		for(m=r[i][j-1];m<=r[i+1][j];m++)
		{
			if((c[i][m-1]+c[m][j])<mini)
			{
				mini=c[i][m-1]+c[m][j];
				k=m;
			}
		}
		return k;
	}
	void constructOBST()
	{
		int j,k;
		for(int i=0 ; i<n ; i++)
		{
			c[i][i]=0;
			r[i][i]=0;
			w[i][i]=q[i];
			w[i][i+1]=q[i]+q[i+1]+p[i+1];
			r[i][i+1]=i+1;
			c[i][i+1]=q[i]+q[i+1]+p[i+1];
		}
		w[n][n]=q[n];
		r[n][n]=c[n][n]=0;
		for(int m=2;m<=n;m++)
		{
			for(int i=0;i<=n-m;i++)
			{
				j=i+m;
				w[i][j]=w[i][j-1]+p[j]+q[j];
				k=min(i,j);
				c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
				r[i][j]=k;
			}
		}
	}
	void construct()	
	{
		int i,j,k;
		int queue[20],front=-1,rear=-1;
		cout<<"OBST for given node" << endl;
		cout<<"The Root of this OBST is :"<<r[0][n] << endl;
		cout<<"The Cost of this OBST is:"<<c[0][n] << endl;
		cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD";
		cout<<"\n";
		queue[++rear]=0;
		queue[++rear]=n;
	
		while(front!=rear)
		{
			i=queue[++front];
			j=queue[++front];
			k=r[i][j];
			cout<<"\n\t"<<k;
			if(r[i][k-1]!=0)
			{
				cout<<"\t\t"<<r[i][k-1];
				queue[++rear]=i;
				queue[++rear]=k-1;
			}
			else
				cout<<"\t\t";
			if(r[k][j]!=0)
			{
				cout<<"\t"<<r[k][j];
				queue[++rear]=k;
				queue[++rear]=j;
			}
			else
				cout<<"\t";
		}
		cout<<"\n";
	}
};


int main()
{
	OBST obj;
	obj.in();
	obj.constructOBST();
	obj.construct();
	return 0;
}