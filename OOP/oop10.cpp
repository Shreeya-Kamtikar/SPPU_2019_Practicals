#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()

{

    fstream fobj;
    int count=0;
    fobj.open("toread.txt");
    char str[100];
    while(!fobj.eof())
    {

        fobj.getline(str, 100);
        if(str[0]!='A')
        {
        count++;
        }
    }
    cout << "Number of lines not starting with 'A' is: " << count;
    fobj.close();
    return 0;

}
