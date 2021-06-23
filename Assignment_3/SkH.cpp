#include<iostream>
#include<vector>
#include<queue>
#define long long long
#define INF (long)(1e15)
#define pl pair<long, long>
#define ff first
#define ss second


using namespace std;
	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<pl> graph[100005];
	long distA[100005], distB[100005];
	long S, T, A, B;
	long n, m;
	

	cin >> n >> m;
	for(int i = 1; i<=n; ++i)
	{	
		distA[i] = INF;
		distB[i] = INF;
	}

	long a,b,w;
	for(int i = 0; i<m; ++i)
	{
		cin >> a >> b >> w;
		graph[a].push_back({w,b});
		if(a != b)
			graph[b].push_back({w,a});
	}

	/*for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<graph[i].size(); j++)
			cout << i << " " << graph[i][j].ss << " " << graph[i][j].first << "\n";
	}*/

	cin >> S >> T >> A >> B;
	
	long node;
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	pq.push({0,S});
	distA[S] = 0;

	while(!pq.empty())
	{
		node = pq.top().ss;
		pq.pop();

		//cout << node << "\n";
		for(auto i : graph[node])
		{
			if(i.ff <= A)
			{
				if(distA[node] + i.ff < distA[i.ss])
			
				{
					distA[i.ss] = distA[node] + i.ff;
					pq.push({distA[i.ss], i.ss});
				}
			}
		} 
	}

	pq.push({0, T});
	distB[T] = 0;

	while(!pq.empty())
	{
		node = pq.top().ss;
		pq.pop();

		//cout << node << "\n";
		for(auto i : graph[node])
		{
			if(i.ff >= B)		
			{
				if(distB[node] + i.ff < distB[i.ss])
				{
					distB[i.ss] = distB[node] + i.ff;
					pq.push({distB[i.ss], i.ss});
				}
			}
		} 
	}

	long min = INF;

	for(int i = 1; i<=n; ++i)
	{
		if(distA[i] + distB[i] < min)
			min = distA[i] + distB[i];
	}

	if(min == INF)
		cout << "-1\n";
	else
		cout << min << "\n";
}