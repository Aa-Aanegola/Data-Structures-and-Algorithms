#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define MOD (long)(1e9+7)
#define pb(x) push_back(x)

using namespace std;

struct edge
{
	long from, to, potato, weight;
};

bool comparator(edge e1, edge e2)
{
	if(e1.weight >= e2.weight)
		return false;
	return true;
}


long tree_id[100005], tot[100000];

long findpar(long node)
{
	if(node != tree_id[node])
		return (tree_id[node] = findpar(tree_id[node]));
	return node;
}

void concat(long e1, long e2)
{
	long p1 = findpar(e1);
	long p2 = findpar(e2);

	if(tot[p1] <= tot[p2])
	{
		tot[p2] += tot[p1];
		tree_id[p1] = p2;
	}

	else
	{
		tot[p1] += tot[p2];
		tree_id[p2] = p1;
	}
}


int main()
{
	int n, m, X;
	cin >> n >> m >> X;
	vl x;
	X += 1;

	long ans = 1000000000000000;
	vector<edge> edge_list;
	long a, b, c, d;

	for(int i = 0; i<m; i++)
	{
		cin >> a >> b >> c >> d;
		edge_list.push_back({a-1,b-1,c,d});
	}

	while(X != 0)
	{
		if(X%2)
			x.pb(1);
		else
			x.pb(0);
		X /= 2;
	}
	for(int i = x.size(); i<21; i++)
		x.pb(0);

	sort(edge_list.begin(), edge_list.end(), comparator);

	while(!x[20])
	{
		long cost = 0;
		int numvis = 0;
		int start = m;

		for(int i = 0; i<n; i++)
		{
			tree_id[i] = i;
			tot[i] = 1;	
		}

		for(int i = 0; i<m; i++)
		{
			int flag = 0;
			for(int j = 0; j<x.size(); j++) 
				if(x[j] && ((edge_list[i].potato>>j)%2 & x[j]) == 0)
				{
					flag = 1;
					break;
				}
			if(!flag)
			{
				numvis += 1;
				start = i;
				break;
			}
		}

		for(int i = start; i<m; i++)
		{
			int flag = 0;
			for(int j = 0; j<x.size(); j++)
				if(x[j] && (x[j] & (edge_list[i].potato>>j)%2) == 0)
				{
					flag = 1;
					break;
				}
			if(!flag)
			{
				if(findpar(edge_list[i].from) != findpar(edge_list[i].to))
				{
					numvis += 1;
					concat(edge_list[i].from, edge_list[i].to);
					cost += edge_list[i].weight;
				}
			}
		}

		if(cost < ans && numvis == n)
			ans = cost;

		int spot = -1;
		for(int i = 0; i<x.size(); i++)
			if(x[i])
			{
				spot = i;
				break;
			}

		x[spot] = 0;

		for(int i = spot+1; i<x.size(); i++)
		{
			if(x[i] == 1)
				x[i] = 0;
			else if(x[i] == 0)
			{
				x[i] = 1;
				break;
			}
		}
	}
	if(ans == 1000000000000000)
		cout << "-1\n";
	else
		cout << ans << "\n";
}