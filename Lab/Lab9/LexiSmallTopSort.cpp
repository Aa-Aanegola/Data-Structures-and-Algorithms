#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define INF (long)1e15
#define MOD (long)(1e9 + 7)


using namespace std;

vector<int> graph[1000];
int indeg[1000];
int sorted[1000];
int vis[1000];


int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i<1000; i++)
	{
		vis[i] = 0;
		indeg[i] = 0;
	}

	for(int i = 0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		indeg[y]++;
	}

	priority_queue<int, vector<int>, greater<long>> q;
	int pos = 0;

	for(int i = 1; i<=n; i++)
	{
		if(indeg[i] == 0)
		{
			vis[i] = 1;
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int node = q.top();
		sorted[pos++] = node;
		q.pop();
		for(int i = 0; i<graph[node].size(); i++)
		{
			if(!vis[graph[node][i]])
			{
				indeg[graph[node][i]]--;

				if(indeg[graph[node][i]] == 0)
				{
					q.push(graph[node][i]);
					vis[graph[node][i]] = 1;
				}
			}
		}
	}

	for(int i = 0; i<n; i++)
		cout << sorted[i] << " ";
	cout << "\n";

	return 0;
}