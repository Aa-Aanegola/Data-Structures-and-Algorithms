#include<iostream>
#define long long long

using namespace std;

struct node
{
	long data;
	node *next;
	node *prev;
};

class cqueue
{
	node *front;
	node *middle;
	long n, mid;
public:
	cqueue()
	{
		front = NULL;
		middle = NULL;
		n = 0;
		mid = 0;
	}
	void push(long x);
	void pop();
	void cycle();
	void update_mid();
	void display();
	//void delete_queue();
};

void cqueue::push(long x)
{
	n+=1;
	node *temp = new node; 
    temp->data = x; 
    if (front == NULL)
    { 
    	temp->next = temp;
    	temp->prev = temp;
    	front = temp;
    }
    else
    {
    	temp->next = front->next;
    	front->next->prev = temp;
    	front->next = temp;
    	temp->prev = front;
    	front = temp;

    	if(n == 2)
			middle = front->next;
		else
		{
			if(n % 2 == 0)
				middle = middle->next;
		}
		mid = n/2;
    }
    
}

void cqueue::pop()
{
	node *temp = new node;
	front->prev->next = front->next;
	front->next->prev = front->prev;
	temp = front;
	front = front->prev;
	delete(temp);
	n--;
	if(n == 0)
		front = NULL;
	if(n == 1)
	{
		middle = NULL;
		mid = 0;
	}
	else if(n % 2)
	{	
		middle = middle->prev;
		mid = n/2;
	}
}

void cqueue::cycle()
{
	if(middle == NULL)
		return;
	node *temp = new node;
	temp = middle;
	middle = front;
	front = temp;
	if(n % 2)
		middle = middle->prev;

}

void cqueue::display()
{
	if(n == 0)
		cout<<0<<"\n";
	else
	{
		cout<<n<<"\n";
		node *temp = new node;
		temp = front->next;
		cout << temp->data <<" ";
		temp = temp->next;
		while(temp != front->next)
		{
			cout << temp->data << " ";
				temp = temp->next;
		}
		//cout<<"\n";
		//cout<<"n:"<<n<<" mid:"<<mid<<" \nmidle:"<<middle->data<<" front:"<<front->data<<" rear:"<<rear->data;
		cout<<"\n";
	}
}


/*void cqueue::delete_queue()
{
	while(front != NULL)
		pop();
}*/



int main()
{
	cqueue que;
	long q;
	cin>>q;
	char cho;
	long d;
	while(q--)
	{
		cin>>cho;
		switch(cho)
		{
			case 'a':
				cin>>d;
				que.push(d);
				break;

			case 't':
				que.pop();
				break;

			case 'e':
				que.cycle();
				break;
		}
		//que.display();
	}
	que.display();
	//que.delete_queue();
}