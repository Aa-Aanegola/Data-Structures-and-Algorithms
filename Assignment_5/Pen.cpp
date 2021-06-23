#include <iostream>
#include <vector>
#include <cstring>
#include <string>
//#include <queue>
//#include <deque>
//#include <stack>
#include <algorithm>
#include <cmath>
#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(), a.end()
#define ql queue<long>
#define sl stack<long>
#define MAX (long)(1e6+5)
#define INF (long)(1e18)
#define MOD (long)(1e9+7)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#define Set set<long, greater<long>>


using namespace std;


long pow(long mult, long pow, long mod);

string master, str;

struct node
{
	node* children[26];
	bool isLeaf;
};

class Trie
{
public:
	node *root;

	Trie()
	{
		root = new node;
		for(int i = 0; i<26; i++)
			root->children[i] = NULL;
	}

	void insert();
	long count();
};


void Trie::insert()
{
	node *temp = root;

	for(int i = 0; i<str.length(); i++)
	{
		//cout << "here";
		int x = str[i] - 'a';
		if(temp->children[x] == NULL)
		{
			temp->children[x] = new node;
			temp = temp->children[x];
			for(int j = 0; j<26; j++)
				temp->children[j] = NULL;
		}
		else
			temp = temp->children[x];
	}
}


long Trie::count()
{
	vector<pl> finish;
	
	for(int i = 0; i<master.length(); i++)
	{
		node *temp = root;
		long end = i;
		while(1)
		{
			int x = master[end] - 'a';
			if(temp->children[x] == NULL)
				break;
			temp = temp->children[x];
			end += 1;
			if(end == master.size())
				break;
		}
		if(end != i)
			finish.pb({i, end-1});
	}

	//for(auto i : finish)
	//	cout << i.ff << " " << i.ss << "\n";

	pl target = {0, master.length()-1};
	long cost = 0, counter = 1;

	if(finish[0].ff != 0)
		return -1;

	int i = 0;
	while(target.ff <= target.ss)
	{
		pl best = {-1, -1};
		while(i < finish.size() && finish[i].ff <= target.ff)
		{
			if(best.ff == -1 || finish[i].ss > best.ss)
			{
				best = finish[i];
				//cout << best.ff << " " << best.ss << "\n";
			}
			i++;
		}
		if(best.ff == -1)
			return -1;
		cost++;
		target.ff = best.ss+1;
		//cout << "target: " << target.ff << " " << target.ss << "\n";
	}

 	return cost;
}


int main()
{
	fastio;

    int t = 1;
    //cin >> t;

    while(t--)
    {
    	Trie T;
    	cin >> master;
    	int n;
    	cin >> n;
    	while(n--)
    	{
    		cin >> str;
    		T.insert();
    	}

    	cout << T.count() << "\n";

    }

	return 0;
}



// Helper functions
long pow(long mult, long pow, long mod = MOD)
{
	long res = 1;
	while(pow > 0)
	{
		if(pow&1)
		{
			res *= mult;
			res %= mult;
		}
		mult *= mult;
		mult %= mult;
	}
	return res;
}