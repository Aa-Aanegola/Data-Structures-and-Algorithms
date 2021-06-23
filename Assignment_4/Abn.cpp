#include<bits/stdc++.h>

#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define INF (long)1e19
#define MOD (long)(1e9+7)


using namespace std;

int tree_id[100005], tot[100005];
long ans = 1;

int findpar(int node)
{
	if(node != tree_id[node])
		return tree_id[node] = findpar(tree_id[node]);
	return node;
}


void concat(int e1, int e2)
{
	long p1 = findpar(e1);
	long p2 = findpar(e2);
	if(p1 == p2)
	{
		ans *= 2;
		ans %= MOD;
		return;
	}
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
	int n, m;
	cin >> n >> m;
	long c = 0;
	for(int i = 0; i<n; i++)
	{
		tree_id[i] = i;
		tot[i] = 1;
	}

	for(int i = 0; i<m; i++)
	{
		int from, to;
		cin >> from >> to;
		from -= 1;
		to -= 1;

		concat(from, to);

		cout << ans-1 << "\n";
	}
}