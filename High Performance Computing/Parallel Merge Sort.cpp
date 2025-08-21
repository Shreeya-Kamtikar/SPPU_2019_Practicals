#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <omp.h>
using namespace std;

void merge(vector<int>& arr, int lt, int m, int rt)
{
	vector<int> temp;
	int left = lt;
	int right = m+1;
	while (left <= m && right <= rt) 
	{
        if (arr[left] <= arr[right]) 
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= m) 
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= rt)
    {
        temp.push_back(arr[right]);
        right++;
	}
	
    for (int i = lt; i <= rt; i++) 
    {
        arr[i] = temp[i - lt];
    }
}

void Parallel_MergeSort(vector<int>& arr, int lt, int rt) 
{
    if (lt < rt) 
    {
        int m = lt + (rt - lt) / 2;
        #pragma omp parallel sections
        {
			#pragma omp section
			Parallel_MergeSort(arr, lt, m);
			#pragma omp section
			Parallel_MergeSort(arr, m + 1, rt);
		}
		merge(arr, lt, m, rt);	
    }
}

void Sequential_MergeSort(vector<int>& arr, int lt, int rt) 
{
    if (lt < rt) 
    {
        int m = lt + (rt - lt) / 2;
        Sequential_MergeSort(arr, lt, m);
        Sequential_MergeSort(arr, m + 1, rt);
        merge(arr, lt, m, rt);
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

    clock_t seq_mergeStart = clock();
	Sequential_MergeSort(arr, 0, n - 1);
	clock_t seq_mergeEnd = clock();
	cout << "\n\nSequential Merge Sort: ";
	for(int num : arr)
		cout << num << " ";		
	cout << endl;
	
	double seq_mergeDuration = double(seq_mergeEnd-seq_mergeStart) / CLOCKS_PER_SEC;
	cout << "Sequential Merge sort time in seconds: " << fixed << seq_mergeDuration << endl;

    clock_t par_mergeStart = clock();
	Parallel_MergeSort(arr, 0, n - 1);
	clock_t par_mergeEnd = clock();
	cout << "\n\nParallel Merge Sort: ";
	for(int num : arr)
		cout << num << " ";		
	cout << endl;
	
	double par_mergeDuration = double(par_mergeEnd-par_mergeStart) / CLOCKS_PER_SEC;
	cout << "Parallel Merge sort time in seconds: " << fixed << par_mergeDuration << endl;
}