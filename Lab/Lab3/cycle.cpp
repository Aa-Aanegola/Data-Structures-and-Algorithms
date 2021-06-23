#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> G[1000];
int vis[1000];

void check_cycle(int node, int parent)
{
	vis[node] = 1;
	int flag = 0;
	for(int i = 0; i<G[node].size(); i++)
	{
		if(vis[G[node][i]] == 0)
			check_cycle(G[node][i],node);
		else
		{
			if(G[node][i] != parent)
			{	
				cout<<"Yes\n";
				flag = 1;
				break;
			}
		}
	}
	if(flag)
	{
		cout<<"Yes\n";
		return;
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
	check_cycle(1,0);	
}