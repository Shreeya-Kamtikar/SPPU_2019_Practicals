#include<iostream>
using namespace std;
#define MAX 5

class dequeue
{
	int front, rear;
	int queue[MAX];
	int temp;
	public:
		dequeue();
		void insertf();
		void insertr();
		void delf();
		void delr();
		void display();
		int isfull();
		int isempty();
};

dequeue::dequeue()
{
	front = rear = -1;
}

int dequeue::isempty()
{
	if (front==-1)
		return 1;
	return 0;
}

int dequeue::isfull()
{
	if(front==0 && rear==(MAX-1) || front==(rear+1)%MAX)
		return 1;
	return 0;
}

void dequeue::insertf()
{
	int f;
	if(isfull())
		cout << "Queue is full" << endl;
	else
	{
		cout << "Enter element to be inserted at front: ";
		cin >> f;
		if(front==-1)
			front = rear = 0;
		else
			front = (front-1+MAX)%MAX;
		queue[front] = f;
	}
}

void dequeue::insertr()
{
	int r;
	if(isfull())
		cout << "Queue is full" << endl;
	else
	{
		cout << "Enter element to be inserted at end: ";
		cin >> r;
		if(front==-1)
			front = rear = 0;
		else
			rear = (rear+1)%MAX;
		queue[rear] = r;
	}
}

void dequeue::delf()
{
	if (isempty())
		cout << "No element to be deleted" << endl;
	else
	{
		cout << "Deleted element is: " << queue[front];
		if(front==rear)
			front = rear = -1;
		else
			front = (front+1)%MAX;
	}
}

void dequeue::delr()
{
	if (isempty())
		cout << "No element to be deleted" << endl;
	else
	{
		cout << "Deleted element is: " << queue[rear];
		if(front==rear)
			front = rear = -1;
		else
			rear = (rear-1+MAX)%MAX;
	}
}

void dequeue::display()
{
	if (isempty())
		cout << "Queue is empty" << endl;
	else
	{
		temp = front;
		while(temp!=rear)
		{
			cout << queue[temp] <<"\t\t";
			temp = (temp+1)%MAX;
		}
		cout << queue[temp] << "\t\t";
	}
}

int main()
{
	dequeue d1;
	int ch;
	do
	{
		cout << "\n1)Insert at front\n2)Insert at rear\n3)Delete from front\n4)Delete at rear\n5)Display\n6)Exit" << endl;
		cout << "Enter choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				d1.insertf();
				break;
			case 2:
				d1.insertr();
				break;
			case 3:
				d1.delf();
				break;
			case 4:
				d1.delr();
				break;
			case 5:
				d1.display();
				break;
			case 6:
				cout << "Exiting" << endl;
				break;
		}
	}while(ch<=6);
}