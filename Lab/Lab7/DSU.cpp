#include<bits/stdc++.h>
#define long long long


using namespace std;

struct edge
{
	long from, to;
	long weight;
};


bool comparator(edge e1, edge e2)
{
	if(e1.weight > e2.weight)
		return false;
	else
		return true;
}

long par[100005], sum[100005];
vector<edge> edge_list;


long findpar(long node)
{
	long temp = node;
	while(par[temp] != temp)
	{
		temp = par[temp];
	}
	return temp;
}

void merge(long merge1, long merge2)
{
	merge1 = findpar(merge1);
	merge2 = findpar(merge2);

	if(sum[merge1] > sum[merge2])
	{
		sum[merge1] += sum[merge2];
		par[merge2] = merge1;
	}
	else
	{
		sum[merge2] += sum[merge1];
		par[merge1] = merge2;
	}
}


long Kruskal(long n)
{
	long total = 0;

	for(long i = 0; i<n; i++)
		par[i] = i, sum[i] = 1;

	for(long i = 0; i<n; i++)
	{
		if(findpar(edge_list[i].from) != findpar(edge_list[i].to))
		{
			total += edge_list[i].weight;
			merge(edge_list[i].to, edge_list[i].from);
		}
	}
	return total;
}

int main()
{
	long n,m;
	cin >> n >> m;
	for(long i = 0; i<m; i++)
	{
		long a,b,w;
		cin >> a >> b >> w;
		edge temp;
		temp.from = a-1;
		temp.to = b-1;
		temp.weight = w;
		edge_list.push_back(temp);
	}

	sort(edge_list.begin(), edge_list.end(), comparator);

	long ans = Kruskal(m);
	cout << ans << "\n";
	return 0;
}