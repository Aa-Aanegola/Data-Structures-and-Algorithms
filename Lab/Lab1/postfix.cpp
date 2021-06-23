#include<iostream>

using namespace std;

class node
{
private:
	char data;
	node *next;
public:
	void push(int x);
	char pop();
	void print();
	//int top();
}*top;

void node::push(int x)
{
	node *q = new node;
	q->data = x;
	q->next = top;
	top = q;
}

char node::pop()
{
	int x = top->data;
	if(top != NULL)
		top = top->next;
	return x;
}

void node::print()
{
	node *temp = new node;
	temp = top;
	while(temp!= NULL)
	{
		cout<<data<<"\n";
		temp = temp->next;
	}
}



int main()
{
	char exp[100];
	cin>>exp;
	int i = 0,a,b;
	while(exp[i] != '\0')
	{
		if(exp[i] >= '0' && exp[i] <= '9')
			top->push(exp[i]);
		else
		{
			b = top->pop() - '0';
			a = top->pop() - '0';
			cout<<a<<" "<<b<<"\n";
			if(exp[i] == '+')
				top->push(a+b + 48);
			if(exp[i] == '-')
				top->push(a-b + 48);
			if(exp[i] == '*')
				top->push(a*b + 48);
			if(exp[i] == '/')
				top->push(a/b + 48);
		}
		i++;
	}
	int ans = top->pop() - '0';
	cout<<ans<<"\n";
}