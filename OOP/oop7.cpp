#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	typedef map<string,int> mapType;
	mapType populationMap;
	populationMap.insert(pair<string, int>("Maharashtra", 7026357));
	populationMap.insert(pair<string, int>("Rajasthan", 6578936));
	populationMap.insert(pair<string, int>("Karanataka", 6678993));
	populationMap.insert(pair<string, int>("Punjab", 5789032));
	populationMap.insert(pair<string, int>("West Bengal", 6676291));
	mapType::iterator iter;
	cout<<"========Population of states in India==========" << endl;
	cout<<"Size of populationMap: "<<populationMap.size()<<endl;
	string state_name;
	cout<<"Enter name of the state: " << endl;
	cin>>state_name;
	iter = populationMap.find(state_name);
	if( iter!= populationMap.end() )
		cout<<state_name<<"'s population is "<<iter->second ;
	else
		cout<<"Key is not populationMap"<<endl;
	populationMap.clear();
	return 0;
}
