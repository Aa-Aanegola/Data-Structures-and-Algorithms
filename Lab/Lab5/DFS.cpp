#include<bits/stdc++.h>


using namespace std;

vector<long> graph[100005];
long vis[100005], cat[100005];
long m,n, res = 0;

void dfs(long dfsfrom, long count)
{
	if(count + cat[dfsfrom] > n)
		return;
	//cout<<"DFSFROM: "<<dfsfrom<<" Count: "<<count<< "cat[]: "<< cat[dfsfrom]<<"\n";
	vis[dfsfrom] = 1;
	if(graph[dfsfrom].size() == 1 && dfsfrom != 1)
	{
		if(count + cat[dfsfrom] <= n)
			res += 1;
	}
	for(int i = 0; i<graph[dfsfrom].size(); i++)
	{
		if(!vis[graph[dfsfrom][i]])
		{
			if(cat[dfsfrom])
			{
				//cout<<"cat\n";
				dfs(graph[dfsfrom][i], count + cat[dfsfrom]);
			}
			else
			{
				//cout<<"nocat\n";
				dfs(graph[dfsfrom][i], 0);
			}
		}
	}
}
int main()
{
	//long m,n;
	cin >> m >> n;
	for(int i = 1; i<=m; i++)
		cin >> cat[i];

	long x,y;
	for(int i = 0; i<m-1; i++)
	{	
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1, 0);
	cout<<res<<"\n";
}