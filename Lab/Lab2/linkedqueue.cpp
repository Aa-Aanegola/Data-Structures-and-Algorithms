#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Queue
{
private:
	Node *f, *r;
public:
	Queue()
	{
		f = NULL;
		r = NULL;
	}
	void push(int x);
	void pop();
	void print();
};


void Queue::push(int x)
{
	Node *temp = new Node;
	if(r == NULL)
	{
		temp->data = x;
		temp->next = NULL;
		f = temp;
		r = temp;
	}
	else
	{
		temp->data = x;
		r->next = temp;
		r = temp;
		r->next = NULL;
	}
}

void Queue::pop()
{
	Node *tem = new Node;
	tem = f;
	if(f == NULL)
		printf("Queue empty\n");
	else
		f = f->next;
	delete tem;
}

void Queue::print()
{
	Node *tem = f;
	cout<<"Queue: ";
	while(tem != NULL)
	{
		int x = tem->data;
		cout<<x<<" ";
		tem = tem->next;
	}
	cout<<"\n";
}




int main()
{
	Queue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.print();
	Q.pop();
	Q.print();
	Q.push(4);
	Q.print();
	Q.pop();
	Q.pop();
	Q.pop();
	Q.pop();
}