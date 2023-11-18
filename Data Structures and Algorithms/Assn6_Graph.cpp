#include<iostream>
using namespace std;

int m;

class Graph
{
	public:
		int arr[10][10];
		string cities[10];
		int visited[10];
		void insert();
		void display_mat();
		void display_list();
};

void Graph::insert()
{
	cout << "Enter number of cities(<10): ";
	cin >> m;
	cout << "Enter City names: " << endl;
	for(int k=1; k<=m; k++)
	{
		cout << "Enter name of City#" << k << ": ";
		cin >> cities[k];
	}
	
	cout << "Following cities have been inserted: " << endl;
	cout << "Num\t\tName" << endl;
	for(int k=1; k<=m; k++)
		cout << k << "\t\t" << cities[k] << endl;
		
	for(int i=1;i<=m;i++)
	{
		visited[i] = 0;
		for(int j=1;j<=m;j++)
			arr[i][j] = 0;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			cout << "Enter time of flight between: " << cities[i] << " & " << cities[j] << ": ";
			cin >> arr[i][j];
			arr[j][i] = arr[i][j];
		}
	}
}

void Graph::display_mat()
{
	cout << "\n\nAdjacency Matrix:\n";

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout << "\t" << arr[i][j] << "\t\t";
		}
		cout << endl;
	}
}

void Graph::display_list()
{
	cout << "\n\nAdjacency List:" << endl;
	for(int i=1;i<=m;i++)
	{
		cout << cities[i] << " --> ";
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j]!=0)
				cout << cities[j] << " ---> ";
		}
		cout << "NULL"<< endl;
	}
}

int main()
{
	Graph gr;
	gr.insert();
	gr.display_list();
	gr.display_mat();
}