#include<iostream>

using namespace std;
 
class Node
{
    public:
    string word;
    string meaning;
    Node *left;
    Node *right;
    int height;
};
 
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    if(a > b)
    	return a;
    else
    	return b;			    
}
 
Node *newNode(string word,string meaning)
{
    Node *node = new Node();
    node->word = word;
    node->meaning = meaning;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node *node,string word,string meaning)
{
    if (node == NULL)
        return(newNode(word,meaning));
        
    if (word < node->word)
        node->left = insert(node->left, word,meaning);
    else if (word > node->word)
        node->right = insert(node->right, word,meaning);
    else 
        return node;
 
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && word < node->left->word)		//Right rotation
        return rightRotate(node);
 
    if (balance < -1 && word > node->right->word)	// Left Rotation
        return leftRotate(node);
 
    if (balance > 1 && word > node->left->word)		//LR Rotation
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && word < node->right->word)	//RL Rotation
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
 
void postOrder(Node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->word << " ->"<<root->meaning<<"\n";
    }
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
    	cout << root->word << " ->"<<root->meaning<<"\n";
        inOrder(root->right);
	}
}

Node * minValueNode(Node* node)
{
    Node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
Node* deleteNode(Node* root, string word)
{
     
    if (root == NULL)
        return root;

    if ( word < root->word )
        root->left = deleteNode(root->left, word);

    else if( word > root->word )
        root->right = deleteNode(root->right, word);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ? root->left : root->right;
 
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
            *root = *temp; 
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);

            root->word = temp->word;

            root->right = deleteNode(root->right, temp->word);
        }
    }

    if (root == NULL)
    return root;
 
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
 
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

void update(Node *root,string word)
{
    if(root != NULL)
    {
        if(root->word==word)
        {
            cout<<"Enter new meaning: ";
            cin>>root->meaning;
            return;
        }
        update(root->left,word);
        update(root->right,word);
    }
}

// Driver Code
int main()
{
    Node *root = NULL;
    int choice=99;
    string entry;
    string value;
    while (choice!=5)
    {
        cout<<"\nMenu"<<endl;
        cout<<"1. Insert node"<<endl;
        cout<<"2. Delete node"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Update"<<endl;
        cout<<"5. Exit"<<endl; 
        cout << "Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the number of words you want to enter"<<"\n";
                int no;
                cin>>no;
                
                for (int i=0;i<no;i++)
                {
                    cout<<"Enter word: ";
                    cin>>entry;
                    cout<<"Enter its meaning: ";
                    cin>>value;
                    root=insert(root,entry,value);
                }
                break;
            }
            case 2:
            {
                cout<<"Enter the word you want to delete: ";
                cin>>entry;
                deleteNode(root,entry);
                cout<<"Deleted successfully"<<"\n";
                break;
            }
            case 3:
            {
                inOrder(root);
                cout << endl;
                postOrder(root);                
                break;
            }
            case 4:
            {
                cout<<"Enter the word you want to update: ";
                cin>>entry;
                update(root,entry);
                break;
            }
            case 5:
            {
                return 0;
            }
        }
    }
    return 0;
}