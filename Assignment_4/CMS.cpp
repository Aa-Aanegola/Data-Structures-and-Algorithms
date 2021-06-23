#include<bits/stdc++.h>
#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
const long INF = 100000;
#define MOD (long)(1e9+7)

using namespace std;

long n, m, k;
vector<pl> par;
long tot[10000];
long counter = 0;
int flag = 0;


pl findpar(long x)
{
	pl node = {x, 0};
	if(par[x] == node)
		return node;
	pl temp = findpar(par[x].ff);
	return par[x] = {temp.ff, temp.ss ^ par[x].ss};
}


void concat(long e1, long e2, long weight)
{
	auto p1 = findpar(e1);
	auto p2 = findpar(e2);
	long we = p2.ss ^ p1.ss;

	if(p1.ff == p2.ff && we == weight)
	{
		return;
	}
	
	if(p1.ff == p2.ff && we != weight)
	{
		flag = 1;
	}

	counter += 1;
	if(p1.ff < p2.ff)
		swap(p1, p2);
	tot[p1.ff] += tot[p2.ff];
	par[p2.ff] = {p1.ff, we ^ weight};
}


int main()
{
	cin >> n >> m >> k;
	par.resize(10000);

	for(int i = 0; i<10000; i++)
	{
		par[i] = {i, 0};
		tot[i] = 1;
	}


	for(int i = 0; i<k; i++)
	{
		long a, b, c;
		cin >> a >> b >> c;
		if(flag)
			continue;
		b += 2000;
		concat(a, b, c);

	}

	if(flag)
	{
		cout << "0\n";
		return 0;
	}

	long pow = 30 * (n + m - counter - 1);
	long res = 1;
	long mult = 2;

	while(pow > 0)
	{
		if(pow&1)
		{
			res *= mult;
			res %= MOD;
		}

		pow >>= 1;
		mult *= mult;
		mult %= MOD;
	}	

	cout << res << "\n";
}