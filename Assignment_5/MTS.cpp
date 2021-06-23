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
#define vp vector<pl>
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
#define Set set<long, greater<long>>


using namespace std;

long power(long mult, long pow, long mod);

vector<vl> graph;
vl size;
long root = 0, ans = 1;

void subtree(long node, long par)
{
	for(auto i : graph[node])
	{
		if(i == par)
			continue;
		
		subtree(i, node);

		size[node] += size[i];
	}
}


void shuffle(long node)
{
	for(auto i : graph[node])
	{
		if(size[root] - size[i] < size[i])
		{
			long temp = size[root];
			size[root] = size[root] - size[i];
			size[i] = temp;
			root = i;
			shuffle(root);
		}

		if(size[root] - size[i] == size[i])
		{
			if(i > root)
			{
				long temp = size[root];
				size[root] = size[root] - size[i];
				size[i] = temp;
				root = i;
				shuffle(root);		
			}
		}
	}
}


int main()
{
	fastio;

    int t = 1;
    cin >> t;

    while(t--)
    {
    	root = 0;
    	ans = 1;
    	int n;
    	cin >> n;
    	long a, b;
    	graph.resize(n);
    	size.resize(n);

    	for(int i = 0; i<n-1; i++)
    	{
    		cin >> a >> b;
    		a--;
    		b--;
    		graph[a].pb(b);
    		graph[b].pb(a);
    	}

    	fill(all(size), 1);
    	subtree(0, -1);

    	/*for(auto i : size)
    		cout << i << " ";
    	cout << "\n";*/

    	shuffle(0);

    	for(int i = 2; i<=n; i++)
    	{
    		ans *= i;
    		ans %= MOD;
    	}

    	//cout << ans << "\n";
    	for(auto i : size)
    	{
    		ans *= power(i, MOD-2, MOD);
    		ans %= MOD;
    	}

    	cout << root+1 << " " << ans << "\n";
    	
    	
    	/*for(auto i : size)
    		cout << i << " ";
    	cout << "\n";*/

    	for(auto i : graph)
    		i.clear();
    	size.clear();
    	graph.resize(0);
    }

	return 0;
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
	return res;
}
