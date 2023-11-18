//oop4
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    fstream fobj;
    
    fobj.open("file2.txt", ios::out);
    char arr[100];
    cout << "Enter data to be entered in file: ";
    cin.getline(arr,100);
    int length = strlen(arr);
    fobj.write(arr,length+1);
    fobj.close();
    
    char line[100];
    fobj.open("file2.txt", ios::in);
    while(fobj)
    {
    	fobj.getline(line,length+1);
    	cout << line;
	}
	fobj.close();

    return 0;
}

