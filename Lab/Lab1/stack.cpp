#include<iostream>


using namespace std;

class Stack
{
private:
	int data[10];
public:
	int top;
	Stack()
	{
		top = -1;
	}
	void push(int a);
	void pop();
	void print();
}S;

void Stack::push(int a)
{
	if(top == 10)
		cout<<"Overflow\n";
	else
		data[top++] = a;
}

void Stack::pop()
{
	if(top == -1)
		cout<<"Empty stack\n";
	else
		top--;
}

void Stack::print()
{
	int temp = top;
	while(temp != -1)
		cout<<data[--temp]<<"\n";
}

int main()
{
	S.push(1);
	S.push(2);
	S.push(9);
	S.push(4);
	S.push(8);
	S.push(3);
	S.push(2);
	S.push(2);
	//S.push(2);
	//S.push(2);
	//S.push(2);
	//S.push(2);
	S.print();
	cout<<"\n";
	S.pop();
	S.pop();
	S.print();
}