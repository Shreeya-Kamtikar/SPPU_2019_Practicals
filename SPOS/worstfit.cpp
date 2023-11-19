#include <iostream>
using namespace std;

void worstfit(int bsize[10], int bno, int psize[10], int pno)
{
    int allocation[10];

    for(int i=0; i<10; i++)
        allocation[i] = -1;

    for (int i=0; i<pno; i++)
    {
        int wstIndex = -1;
        for(int j=0; j<bno; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if(wstIndex == -1)
                    wstIndex = j;
                else if(bsize[wstIndex] < bsize[j])
                    wstIndex = j;
            }
        }
        if (wstIndex != -1)
        {
            allocation[i] = wstIndex;
            bsize[wstIndex] -= psize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < pno; i++)
    {
        cout << " " << i+1 << "\t\t" << psize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated" << endl;
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

    worstfit(bsize,bno,psize,pno);

    return 0;
}