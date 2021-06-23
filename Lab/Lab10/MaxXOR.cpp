#include<bits/stdc++.h>
#define long long long

using namespace std;

int n;
long arr[100005];

struct node
{
	node *children[2];
	bool isLeaf;
};

class Trie
{
public:
	node *root;
	Trie()
	{
		root->children[0] = NULL;
		root->children[1] = NULL;
		root->isLeaf = false;
	}
	void insert(long data)
	{
		string s = "";
		while(1)
		{
			s.push_back(data%2 + '0');
			data/=2;
			if(data == 0)
				break;
		}
		for(int i = s.length(); i<31; i++)
			s.push_back('0');
		reverse(s.begin(), s.end());
		node *temp = new node;
		temp = root;
		for(auto i : s)
		{
			int x = i - '0';
			if(temp->children[x] == NULL)
			{
				temp->children[x] = new node;
				temp = temp->children[x];
				temp->children[0] = NULL;
				temp->children[1] = NULL;
				temp->isLeaf = false;
			}
			else
				temp = temp->children[x];
			
		}
		temp->isLeaf = true;
	}
	void Search()
	{
		int max = -1;

		for(int i = 0; i<n; i++)
		{
			long data = arr[i];
			string s = "";
			string res = "";
			while(1)
			{
				s.push_back(data%2 + '0');
				data/=2;
				if(data == 0)
					break;
			}
			for(int i = s.length(); i<31; i++)
				s.push_back('0');
			reverse(s.begin(), s.end());
			
			node *temp = new node;
			temp = root;

			for(auto i : s)
			{
				int notx, x = i - '0';
				if(x)
					notx = 0;
				else
					notx = 1;
				if(temp->children[notx] != NULL)
				{
					res.push_back('1');
					temp = temp->children[notx];
				}
				else
				{
					res.push_back('0');
					temp = temp->children[x];
				}
			}

			reverse(res.begin(), res.end());
			long mult = 1;
			long ans = 0;
			
			for(auto i : res)
			{
				if(i-'0')
					ans += mult;
				mult *= 2;
			}
			if(ans > max)
				max = ans;
		}
		cout << max << "\n";
	}
};


int main()
{
	Trie T;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		T.insert(arr[i]);
	}
	T.Search();
	return 0;
}