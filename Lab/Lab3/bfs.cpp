#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> G[1000];
int vis[1000];

void bfs()
{
	queue<int> q;
	int source = 1;
	vis[source] = 1;
	q.push(source);
	while(!q.empty())
	{
		int node = q.front();
		cout<<node<<" ";
		q.pop();
		for(int i = 0; i<G[node].size(); i++)
		{
			if(vis[G[node][i]] == 0)
			{
				vis[G[node][i]] = 1;
				q.push(G[node][i]);
			}
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
	bfs();
	cout<<"\n";
}