#include<iostream>
#include<cstring>
using namespace std;

class publication
{
    string title;
    float price;
    public:
    publication();
    void getdata();
    void displaydata();
};

publication :: publication()
{
    title = ' ';
    price = 0.0;
}

void publication::getdata()
{
    cout << "Enter the title: ";
    getline(cin>>ws,title);
    cout << "Enter the price: ";
    cin >> price;
}

void publication::displaydata()
{
    cout << "Title: " << title << endl;
    cout << "Price: Rs." << price << endl;
}

class Book:public publication
{
    int pg_no;
    public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter number of pages: ";
        cin >> pg_no;
    }
    void displaydata()
    {
        publication::displaydata();
        cout << "Number of pages: " << pg_no << endl;
    }
};

class Tape:public publication
{
    float time;
    public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter duration of tape in minutes: ";
        cin >> time;
    }
    void displaydata()
    {
        publication::displaydata();
        cout << "Duration of tape: " << time << " minutes" << endl;
    }
};

int main()
{
    Book b;
    Tape t;
    int ch;
    do
    {
        cout << "\n1)Book\n2)Tape\n3)Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                b.getdata();
                b.displaydata();
                break;
            case 2:
                t.getdata();
                t.displaydata();
                break;
            case 3:
                cout << "Exiting process" << endl;
                break;
            default:
            	cout << "Title = 0" << endl;
            	cout << "Price = 0.0" << endl;
        }
    } while(ch<3);
    return 0;
}


