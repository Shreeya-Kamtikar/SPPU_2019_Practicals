#include <iostream>
using namespace std;

int main()
{
    int bsize[10], psize[10], bno, pno, fragment[10];
    int i, j, temp, lowest = 9999;
    static int barr[10], parr[10];

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

    //best fit
    for(i=0; i<pno; i++)
    {
        for(j=0; j<bno; j++)
        {
            if(barr[j]!=1)
            {
                temp = bsize[j]-psize[i];
                if(temp>=0)
                {
                    if(lowest>temp)
                    {
                        parr[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        fragment[i] = lowest;
        barr[parr[i]] = 1;
        lowest = 10000;
    }

    //display
    cout << "PNo\t\tPSize\t\tBno\t\tBSize\t\tFragment" << endl;
    for(i=0; i<pno && parr[i]!=0; i++)
        cout << "P" << (i+1) << "\t\t" << psize[i] << "\t\t" << parr[i] << "\t\t" << bsize[parr[i]] << "\t\t" << fragment[i] << endl;

    return 0;
}