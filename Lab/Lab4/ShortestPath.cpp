#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[100005];
int vis[100005], ans[100005];
void bfs(int source)
{
	queue<int> q;
	vis[source] = 1;
	ans[source] = 0;
	q.push(source);
	while(!q.empty())
	{
		int node = q.front();
		//cout<<node<<" ";
		q.pop();
		for(int i = 0; i<graph[node].size(); i++)
		{
			if(vis[graph[node][i]] == 0)
			{
				ans[graph[node][i]] = ans[node] + 1;
				vis[graph[node][i]] = 1;
				q.push(graph[node][i]);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		for(int i = 0; i<100000; i++)
			graph[i].clear();
		for(int i = 0; i<100005; i++)
		{
			vis[i] = 0;
			ans[i] = -1;
		}
		int n,e,root;
		cin >> n >> e >> root;
		while(e--)
		{
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			if(b != a)
				graph[b].push_back(a);
		}
		bfs(root);
		for(int i = 1; i<= n; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
}