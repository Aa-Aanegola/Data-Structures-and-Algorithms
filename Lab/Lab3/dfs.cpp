#include<vector>
#include<iostream>

using namespace std;

vector<int> G[1000];
int vis[1000];

void dfs(int node)
{
	vis[node] = 1;
	for(int i = 0; i<G[node].size(); i++)
	{
		if(vis[G[node][i]] == 0)
		{
			dfs(G[node][i]);
		}
	}
}

int main()
{
	int n,e;
	cin >> n >> e;
	for(int i = 0; i<e; i++)
	{
		int a,b;
		cin>> a >> b;
		G[a].push_back(b);
		if(b!=a)
			G[b].push_back(a);
	}
}