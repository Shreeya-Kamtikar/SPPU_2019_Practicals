#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct Employee
{
    int empid;
    string name;
    string designation;
    string salary;
};

void add_emp()
{
    Employee e;
    cout << "Enter employee id: ";
    cin >> e.empid;
    cout << "Enter name: ";
    cin >> e.name;
    cout << "Enter designation: ";
    cin >> e.designation;
    cout << "Enter salary: ";
    cin >> e.salary;

    if (1 <= e.empid and e.empid <= 10)
    {
        ofstream write;
        write.open("1to10.txt", ios::app);

        write << "\n" << e.empid;
        write << "\n" << e.name;
        write << "\n" << e.designation;
        write << "\n" << e.salary;

        write.close();
    }
    if (11 <= e.empid and e.empid <= 20)
    {
        ofstream write;
        write.open("11to20.txt", ios::app);

        write << "\n" << e.empid;
        write << "\n" << e.name;
        write << "\n" << e.designation;
        write << "\n" << e.salary;

        write.close();
    }
    if (21 <= e.empid and e.empid <= 30)
    {
        ofstream write;
        write.open("21to30.txt", ios::app);

    	write << "\n" << e.empid;
        write << "\n" << e.name;
        write << "\n" << e.designation;
        write << "\n" << e.salary;

        write.close();
    }
    if (31 <= e.empid and e.empid <= 40)
    {
        ofstream write;
        write.open("31to40.txt", ios::app);

        write << "\n" << e.empid;
        write << "\n" << e.name;
        write << "\n" << e.designation;
        write << "\n" << e.salary;

        write.close();
    }
    if (41 <= e.empid and e.empid <= 50)
    {
        ofstream write;
        write.open("41to50.txt", ios::app);

        write << "\n" << e.empid;
        write << "\n" << e.name;
        write << "\n" << e.designation;
        write << "\n" << e.salary;

        write.close();
    }
}

void display(Employee e)
{
    cout << "Employee ID: " << e.empid << endl;
    cout << "Name: " << e.name << endl;
    cout << "Designation: " << e.designation << endl;
    cout << "Salary: " << e.salary << endl;
}

void display_emp()
{
    Employee e1;
    ifstream read;
    read.open("1to10.txt");
    while (!read.eof())
    {
        read >> e1.empid;
        read >> e1.name;
        read >> e1.designation;
        read >> e1.salary;

        display(e1);
    }
    read.close();

    cout << endl;

    Employee e2;
    read.open("11to20.txt");
    while (!read.eof())
    {
        read >> e2.empid;
        read >> e2.name;
        read >> e2.designation;
        read >> e2.salary;

        display(e2);
    }
    read.close();

    cout << endl;

    Employee e3;
    read.open("21to30.txt");
    while (!read.eof())
    {
        read >> e3.empid;
        read >> e3.name;
        read >> e3.designation;
        read >> e3.salary;

        display(e3);
    }
    read.close();

    cout << endl;

    Employee e4;
    read.open("31to40.txt");
    while (!read.eof())
    {
        read >> e4.empid;
        read >> e4.name;
        read >> e4.designation;
        read >> e4.salary;

        display(e4);
    }
    read.close();

    cout << endl;

    Employee e5;
    read.open("41to50.txt");
    while (!read.eof())
    {
        read >> e5.empid;
        read >> e5.name;
        read >> e5.designation;
        read >> e5.salary;

        display(e5);
    }
    read.close();

    cout << endl;
}

int search_emp(int emp_id)
{
    if (1 <= emp_id and emp_id <= 10)
    {
        Employee e;
        ifstream read;
        read.open("1to10.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid == emp_id)
            {
                cout << "Employee record found!" << endl;
                display(e);
                return emp_id;
            }
        }
        read.close();
    }
    if (11 <= emp_id and emp_id <= 20)
    {
        Employee e;
        ifstream read;
        read.open("11to20.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid == emp_id)
            {
                cout << "Employee record found!" << endl;
                display(e);
                return emp_id;
            }
        }
        read.close();
    }
    if (21 <= emp_id and emp_id <= 30)
    {
        Employee e;
        ifstream read;
        read.open("21to30.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid == emp_id)
            {
                cout << "Employee record found!" << endl;
                display(e);
                return emp_id;
            }
        }
        read.close();
    }
    if (31 <= emp_id and emp_id <= 40)
    {
        Employee e;
        ifstream read;
        read.open("31to40.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid == emp_id)
            {
                cout << "Employee record found!" << endl;
                display(e);
                return emp_id;
            }
        }
        read.close();
    }
    if (41 <= emp_id and emp_id <= 50)
    {
        Employee e;
        ifstream read;
        read.open("41to50.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid == emp_id)
            {
                cout << "Employee record found!" << endl;
                display(e);
                return emp_id;
            }
        }
        read.close();
    }
    return -1;
}

void delete_emp(int emp_id)
{
    emp_id = search_emp(emp_id);

    if (emp_id == -1)
    {
        cout << "Employee record to be deleted is not present in the file!" << endl;
        return;
    }
    
    if (1 <= emp_id and emp_id <= 10)
    {
        Employee e;
        ifstream read;
        ofstream write;
        read.open("1to10.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid != emp_id)
            {
                write << "\n" << e.empid;
        		write << "\n" << e.name;
        		write << "\n" << e.designation;
        		write << "\n" << e.salary;
            }
        }
        read.close();
        write.close();
        remove("1to10.txt");
        rename("temp.txt", "1to10.txt");
        cout << "Deletion successful" << endl;
    }
    if (11 <= emp_id and emp_id <= 20)
    {
        Employee e;
        ifstream read;
        ofstream write;
        read.open("11to20.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid != emp_id)
            {
                write << "\n" << e.empid;
        		write << "\n" << e.name;
        		write << "\n" << e.designation;
        		write << "\n" << e.salary;
            }
        }
        read.close();
        write.close();
        remove("11to20.txt");
        rename("temp.txt", "11to20.txt");
        cout << "Deletion successful" << endl;
    }
    if (21 <= emp_id and emp_id <= 30)
    {
        Employee e;
        ifstream read;
        ofstream write;
        read.open("21to30.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid != emp_id)
            {
                write << "\n" << e.empid;
        		write << "\n" << e.name;
        		write << "\n" << e.designation;
        		write << "\n" << e.salary;
            }
        }
        read.close();
        write.close();
        remove("21to30.txt");
        rename("temp.txt", "21to30.txt");
        cout << "Deletion successful" << endl;
    }
    if (31 <= emp_id and emp_id <= 40)
    {
        Employee e;
        ifstream read;
        ofstream write;
        read.open("31to40.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid != emp_id)
            {
                write << "\n" << e.empid;
        		write << "\n" << e.name;
        		write << "\n" << e.designation;
        		write << "\n" << e.salary;
            }
        }
        read.close();
        write.close();
        remove("31to40.txt");
        rename("temp.txt", "31to40.txt");
        cout << "Deletion successful" << endl;
    }
    if (41 <= emp_id and emp_id <= 50)
    {
        Employee e;
        ifstream read;
        ofstream write;
        read.open("41to50.txt");
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> e.empid;
        	read >> e.name;
        	read >> e.designation;
        	read >> e.salary;
            if (e.empid != emp_id)
            {
                write << "\n" << e.empid;
        		write << "\n" << e.name;
        		write << "\n" << e.designation;
        		write << "\n" << e.salary;
            }
        }
        read.close();
        write.close();
        remove("41to50.txt");
        rename("temp.txt", "41to50.txt");
        cout << "Deletion successful" << endl;
    }
}

int main()
{
    int choice;
    do 
    {
        cout << "---------EMPLOYEE RECORDS---------" << endl;
        cout << "Enter 1 for adding a record" << endl;
        cout << "Enter 2 for displaying the records" << endl;
        cout << "Enter 3 for searching a record" << endl;
        cout << "Enter 4 for deleting a record" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_emp();
            break;
        case 2:
            display_emp();
            break;
        case 3:
            int emp_id;
            cout << "Enter employee id to be searched-\n";
            cin >> emp_id;
            search_emp(emp_id);
            break;
        case 4:
            cout << "Enter employee id to be deleted-\n";
            cin >> emp_id;
            delete_emp(emp_id);
            break;
        case 0:
            break;
        }
    } while (choice != 0);
    return 0;
}