#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	char arr[100];
	cout << "Enter data to be entered in file: ";
	cin.getline(arr,100);
	ofstream fout("testfile.txt");
	fout << arr;
	fout.close();
	
	char line[100];
	ifstream fin("testfile.txt");
	fin.getline(line,100);
	fin.close();
	
	cout << "File contains: " << line << endl;
	
	
	return 0;
}
