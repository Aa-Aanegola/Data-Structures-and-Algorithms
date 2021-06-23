#include<iostream>

using namespace std;

class node
{
private:
	int data;
	node *next;
public:
	void push(int x);
	void pop();
	void print();
	int top();
}*top;

void node::push(int x)
{
	node *q = new node;
	q->data = x;
	q->next = top;
	top = q;
}

void node::pop()
{
	if(top != NULL)
		top = top->next;
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

int node::top()
{
	return data;
}

int main()
{
	top->push(1);
	top->push(1);
	top->push(1);
	top->push(1);
	top->push(1);
	top->print();
	cout<<top->top()<<"\n\n";
	top->pop();
	top->pop();
	cout<<"\n";
	top->print();
}