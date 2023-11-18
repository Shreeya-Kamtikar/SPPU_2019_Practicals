// OOP Assn2
#include<iostream>
using namespace std;

class pers_info
{
	//string lic, dob, bgrp;
	public:
		string lic, dob, bgrp;
		pers_info();			//default
		pers_info(pers_info &obj);		//copy constructor
		~pers_info();		//destructor
		friend class Student;
};

pers_info::~pers_info()
{
	cout << "Destructor for pers_info called. Data deleted successfully." << endl;
}

class Student
{
	string name, address, cla_ss, div;
	int rno;
	string cell_no;
	static int count;
	public:
		void create(pers_info &);
		void display(pers_info &);
		inline static void inccnt()	//static fn
		{
			count++;
		}
		inline static void showcnt()		//static fn
		{
			cout << "Number of entries is: " << count << endl;
		}
		Student();				//default
		Student(Student &);		//copy
		~Student();				// destructor
};

Student::~Student()
{
	cout << "Destructor for Student called. Data deleted successfully." << endl;	
}

int Student::count;		//definition of static member
Student::Student()
{
	name = "Reeya";
	cla_ss = "CompSci";
	div = "A";
	rno = 133;
	cell_no = "9876543210";
	address = "Bavdhan,Pune";
}

pers_info::pers_info()
{
	lic = "ARHN830053";
	dob = "2nd/November/2002";
	bgrp = "O+ve";
}

Student::Student(Student &obj)
{
	this->name = obj.name;
	this->cla_ss = obj.cla_ss;
	this->div = obj.div;
	this->rno = obj.rno;
	this->cell_no = obj.cell_no;
	this->address = obj.address;
}

pers_info::pers_info(pers_info &obj)
{
	this->lic = obj.lic;
	this->bgrp = obj.bgrp;
	this->dob = obj.dob;
}

void Student::create(pers_info &obj)
{
	cout << "Enter the details of student: " << endl;
	cout << "Name: "; 
	cin >> name;
	cout <<"\nClass: ";
	cin >> cla_ss;
	cout << "\nDivision: ";
	cin >> div;
	cout << "\nRoll Number: ";
	cin >> rno;
	cout << "\nMobile number: ";
	cin >> cell_no;
	cout << "\nAddress: ";
	cin >> address;
	cout << "\nDate of Birth: ";
	cin >> obj.dob;
	cout << "\nBlood Group: ";
	cin>> obj.bgrp;
	cout << "\nLicence Number: ";
	cin >> obj.lic;
}

void Student::display(pers_info &obj)
{
	cout << "\nInformation of student is: " << endl;
	cout << "Name: " << name << endl;
	cout << "Class: " << cla_ss << endl;
	cout << "Division: " << div << endl;
	cout << "Roll Number: " << rno << endl;
	cout << "Mobile Number: " << cell_no << endl;
	cout << "Address: " << address << endl;
	cout << "Date of Birth: " << obj.dob << endl;
	cout << "Blood Group: " << obj.bgrp << endl;
	cout << "Licence Number: " << obj.lic << endl;
}

int main()
{
	int n, ch;
	char ans;
	cout << "Enter number of students: ";
	cin >> n;
	Student *objs = new Student[n];
	pers_info *objp = new pers_info[n];
	
	do
	{
		cout << "\n1. Create database." << endl;
		cout << "2. Display database." << endl;
		cout << "3. Copy Constructor." << endl;
		cout << "4. Default Constructor." << endl;
		cout << "5. Destructor." << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				for(int i=0; i<n; i++)
				{
					objs[i].create(objp[i]);
					objs[i].inccnt();
				}
			}
			break;
			case 2:
			{
				objs[0].showcnt();
				for(int i=0; i<n; i++)
					objs[i].display(objp[i]);
			}
			break;
			case 3:
			{
				Student obj1;
				pers_info obj2;
				obj1.create(obj2);
				Student obj3(obj1);
				pers_info obj4(obj2);
				cout << "Copy constructor called. " << endl;
				obj3.display(obj4);
			}
			break;
			case 4:
			{
				Student obj1;
				pers_info obj2;
				cout << "Default constructor called. " << endl;
				obj1.display(obj2);
			}
			break;
			case 5:
			{
				delete [] objs;
				delete [] objp;
			}
		}
		cout << "Enter Y/y to continue: " ;
		cin >> ans;
		
	} while(ans == 'Y' || ans == 'y');
	
	return 0;
}
