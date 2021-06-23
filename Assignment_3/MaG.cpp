#include<bits/stdc++.h>
#define long long long
#define pl pair<long, long>
//#define PQ priority_queue<pl, vector<pl>, greater<int>()>
#define INF 1e9
#define MAX 100005
#define ff first
#define ss second


using namespace std;


long n, m, k;
vector<pl> adj[MAX];
int vis[MAX];
long ans = -1;


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i<MAX; i++)
    	vis[i] = 0;

    cin >> n >> m >> k;

    for(int i = 0; i<m; i++)
    {

    	long x, y, w;
    	cin >> x >> y >> w;
    	adj[x].push_back({y, w});
    	adj[y].push_back({x, w});
    }

   	priority_queue<pl, vector<pl>, greater<pl>> pq;

    for(int i = 0; i<k; i++)
    {
    	int t;
    	cin >> t;
    	pq.push({0, t});
    	vis[t] = 1;
    }

    if(n == 1)
    {
    	if(vis[0])
    		cout << "0\n";
    	else
    		cout << "-1\n";
    	return 0;
    }

    if(n == 2)
    {
    	if(vis[0])
    		cout << "0\n";
    	else
    		cout << "-1\n";
    	return 0;
    }

    while(!pq.empty())
    {
    	long from = pq.top().ss;
    	long weight = pq.top().ff;
    	pq.pop();
    	if(vis[from] == 0)
    	{
    		vis[from] = 1;
    		continue;
    	}

    	if(vis[from] == 2)
    	{
    		continue;
    	}

    	if(from == 0)
    	{
    		ans = weight;
    		break;
    	}

    	vis[from] = 2;
    	for(int i = 0; i<adj[from].size(); i++)
    	{
    		pl temp = adj[from][i];
    		long to = temp.ff;
    		long newl = weight + temp.ss;
    		if(vis[to] != 2)
    			pq.push({newl, to});
    	}
    }

    cout << ans << "\n";
}