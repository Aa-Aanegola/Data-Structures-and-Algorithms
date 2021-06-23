#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define INF (long)1e15
#define MOD (long)(1e9 + 7)


using namespace std;

int pos, sorted[1000], vis[1000];
vector<int> graph[1000];

void dfs(int node)
{
	vis[node] = 1;

	for(int i = 0; i<graph[node].size(); i++)
	{
		if(!vis[graph[node][i]])
			dfs(graph[node][i]);
	}

	sorted[pos] = node;
	pos--;
}


int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i<1000; i++)
		vis[i] = 0;

	for(int i = 0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	pos = n-1;

	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(i);
		}
	}

	int ans = 0, count = n-1;
	for(int i = 0; i<n-1; i++)
	{
		ans += count - graph[sorted[i]].size();
		count--;
	}

	cout << ans << "\n";

	return 0;
}