#include<iostream>
#define ll long long

using namespace std;

ll blobsize[200005];
ll par[200005];

ll getPar(ll node)
{
	while(par[node] != node)
	{
		return par[node] = getPar(par[node]);
	}
	return node;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,m;
	cin >> n >> m;

	for(int i = 1; i<=n; i++)
	{
		blobsize[i] = 1;
		par[i] = i;
	}

	ll max = -1, ans = 0;
	for(int i = 0; i<m; i++)
	{
		ll from, to;
		cin >> from >> to;
		
		ll parfrom = getPar(from);
		ll parto = getPar(to);
		
		if(parfrom != parto)
		{
			if(blobsize[parfrom] > blobsize[parto])
			{
				blobsize[parfrom] += blobsize[parto];
				par[parto] = parfrom;

				if(blobsize[parfrom] > max)
					max = blobsize[parfrom];
			}

			else
			{
				blobsize[parto] += blobsize[parfrom];
				par[parfrom] = parto;

				if(blobsize[parto] > max)
					max = blobsize[parto];
			}
		}		
		ans += max;
	}
	cout << ans << "\n";
}