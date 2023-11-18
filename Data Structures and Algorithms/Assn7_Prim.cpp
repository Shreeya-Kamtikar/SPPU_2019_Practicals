#include<iostream>
using namespace std;

class tree
{
	int arr[20][20], visited[20], l, u, w, i, j, b, e;
	public:
		void input();
		void display();
		void minimum();
};

void tree::input()
{
	cout << "Enter the number of branches: ";		//branches --> vertices
	cin >> b; 
	for(i=0;i<b;i++)
	{
		visited[i] = 0;
		for(j=0;j<b;j++)
			arr[i][j] = 999;
	}
	
	cout << "Enter number of connections: ";		// connections --> edges
	cin >> e;
	for(i=0;i<e;i++)
	{
		cout << "\nEnter end branches between which connection is to be created: ";
		cin >> l >> u;
		cout << "Enter the cost of connection: ";
		cin >> w;
		arr[l-1][u-1] = arr[u-1][l-1] = w;
	}
}

void tree::display()
{
	cout << "\n\nAdjacency Matrix" << endl;
	for(i=0;i<b;i++)
	{
		cout << endl;
		for(j=0;j<b;j++)
			cout << arr[i][j] << "\t\t";
		cout << endl;
	}
}

void tree::minimum()
{
	int p=0, q=0, total=0, min;
	visited[0] = 1;
	for(int count=0; count<(b-1); count++)
	{
		min=999;
		for(i=0;i<b;i++)
		{
			if(visited[i]==1)
			{
				for(j=0;j<b;j++)
				{
					if(visited[j]!=1)
					{
						if(min > arr[i][j])
						{
							min = arr[i][j];
							p = i;
							q = j;
						}
					}
				}
			}
		}
		visited[p] = 1;
		visited[q] = 1;
		total += min;
		cout << "Minimum cost connection: " << (p+1) << " and " << (q+1) << " --> " << min << endl;
	}
	cout << "Total minimum cost of connections of all branches is: " << total;
}

int main()
{
	tree t1;
	t1.input();
	t1.display();
	t1.minimum();
	return 0;
}