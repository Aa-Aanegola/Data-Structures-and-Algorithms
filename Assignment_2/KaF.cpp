#include<iostream>
#include<vector>
#define long long long
#define m 1000000007

using namespace std;

struct pa
{
	long to;
	long weight;
};

vector<pa> graph[100005];
int vis[100005];
long ans,subtree[100005];
int n, c1, c2;
long  arr[100005];

void dfs0(long node, long cost, long parent)
{
	if(arr[node] == 0)
		subtree[node] = 1;
	for(int i = 0; i<graph[node].size(); i++)
	{
			long next = graph[node][i].to;
			long weight = graph[node][i].weight;
			if(next != parent)
			{
				dfs0(next, weight, node);
				subtree[node] += subtree[next];
			}
	}
	ans = ((((c2-subtree[node])%m) * (subtree[node]%m)) * (cost%m)) + ans%m;
	ans %= m;
}

void dfs1(long node, long cost, long parent)
{
	if(arr[node] == 1)
		subtree[node] = 1;
	for(int i = 0; i<graph[node].size(); i++)
	{
			long next = graph[node][i].to;
			long weight = graph[node][i].weight;
			if(next != parent)
			{
				dfs1(next, weight, node);
				subtree[node] += subtree[next];
			}
	}
	ans = ((((c1-subtree[node])%m) * (subtree[node]%m)) * (cost%m)) + ans%m;
	ans %= m;
}


int main()
{
	cin >> n;
	pa t;
	for(int i = 0; i<100005; i++)
		subtree[i] = 0,arr[i] = 0, vis[i] = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		if(arr[i])
			c1++;
		else
			c2++;
	}

	for(int i = 0; i<n-1; i++)
	{
		long a,b,c;
		cin >> a >> b >> c;
		t.to = b;
		t.weight = c;
		graph[a].push_back(t);
		t.to = a;
		graph[b].push_back(t);
	}
	dfs0(1,0,-1);
	for(int i = 0; i<100005; i++)
		subtree[i] = 0, vis[i] = 0;
	dfs1(1,0,-1);
	cout<<ans<<"\n";
	//display(n);
}