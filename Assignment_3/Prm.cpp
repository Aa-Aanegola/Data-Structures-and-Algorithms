#include<bits/stdc++.h>
#define long long long
#define INF (long)1e12
#define pl pair<long, long>
#define ff first
#define ss second


using namespace std;


struct Edge
{
	long from, to, weight;
};


vector<Edge> graph, revgraph;
long fdis[1005], rdis[1005];
long dis[1005];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;

		for(int i = 0; i<m; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			x--;
			y--;
			graph.push_back({x, y, w});
			revgraph.push_back({y, x, w});
		}

		for(int i = 0; i<1005; i++)
		{
			fdis[i] = 0;
			rdis[i] = 0;
		}

		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<graph.size(); j++)
			{
				int u = graph[j].from;
				int v = graph[j].to;
				int w = graph[j].weight;
				if(fdis[u] + w < fdis[v])
					fdis[v] = fdis[u] + w;
			}

			for(int j = 0; j<revgraph.size(); j++)
			{
				int u = revgraph[j].from;
				int v = revgraph[j].to;
				int w = revgraph[j].weight;
				if(rdis[u] + w < rdis[v])
					rdis[v] = rdis[u] + w;
			}
		}

		for(int j = 0; j<graph.size(); j++)
		{
			int u = graph[j].from;
			int v = graph[j].to;
			int w = graph[j].weight;
			if(fdis[u] + w < fdis[v])
				fdis[v] = INF;
		}

		for(int j = 0; j<revgraph.size(); j++)
		{
			int u = revgraph[j].from;
			int v = revgraph[j].to;
			int w = revgraph[j].weight;
			if(rdis[u] + w < rdis[v])
				rdis[v] = INF;
		}


		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<graph.size(); j++)
			{
				int u = graph[j].from;
				int v = graph[j].to;
				if(fdis[u] > 0)
					fdis[v] = INF;
			}

			for(int j = 0; j<revgraph.size(); j++)
			{
				int u = revgraph[j].from;
				int v = revgraph[j].to;
				if(rdis[u] > 0)
					rdis[v] = INF;
			}
		}

		for(int i = 0; i<n; i++)
		{
			dis[i] = fdis[i] + rdis[i];
			if(dis[i] > 0)
				cout << "INF\n";
			else
				cout << dis[i] << "\n";
		}

		graph.clear();
		revgraph.clear();
	}	
}