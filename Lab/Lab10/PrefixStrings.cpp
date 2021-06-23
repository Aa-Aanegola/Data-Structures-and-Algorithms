#include<bits/stdc++.h>


using namespace std;

char str[21];
int c;

struct node
{
	node *children[26];
	bool isLeaf;
};


class Trie
{
public:
	node *root;

	Trie()
	{
		for(int i = 0; i<26; i++)
			root->children[i] = NULL;
		root->isLeaf = false;
	}

	void insert()
	{
		node *temp = root;
		for(int i = 0; i<strlen(str); i++)
		{
			int x = str[i] - 'a';
			if(temp->children[x] == NULL)
			{
				temp->children[x] = new node;
				temp = temp->children[x];

				for(int j = 0; j<26; j++)
					temp->children[j] = NULL;
				temp->isLeaf = false;			
			}
			else
				temp = temp->children[x];
		}
		temp->isLeaf = true;
	}
	void search()
	{
		c = 0;
		node *temp = root;
		for(int i = 0; i<strlen(str); i++)
		{
			int x = str[i] - 'a';
			temp = temp->children[x];
		}
		dfs(temp);
		cout << c << "\n";
	}

	void dfs(node *start)
	{
		if(start->isLeaf)
			c += 1;

		for(int i = 0; i<26; i++)
		{
			if(start->children[i] != NULL)
				dfs(start->children[i]);
		}
	}
};


int main()
{
	Trie T;
	int n, q;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> str;
		T.insert();
	}
	cin >> q;
	for(int i = 0; i<q; i++)
	{
		cin >> str;
		T.search();
	}
	return 0;
}