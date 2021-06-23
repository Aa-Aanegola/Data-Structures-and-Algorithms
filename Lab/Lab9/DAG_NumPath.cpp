#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define INF (long)1e15
#define MOD (long)(1e9 + 7)


using namespace std;


vector<int> graph[1000];
int vis[1000];

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	for(int i = 0; i<1000; i++)
		vis[i] = 0;

	queue<int> q;

	int s, t, count = 0;
	cin >> s >> t;
	q.push(s);

	while(!q.empty())
	{
		int start = q.front();
		q.pop();
		for(int i = 0; i<graph[start].size(); i++)
		{
			//cout << start << " " << graph[start][i] << "\n";

			if(graph[start][i] == t)
				count++; 
			
			else
				q.push(graph[start][i]);
		}
	}

	cout << count << "\n";

	return 0;
}