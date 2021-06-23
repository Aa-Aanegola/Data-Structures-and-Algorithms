#include<bits/stdc++.h>
#define long long long
#define pl pair<long, long>
#define INF 1e16
#define ss second
#define ff first

using namespace std;

long GCD(long a, long b)
{
	if(b == 0)
		return a;
	else
		return GCD(b, a%b);
}


struct Edge
{
	long from, to, weight;
};



bool comparator(Edge e1, Edge e2)
{
	if(e1.weight >= e2.weight)
		return false;
	return true;
}

vector<Edge> edge_list;
long cost = 0, tree_id[305], tot[305];

long findpar(long node)
{
	if(node != tree_id[node])
		return tree_id[node] = findpar(tree_id[node]);
	else
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

void findcost()
{
	for(int i = 0; i<305; i++)
	{
		tree_id[i] = i;
		tot[i] = 1;
	}

	for(int i = 0; i<edge_list.size(); i++)
	{
		if(findpar(edge_list[i].from) != findpar(edge_list[i].to))
		{
			concat(edge_list[i].from, edge_list[i].to);
			cost += edge_list[i].weight;
		}
	}
}




int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long M,K;
	cin >> M >> K;
	long gcd, temp;
	vector<long> a[M+5];
	vector<long> arr[M+5];

	for(int i = 1; i<=M; i++)
	{
		for(int j = 0; j<K; j++)
		{
			cin >> temp;
			arr[i].push_back(temp);
		}

		sort(arr[i].begin(), arr[i].end(), greater<int>());
	}

	/*for(int i = 0; i<M; i++)
	{
		for(int j = 0; j<K; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}*/


	for(int i = 1; i<=M; i++)
	{
		a[i].push_back(arr[i][0]);
		for(int j = 1; j<K; j++)
		{
			gcd = GCD(a[i].back(), arr[i][j]);
			if (gcd != a[i].back())
				a[i].push_back(gcd);
		}
	}

	/*for(int i = 0; i<M; i++)
	{
		for(int j = 0; j<a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}*/


	for(int i = 1; i<=M; i++)
	{
		for(int j = i+1; j<=M; j++)
		{
			long min = INF, temp;
			for(int k = 0; k<a[i].size(); k++)
				for(int l = 0; l<a[j].size(); l++)
				{
					temp = a[i][k] ^ a[j][l];
					edge_list.push_back({i,j,min});		
				}
		}
	}

	sort(edge_list.begin(), edge_list.end(), comparator);

	/*for(int i = 0; i<edge_list.size(); i++)
			cout << edge_list[i].from << " " << edge_list[i].to << " " << edge_list[i].weight << "\n";
	*/

	findcost();

	cout << cost << "\n";
}