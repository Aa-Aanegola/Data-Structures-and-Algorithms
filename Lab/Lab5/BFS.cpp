#include<iostream>
#include<vector>
#include<queue>
#define min(a,b) (a<b ? a : b)
#define long long long

using namespace std;

vector<long> graph[100005];
long cost[100005], tempans, ans = 0;
int vis[100005];


int main()
{
	long m,n;
	cin >> m >> n;
	for(int i = 1; i<=m; i++)
		cin >> cost[i];
	long x,y;

	for(int i = 0; i<100005; i++)
		vis[i] = 0;

	for(int i = 0; i<n; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	long j = 0;
	queue<long> q; 
	while(j != m)
	{	
		j+=1;
		tempans = cost[j];
		if(!vis[j])
		{
			vis[j] = 1;
			q.push(j);
			while(!q.empty())
			{
				tempans = min(tempans, cost[q.front()]);
				for(int i = 0; i<graph[q.front()].size(); i++)
				{
					if(!vis[graph[q.front()][i]])
					{
						vis[graph[q.front()][i]] = 1;
						q.push(graph[q.front()][i]);
						tempans = min(tempans, cost[q.front()]);	
					}
				}	
				q.pop();
			}
			ans += tempans;
		}
	}
	cout<<ans<<"\n";
}	