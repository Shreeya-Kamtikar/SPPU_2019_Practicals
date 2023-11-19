#include <iostream>
using namespace std;

void nextfit(int bsize[10], int bno, int psize[10], int pno)
{
    int allocation[10], t = bno-1;
    int j=0;

    for(int i=0; i<10; i++)
        allocation[i] = -1;

    for (int i=0; i<pno; i++)
    {
        while(j < bno)
        {
            if(bsize[j] >= psize[i])
            {
                allocation[i] = j;
                bsize[j] -= psize[i];
                t = (j-1)%bno;
                break;
            }
            if (t == j)
            {
                t = (j - 1) % bno;
                break;
            }
            j = (j + 1) % bno;
        }
    }

    cout << "PNo\t\tPSize\t\tBNo" << endl;
    for(int i=0; i<pno; i++)
    {
        cout << (i+1) << "\t\t" << psize[i] << "\t\t";
        if(allocation[i] != -1)
            cout << allocation[i]+1 << endl;
        else   
            cout << "Not allocated" << endl;
    }
}

int main()
{
    int bno, pno, bsize[10], psize[10];

    cout << "\nEnter number of blocks: ";
    cin >> bno;
    for(int i=0; i<bno; i++)
    {
        cout << "\nEnter size of block" << (i+1) << ": ";
        cin >> bsize[i];
    }

    cout << "\nEnter number of processes: ";
    cin >> pno;
    for(int i=0; i<pno; i++)
    {
        cout << "\nEnter size of process" << (i+1) << ": ";
        cin >> psize[i];
    }

    nextfit(bsize,bno,psize,pno);

    return 0;
}