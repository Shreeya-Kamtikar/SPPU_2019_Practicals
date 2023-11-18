#include<iostream>
using namespace std;

int top = -1;
int top1 = -1;
int top2 = -1;

struct tree
{
	char data;
	tree *left;
	tree *right;
};

class stack
{
	public:
		tree *root = NULL;
		int count, j;
		tree *st0[10];
		tree *st1[10];
		tree *st2[10];
		string exp;
		
		void push(tree *root);
		void push1(tree *root);
		void push2(tree *root);
		
		tree *pop()
		{
			tree *ptr = st0[top];
			top--;
			return ptr;
		}
		void pop1();
		void pop2();
		
		tree *create(char info)
		{
			tree *newnode = new (struct tree);
			newnode->data = info;
			newnode->left = NULL;
			newnode->right = NULL;
			return newnode;
		}
		void inorder(tree *root);
		void postorder(tree *root);
		void non_rec_postorder(tree *root);
		void deltree(tree *root);
		void process();
};

void stack::push(tree *root)
{
	top++;
	st0[top] = root;
}

void stack::push1(tree *root)
{
	top1++;
	st1[top1] = root;
}

void stack::push2(tree *root)
{
	top2++;
	st2[top2] = root;
}

void stack::pop1()
{
	top1--;
}

void stack::pop2()
{
	top2--;
}

void stack::inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

void stack::postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}

void stack::non_rec_postorder(tree *root)
{
	if(root==NULL)
		return;
	push1(root);
	tree *ntr;
	while(top1 != -1)
	{
		ntr = st1[top1];
		pop1();
		push2(ntr);
		if(ntr->left)
			push1(ntr->left);
		if(ntr->right)
			push1(ntr->right);
	}
	while(top2 != -1)
	{
		ntr = st2[top2];
		pop2();
		cout << ntr->data;
	}
}

void stack::deltree(tree *root)
{
	if(root!=NULL)
	{
		deltree(root->left);
		deltree(root->right);
		cout <<"\nDeleted data is: " << root->data << endl;
		delete root;
	}
}

void stack::process()
{
	cout << "\nEnter the prefix expression: ";
	cin >> exp;
	count = 0;
	for(int i=0;exp[i];i++)
		count++;
	j = count - 1;
	while(j>=0)
	{
		if(exp[j]>='a'&&exp[j] <='z')
		{
			tree *node = create(exp[j]);
			push(node);
		}
		else		//for operators
		{
			tree *t1 = pop();
			tree *t2 = pop();
			tree *newnode2 = create(exp[j]);
			newnode2->left = t1;
			newnode2->right = t2;
			push(newnode2);
		}
		j--;
	}
	
	//for display
	tree *newnode1 = pop();
	cout << "\nRecursive inorder: ";
	inorder(newnode1);
	cout << "\nRecursive postorder: ";
	postorder(newnode1);
	cout << "\nNon-recursive postorder: ";
	non_rec_postorder(newnode1);
	deltree(newnode1);
}

int main()
{
	stack s;
	s.process();
	return 0;
}