#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <omp.h>
using namespace std;

void BubbleSort_Parallel(vector<int>& arr)
{
	int size = arr.size();
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		#pragma omp parallel for
		for (int i=0; i<size-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				swap(arr[i],arr[i+1]);
				swapped = true;
			}
		}
	}
}

void BubbleSort_Sequential(vector<int>& arr)
{
	int size = arr.size();
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		for (int i=0; i<size-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				swap(arr[i],arr[i+1]);
				swapped = true;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	
	vector<int> arr(n);
	for(int i=0; i<n; i++)
	{
		cout << "Enter element: ";
		cin >> arr[i];
	}
	
    clock_t seq_bubbleStart = clock();
	BubbleSort_Parallel(arr);
	clock_t seq_bubbleEnd = clock();
	cout << "\n\nSequential Bubble Sort: ";
	for(int num : arr)
		cout << num << " ";		
	cout << endl;
	
	double seq_bubbleDuration = double(seq_bubbleEnd-seq_bubbleStart) / CLOCKS_PER_SEC;
	cout << "Sequential Bubble sort time in seconds: " << fixed << seq_bubbleDuration << endl;

    
	clock_t parallel_bubbleStart = clock();
	BubbleSort_Parallel(arr);
	clock_t parallel_bubbleEnd = clock();
	cout << "\n\nParallel Bubble Sort: ";
	for(int num : arr)
		cout << num << " ";		
	cout << endl;
	
	double parallel_bubbleDuration = double(parallel_bubbleEnd-parallel_bubbleStart) / CLOCKS_PER_SEC;
	cout << "Parallel Bubble sort time in seconds: " << fixed << parallel_bubbleDuration << endl;

	double speedup = seq_bubbleDuration/parallel_bubbleDuration;
	cout << "Speedup: " << speedup << endl;

    return 0;
}