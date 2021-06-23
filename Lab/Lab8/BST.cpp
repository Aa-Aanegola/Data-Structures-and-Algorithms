#include<bits/stdc++.h>
#define long long long
#define INF (long)1e16


using namespace std;


struct node
{
	long data;
	node *lc, *rc;
};

class BST
{
	node *root;
public:
	BST()
	{
		root = NULL;
	}
	bool del(long data);
	void insert(long data);
	bool search(long data);
	long search_successor(long data);
	void inorder_traversal(node *n);
	void postorder_traversal(node *n);
	void preorder_traversal(node *n);
	node *getroot()
	{
		return root;
	}
};

void BST::insert(long data)
{
	node *temp, *prevtemp = NULL;
	temp = root;
	while(temp != NULL)
	{
		prevtemp = temp;
		if(data < temp->data)
			temp = temp->lc;
		else if(data > temp->data)
			temp = temp->rc;
		else
			return;
	}

	node *insertee = new node;
	insertee->data = data;
	insertee->lc = NULL;
	insertee->rc = NULL;
	if(prevtemp == NULL)
		root = insertee;
	else
	{
		if(prevtemp->data < insertee->data)
			prevtemp->rc = insertee;
		else
			prevtemp->lc = insertee;
	}
}


bool BST::search(long data)
{
	node *temp = root;
	while(temp != NULL)
	{
		if(data < temp->data)
			temp = temp->lc;
		else if(data > temp->data)
			temp = temp->rc;
		else
			return true;
	}
	return false;
}

long BST::search_successor(long data)
{
	long suc = INF;
	node *temp = root;
	while(temp != NULL)
	{
		if(suc > temp->data && data < temp->data)
			suc = temp->data;
		if(data <= temp->data)
			temp = temp->lc;
		else
			temp = temp->rc;

	}
	if(suc == INF)
		return -1;	
	return suc;	
}


bool BST::del(long data)
{
	node *temp = new node;
	temp =root; 
	node *prevtemp;
	while(temp != NULL)
	{
		if(temp->data == data)
			break;
		prevtemp = temp;
		if(data < temp->data)
			temp = temp->lc;
		else
			temp = temp->rc;
	}
	if(temp == NULL)
		return false;
	
	if(temp->lc == NULL && temp->rc == NULL)
	{
		if(prevtemp->lc == temp)
			prevtemp->lc = NULL;
		else
			prevtemp->rc = NULL;
		free(temp);
		return true;
	}
	
	if(temp->lc == NULL)
	{
		prevtemp->rc = temp->rc;
		free(temp);
		return true;
	}

	if(temp->rc == NULL)
	{
		prevtemp->lc = temp->lc;
		free(temp);
		return true;
	}

	node *temp2 = new node;
	temp2 = temp->rc;
	while(temp2->lc != NULL)
		temp2 = temp2->lc;

	temp->data = temp2->data;
	temp->rc = temp2->rc;
	free(temp2);
	return true;
}


void BST::inorder_traversal(node *n)
{
	if(n == NULL)
		return;
	inorder_traversal(n->lc);
	cout << n->data << " ";
	inorder_traversal(n->rc);
}



void BST::preorder_traversal(node *n)
{
	if(n == NULL)
		return;
	cout << n->data << " ";
	inorder_traversal(n->lc);
	inorder_traversal(n->rc);
}


void BST::postorder_traversal(node *n)
{
	if(n == NULL)
		return;
	inorder_traversal(n->lc);
	inorder_traversal(n->rc);
	cout << n->data << " ";
}


int main()
{
	BST b;
	b.insert(10);
	b.insert(7);
	b.insert(4);
	b.insert(8);
	b.insert(20);
	b.insert(14);
	b.insert(13);
	b.insert(30);
	b.insert(16);
	b.insert(31);
	b.insert(54);
	b.insert(1);
	b.insert(2);
	b.insert(9);
	//b.del(7);
	b.inorder_traversal(b.getroot());
	cout << "\n";
	b.preorder_traversal(b.getroot());
	cout << "\n";
	b.postorder_traversal(b.getroot());
	cout << "\n";
	cout << b.search_successor(4) << "\n";
}