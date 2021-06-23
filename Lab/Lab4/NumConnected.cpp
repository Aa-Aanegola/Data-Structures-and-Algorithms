#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[100005];
int vis[100005];

void dfs(int x)
{
	vis[x] = 1;
	for(int i = 0; i<graph[x].size();i++)
		if(!vis[graph[x][i]])
			dfs(graph[x][i]);
}


int count_connected(int n)
{
	int count = 0;
	for(int i = 0; i<100005; i++)
		vis[i] = 0;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			count++;
			dfs(i);
		}
	}
	return count;
}



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		for(int i = 0; i<100000; i++)
			graph[i].clear();
		int n,e;
		cin >> n >> e;
		int tem = e;
		int a,b;
		while(tem--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			if(a != b)
				graph[b].push_back(a);
		}
		cout<<count_connected(n)<<"\n";
	}
}