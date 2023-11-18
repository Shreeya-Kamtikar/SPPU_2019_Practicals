#include<iostream>
using namespace std;
#define size 10

class heap
{
	public:
		void maxheap(int arr[],int n);
		void minheap(int arr[],int n);
		void display(int arr[],int n);
};

void heap::maxheap(int arr[], int n)
{
	for(int i=n/2; i>=0; i--)
	{
		int largest = i;
		int l = 2*i + 1;
		int r = 2*i + 2;
		
		if(l<n && arr[l] > arr[largest])
			largest = l;
		if(r<n && arr[r] > arr[largest])
			largest = r;
		if(largest != i)
		{
			int temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;
			maxheap(arr,n);
		}
	}
}

void heap::minheap(int arr[], int n)
{
	for(int i=n/2; i>=0; i--)
	{
		int smallest = i;
		int l = 2*i + 1;
		int r = 2*i + 2;
		
		if(l<n && arr[l] < arr[smallest])
			smallest = l;
		if(r<n && arr[r] < arr[smallest])
			smallest = r;
		if(smallest != i)
		{
			int temp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = temp;
			minheap(arr,n);
		}
	}
}

void heap::display(int arr[], int n)
{
	cout << arr[0];
	cout << "\nMarks: " << endl;
	for(int i=0;i<n;i++)
		cout << arr[i] << "\t\t";
	cout << endl;
}

int main()
{
	int arr[size];
	int n;
	cout << "Enter number of students whose marks are to be stored: ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cout << "Enter marks for student " << i+1 << ": ";
		cin >> arr[i];
	}
	
	heap hp;
	hp.maxheap(arr,n);
	cout << "Highest Marks: ";
	hp.display(arr,n);
	
	hp.minheap(arr,n);
	cout << "Lowest Marks: ";
	hp.display(arr,n);
}