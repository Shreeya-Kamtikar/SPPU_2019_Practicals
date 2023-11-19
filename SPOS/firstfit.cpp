#include <iostream>
using namespace std;

int main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocations[10];
    int i, j;
    for(i=0; i<10; i++)
    {
        flags[i] = 0;
        allocations[i] = -1;
    }

    cout << "\nEnter number of blocks: ";
    cin >> bno;
    for(i=0; i<bno; i++)
    {
        cout << "\nEnter size of block" << (i+1) << ": ";
        cin >> bsize[i];
    }

    cout << "\nEnter number of processes: ";
    cin >> pno;
    for(i=0; i<pno; i++)
    {
        cout << "\nEnter size of process" << (i+1) << ": ";
        cin >> psize[i];
    }

    //first fit code
    for(i=0; i<pno; i++)
    {
        for(j=0; j<bno; j++)
        {
            if(flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocations[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }

    //display
    cout << "BNo\t\tBSize\t\tPNo\t\tPSize" << endl;
    for(i=0; i<bno; i++)
    {
        cout << (i+1) << "\t\t" << bsize[i];
        if(flags[i] == 1)
            cout << "\t\t" << allocations[i]+1 << "\t\t" << psize[allocations[i]] << endl;
        else
            cout << "\t\tNot allocated" << endl;
    }

    return 0;
}