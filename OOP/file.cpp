#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
	char ch;
	int c;
	if(argc>=2)
	{
		ifstream fin;
		fin.open(argv[1]);
		if(fin)
		{
			fin.seekg(0,ios::end);
			c = fin.tellg();
		}
			fin.close();
			cout << "Size of file: " << c << " bytes" << endl;
	}
	else
		cout << "Source file not found.";
	return 0;
}