#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left = NULL;
	struct tree *right = NULL;
};

class BST
{
	int total, actual;
	int max,min;
	public:
	struct tree *root;
	BST()
	{
		root = NULL;
	}
   
	tree *create(int num)
	{
		tree *newnode = new tree();
		newnode->data = num;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	tree *insert(tree *temp,int num)
	{
		if(temp==NULL)
			temp = create(num);
		else if(temp->data > num)
			temp->left = insert(temp->left,num);
		else
			temp->right = insert(temp->right,num);
		return temp;
	}
   
	void input()
	{
		cout << "Enter the number of elements in tree: ";
		cin >> total;
		for(int i=0; i<total;i++)
		{
			cout << "Enter actual value: ";
			cin >> actual;
			root = insert(root,actual);
		}
	}
   
	void inorder (struct tree *temp)
	{
   		if (temp!=NULL)
   		{
   			inorder(temp->left);
   			cout<<temp->data<<"\t";
   			inorder(temp->right);
   		}
    }

    void preorder (struct tree *temp)
    {
   		if (temp!=NULL)
   		{
   			cout<<temp->data<<"\t";
   			preorder(temp->left);
   			preorder(temp->right);
   		}
    }

    void postorder (struct tree *temp)
    {
   		if (temp!=NULL)
   		{
   			postorder(temp->left);
   			postorder(temp->right);
   		 	cout<<temp->data<<"\t";
   	 	}
    }
    
	void display()
	{
		cout<<"inorder traversal:"<<"\t";
		inorder(root);
		cout<<endl;
		cout<<"preorder traversal:"<<"\t";
		preorder(root);
		cout<<endl;
		cout<<"postorder traversal:"<<"\t";
		postorder(root);
		cout<<endl;
    }    

    void search(tree *temp,int val)
    {
		if(temp!=NULL)
		{
			if(temp->data == val)
				cout << "Value found" << endl;
			else if(val < temp->data)
				search(temp->left,val);
			else
				search(temp->right,val);
   	 }
   	 else
		cout << "Value not found" << endl;
    }

    void maxval()
    {
    	tree *temp;
    	int max;
		temp=root;
		while(temp->right != NULL)
		{
			max = temp->data;
			temp = temp->right;
			if(temp->data > max)
				max = temp->data;
			else
				temp = temp->right;
		}
		cout << "Maximum value is: " << max << endl;
    }

    void minval()
    {
    	tree *temp;
    	int min;
		temp = root;
		while(temp->left != NULL)
		{
			min = temp->data;
			temp = temp->left;
			if(temp->data < min)
				min = temp->data;
			else
				temp = temp->left;
		}
		cout << "Minimum value is: " << min << endl;
    }

    int depth(tree *root)
    {
    	if(root==NULL)
    		return 0;
    	else
    	{
    		if(depth(root->right)>depth(root->left))
    			return depth(root->right)+1;
    		else
    			return depth(root->left)+1;
		}
    }

    void mirror(tree *temp)
    {
   		if(temp == NULL)
   			return;
   		else
   		{
   			tree *ptr;
   		 	ptr = temp->left;
   			temp->left = temp->right;
   			temp->right = ptr;
   			mirror(temp->left);
   			mirror(temp->right);
   	 	}
    }
};
   
int main()
{
    int val;
    BST b;
    b.input();
    b.display();
    cout<<"Enter value to be searched: ";
    cin>>val;
    b.search(b.root,val);
    b.minval();
    b.maxval();
    cout << "Depth of tree is: " << b.depth(b.root);
    b.mirror(b.root);
    cout<<"\ninorder mirror: ";
    b.inorder(b.root);
    cout<<endl;
    cout<<"preorder mirror: ";
    b.preorder(b.root);
    cout<<endl;
    cout<<"postorder mirror: ";
    b.postorder(b.root);
    cout<<endl;
    return 0;
}