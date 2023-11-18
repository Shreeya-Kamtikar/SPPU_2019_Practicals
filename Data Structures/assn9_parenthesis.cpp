#include<iostream>
using namespace std;

class STACK
{
    char st[20];
    int top;
    public:
    void pop();
    void push(char a);
    void data();
};

void STACK::pop()
{
    top--;
}

void STACK::push(char a)
{
    top++;
    st[top]=a;
}

void STACK::data()
{
    char ex[20];
    int i=0;
    top=-1;
    cout<<"Enter the expression: ";
    cin>>ex;
    cout<<endl;
    int counter = 0;
    for (int i = 0; ex[i]; i++)
    	counter++;
    while(i<counter)
    {
    	if((ex[i]=='{')||(ex[i]=='[')||(ex[i]=='('))
    	{
    	    push(ex[i]);
    	}
    	if(ex[i]=='}')
    	{
    	    if(st[top]=='{')
    	    pop();
    	}
    	if(ex[i]==']')
    	{
    		if(st[top]=='[')
    		pop();
    	}
   		if(ex[i]==')')
    	{
    		if(st[top]=='(')
    		pop();
    	}
    		i++;
    }
    if(top==-1)
    {
        cout<<"The given expression is well paranthesized!";
    }
    else
    {
        cout<<"The given expression is NOT paranthesized!";
    }
}
int main()
{
	STACK s1;
	s1.data();
}

