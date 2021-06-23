#include <iostream>
#include <vector>
#include <cstring>
#include <string>
//#include <queue>
//#include <deque>
//#include <stack>
#include <algorithm>
#include <cmath>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>

#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(), a.end()
#define ql queue<long>
#define sl stack<long>
#define MAX (long)(1e8)
#define INF (long)(1e18)
#define MOD (long)(1e9+7)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define Set set<long, greater<long>>


using namespace std;

long power(long mult, long pow, long mod);

struct node
{
	node* child[2];
	node* par;
	int count;
	bool full;
	node()
	{
		child[0] = NULL;
		child[1] = NULL;
		par = NULL;
		count = 0;
		full = false;
	}
};

class Trie
{
	node* root;
	int xor_val;

public:
	Trie()
	{
		root = new node;
		xor_val = 0;
	}
	void insert(int x);
	void del(int x);
	void XOR(int x);
	long retxor()
	{
		return xor_val;
	}
	long findmin();
};


void Trie::insert(int x)
{
	vector<int> t;
	while(x > 0)
	{
		t.pb(x%2);
		x >>= 1;
	}
	while(t.size() < 30)
		t.pb(0);
	reverse(all(t));


	node *temp = root;
	for(auto i : t)
	{
		if(temp->child[i] == NULL)
		{
			temp->child[i] = new node;
			temp->child[i]->par = temp;
		}
		temp = temp->child[i];
	}
	temp->full = true;
	temp->count += 1;

	while(temp->par != NULL)
	{
		temp = temp->par;
		if(temp->child[0] == NULL || temp->child[1] == NULL)
			break;
		else
			temp->full = temp->child[0]->full && temp->child[1]->full;
	}
}


void Trie::del(int x)
{
	vector<int> t;
	while(x > 0)
	{
		t.pb(x%2);
		x >>= 1;
	}
	while(t.size() < 30)
		t.pb(0);
	reverse(all(t));

	node *temp = root;
	for(auto i : t)
		temp = temp->child[i];

	temp->count -= 1;

	if(temp->count == 0)
	{
		temp->full = false;
		while(temp->par != NULL)
		{
			temp = temp->par;
			temp->full = false;
		}
	}
}

long Trie::findmin()
{
	long x = xor_val;
	vector<int> t;
	while(x > 0)
	{
		t.pb(x%2);
		x >>= 1;
	}
	while(t.size() < 30)
		t.pb(0);
	reverse(all(t));

	node *temp = root;
	bool flag = false;
	vector<int> min;

	for(auto i : t)
	{
		if(flag)
		{
			min.pb(i);
			continue;
		}
		if(temp->child[i] == NULL)
		{
			flag = true;
			min.pb(i);
		}
		else
		{
			if(temp->child[i]->full)
			{
				int noti = (i?0:1);
				if(temp->child[noti] == NULL)
				{
					flag = 1;
					min.pb(noti);
				}
				else
				{
					min.pb(noti);
					temp = temp->child[noti];
				}
			}
			else
			{
				min.pb(i);
				temp = temp->child[i];
			}
		}
	}

	reverse(all(min));
	int res = 0;
	//for(auto i : min)
	//	cout << i;
	//cout << "\n";
	for(int i = 0; i<30; i++)
		res += min[i] << i;
	//cout << res << " ";
	return res^xor_val;

}



void Trie::XOR(int x)
{
	xor_val ^= x;
}


int main()
{
	Trie T;
	int n, q, temp;
	cin >> n >> q;
	vector<int> arr;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		arr.pb(temp);
		T.insert(temp);
	}

	long res = 1, finpow = 0;
	int code, a, b;
	while(q--)
	{
		cin >> code;
		if(code == 1)
		{
			cin >> a;
			T.XOR(a);
		}
		else
		{
			cin >> a >> b;
			a--;
			T.del(arr[a]);
			T.insert(b^T.retxor());
			arr[a] = b^T.retxor();
		}
		finpow = T.findmin();
	//	cout << finpow;
		res *= power(MAX, finpow, MOD);
		res %= MOD;
	}

	cout << res << "\n";
}



// Helper functions
long power(long mult, long pow, long mod = MOD)
{
	long res = 1;
	while(pow > 0)
	{
		if(pow&1)
		{
			res *= mult;
			res %= mod;
		}
		mult *= mult;
		mult %= mod;

		pow >>= 1;
	}
	return res%mod;
}