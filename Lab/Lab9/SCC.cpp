#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define INF (long)1e15
#define MOD (long)(1e9 + 7)


using namespace std;

int pos, vis[1000], visrev[1000];
stack<int> sorted;
vector<int> graph[1000];
vector<int> revgraph[1000];

void dfs(int node)
{
	vis[node] = 1;

	for(int i = 0; i<graph[node].size(); i++)
	{
		if(!vis[graph[node][i]])
			dfs(graph[node][i]);
	}

	sorted.push(node);
	pos--;
}

void dfsrev(int node)
{
	if(node != 0)
		cout << node << " ";
	visrev[node] = 1;

	for(int i = 0; i<graph[node].size(); i++)
	{
		if(!visrev[revgraph[node][i]])
			dfsrev(revgraph[node][i]);
	} 
}

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i<1000; i++)
	{
		vis[i] = 0;
		visrev[i] = 0;
	}

	for(int i = 0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		revgraph[y].push_back(x);
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

	while(!sorted.empty())
	{
		int i = sorted.top();
		sorted.pop();

		if(!visrev[i])
		{
			visrev[i] = 1;
			dfsrev(i);
			cout << "\n";
		}
	}

	return 0;
}