#include<iostream>
#include<string.h>

using namespace std;

struct Node
{
	int rno;
	char name[20];
	Node *next;
}*start;

void insert(int rno, char name[])
{
	if(start == NULL)
	{
		Node *q = new Node;
		q->rno = rno;
		strcpy(q->name,name);
		q->next = NULL;
		start = q;
	}
	else
	{
		Node *q = new Node;
		q = start;
		while(q->next != NULL)
		{
			q = q->next;
		}
		Node *temp = new Node;
		temp->rno = rno;
		strcpy(temp->name,name);
		q->next = temp;
	}
}

void print(int x)
{
	Node *temp = start;
	while(temp != NULL)
	{
		if(temp->rno%x == 0)
		{
			cout<<"Name:\t"<<temp->name<<"\n";
			cout<<"Roll number:\t"<<temp->rno<<"\n";
		}
		temp = temp->next;
	}
}

void del(int x)
{
	if(start->rno == x)
	{
		start = start->next;
		return;
	}
	Node *temp = new Node, *t2 = new Node;
	temp = start;
	t2 = start->next;
	while(t2 != NULL)
	{
		if(t2->rno == x)
		{
			cout<<"Found.\n";
			temp->next = t2->next;
			delete t2;
			break;
		}
		t2 = t2->next;
		temp = temp->next;
	}
}


int main()
{
	char a[20] = "Aakash";
	insert(1,a);
	insert(2,a);
	insert(3,a);
	print(1);
	cout<<"\n\n";
	del(2);
	print(1);
}