//OOP 5
#include<iostream>
using namespace std;
#define size 10

int n;
template<class T>
void sel(T A[size])
{
    int i,j;
    T temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[i])
			{
				temp=A[i];
        		A[i]=A[j];
        		A[j]=temp;
			}
		}
    }
    cout<<"Sorted array: " << endl;
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<A[i];
    }
}

int main()
{
    int A[size];
    float B[size];
    int i;

    cout<<"Enter total no of int elements: ";
    cin>>n;
    cout<<"Enter int elements: ";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sel(A);

    cout<<"\nEnter total no of float elements: ";
    cin>>n;
    cout<<"Enter float elements: ";
    for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    sel(B);
}

