#include<iostream>
using namespace std;

struct node
{
	string data;
	struct node *next;
	struct node *down;
	int flag;
};

class general_LL
{
	public:
		string val;
		struct node *root = NULL;
		struct node *t1 = NULL;
		struct node *temp = NULL;
		struct node *temp1 = NULL;
		struct node *temp2 = NULL;
		
		node *create()
		{
			cout << "Enter the name: ";
			cin >> val;
			node *newnode = new (struct node);
			newnode->data = val;
			newnode->down = NULL;
			newnode->next = NULL;
			newnode->flag = 0;
			return newnode;
		}
		
		void insert_book();
		void insert_ch();
		void insert_sec();
		void insert_subsec();
		void display();
};

void general_LL::insert_book()
{
	if(root == NULL)
	{
		t1 = create();
		root = t1;
	}
	else
		cout << "Book not created." << endl;
}

void general_LL::insert_ch()
{
	int c;
	cout << "Enter the number of chapters in book: ";
	cin >> c;
	for(int i=0; i<c; i++)
	{
		t1 = create();
		temp = root;
		if(temp->down == NULL)
		{
			temp->down = t1;
			temp->flag = 1;
		}
		else
		{
			temp = temp->down;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = t1;
		}
	}
}

void general_LL::insert_sec()
{
	int sno, fl;
	string ch_name;
	cout << "Enter the name of chapter in which section is to be entered: ";
	cin >> ch_name;
	temp = root;
	temp = temp->down;
	while(temp != NULL)
	{
		if(temp->data == ch_name)
		{
			fl = 1;
			cout << "Enter the number of sections: ";
			cin >> sno;
			for(int i=0; i<sno; i++)
			{
				t1 = create();
				if(temp->down==NULL)
				{
					temp->down = t1;
					temp->flag = 1;
				}
				else
				{
					temp = temp->down;
					while(temp->next!=NULL)
						temp = temp->next;
					temp->next = t1;
				}
			}
		}
		temp = temp->next;
	}
	if(fl != 1)
		cout << "Invalid chapter entered" << endl;	
}
		
void general_LL::insert_subsec()
{
	int ssno, f2;
	string s_name;
	cout << "Enter name of section where subsection is to be entered: ";
	cin >> s_name;
	temp = root;
	temp = temp->down;
	while(temp != NULL)
	{
		if(temp->flag == 1)
		{
			temp1 = temp->down;
			while(temp1 != NULL)
			{
				if(temp1->data == s_name)
				{
					f2 = 1;
					cout << "Enter number of subsections: ";
					cin >> ssno;
					for(int i=0; i<ssno; i++)
					{
						t1 = create();
						if(temp1->down == NULL)
						{
							temp1->down = t1;
							temp1->flag = 1;
						}
						else
						{
							temp1 = temp1->down;
							while(temp1->next != NULL)
								temp1 = temp1->next;
							temp1->next = t1;
						}
					}
				}
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}
	if (f2 != 1)
		cout << "Invalid section name" << endl;
}
		
	
void general_LL::display()
{
	temp = root;
	cout << "Book Name: " << temp->data << endl;
	temp = temp->down;
	while(temp!=NULL)
	{
		cout << "\tChapter Name: " << temp->data << endl;
		if(temp->flag == 1)
		{
			temp1 = temp->down;
			while(temp1!=NULL)
			{
				cout << "\t\tSection Name: " << temp1->data << endl;
				if(temp1->flag == 1)
				{
					temp2 = temp1->down;
					while(temp2!=NULL)
					{
						cout << "\t\t\tSubsection Name: " << temp2->data << endl;
						temp2 = temp2->next;
					}
				}
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}
}

int main()
{
	int ch;
	char ans;
	general_LL g;
	do
	{
		cout << "---MENU---" << endl;
		cout << "1. Insert Book Name\n2. Insert Chapter Name\n3. Insert Section Name\n4. Enter Subsection Name\n5. Display" << endl;
		cout << "Enter valid choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				g.insert_book();
				break;
			case 2:
				g.insert_ch();
				break;
			case 3:
				g.insert_sec();
				break;
			case 4:
				g.insert_subsec();
				break;
			case 5:
				g.display();
				break;
		}
		cout << "Enter Y to continue: ";
		cin >> ans;
	}while(ans=='Y'||ans=='y');
	return 0;
}