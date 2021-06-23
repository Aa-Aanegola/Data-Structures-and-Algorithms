#include<iostream>
#define inf 10000000000000000
#define long long long
using namespace std;


int main()
{
	int e;
	cin >> e;
	long graph[505][505], dist[505][505];
	for(int i = 0; i<505; i++)
		for(int j = 0; j<505; j++)
			graph[i][j] = inf;
	for(int i = 0; i<505; i++)
		graph[i][i] = 0;

	while(e--)
	{
		long a,b,c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for(int i = 0; i<505; i++)
		for(int j = 0; j<505; j++)
			dist[i][j] = graph[i][j];

	for(int k = 0; k<505; k++)
		for(int i = 0; i<505; i++)
			for(int j = 0; j<505; j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	int u, q;
	cin >> u >> q;
	while(q--)
	{
		int a;
		cin >> a;
		if(dist[u][a] == inf)
			cout<<"NO PATH\n";
		else
			cout<<dist[u][a]<<"\n";
	}
}