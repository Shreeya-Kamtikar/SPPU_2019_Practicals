#include<iostream>
using namespace std;
#define size 5

class pizza
{
    int order[size];
    int front, rear;
    public:
    pizza();
    void accept(int);
    void deliver();
    void display();
    int isfull();
    int isempty();
};

pizza::pizza()
{
    front = rear = -1;
}

int pizza::isfull()
{
    if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
        return 1;
    return 0;
}

int pizza::isempty()
{
    if(front==-1)
        return 1;
    return 0;
}

void pizza::accept(int item)
{
    if(isfull())
        cout << "Maximum capacity reached." << endl;
    else
    {
        rear = (rear+1)%size;
        order[rear] = item;
        if(front == -1)
            front = 0;
    }
}

void pizza::deliver()
{
    int item;
    if(isempty())
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Deleted element is: " << order[front];
        front = (front+1)%size;
        if(front==(rear+1)%size)
            front = rear = -1;
    }
}

void pizza::display()
{
    int temp;
    if(isempty())
        cout << "No orders to display" << endl;
    else
    {
        temp = front;
        while(temp!=rear)
        {
            cout << "\t" << order[temp];
            temp = (temp+1) % size;
        }
        cout << "\t" << order[temp];
    }
}

int main()
{
    pizza p;
    int ch, ch1, nop;
    char ans;

    do
    {
        cout << "Welcome to Pizza Parlor. Each pizza here costs Rs. 100/-" << endl;   
        cout << "1)Place order\n2)Make Payment\n3)View Order" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter element:  ";
                cin >> ch1;
                p.accept(ch1);
                break;
            case 2:
                p.deliver();
                break;
            case 3:
                p.display();
                break;
        }
        cout << "\nEnter Y to continue: ";
        cin >> ans;
    } while(ans=='Y' || ans=='y');
    return 0;
}
