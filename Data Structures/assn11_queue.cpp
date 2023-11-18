#include<iostream>
using namespace std;
#define size 5

void insert(int x);
void display();
void dele();
int front=-1, rear=-1;
int queue[size];

int main()
{
	int x, ch;
	do
	{
		cout << "\nFollowing operations can be done on queue:" << endl;
		cout << "1)Insert\n2)Display\n3)Delete\n4)Exit" << endl;
		cout << "Enter choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				cout << "Enter value to be entered: ";
				cin >> x;
				insert(x);
				break;
			case 2:
				display();
				break;
			case 3:
				dele();
				break;
			case 4:
				cout << "Exiting process" << endl;
				break;
		}
	}while(ch < 4);
}

void insert(int x)
{
	if(rear >= size-1)
		cout << "Maximum limit reached. Cannot insert element" << endl;
	else
	{
		if(front==-1)
			front = 0;
		rear = rear + 1;
		queue[rear] = x;
	}
}

void dele()
{
	if(front==-1)
		cout << "Queue is empty. Deletion not possible" << endl;
	else
	{
		cout << "Deleted element is: " << queue[front] << endl;
		if(front==rear)
			front = rear = -1;
		else
			front = front + 1;
	}
}

void display()
{
	int i;
	if(front==-1)
		cout <<"Queue is empty" << endl;
	else
	{
		for(i=front; i <= rear; i++)
			cout << queue[i] << "\t";
	}
}
