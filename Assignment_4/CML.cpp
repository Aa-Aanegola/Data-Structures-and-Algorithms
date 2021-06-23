#include<bits/stdc++.h>
#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
const long INF = 10000000000;
#define MOD (long)(1e9+7)

using namespace std;


long n, m, k, x;
unordered_map<long, pl> par;
unordered_map<long, long> tot;
int flag = 0;
int counter = 0;
int fincount = 0;
vector<long> h;

long pow(long x, long y, long m)
{
	long res = 1;
	while(y > 0)
	{
		if(y & 1)
		{
			res *= x;
			res %= m;
		}

		x *= x;
		x %= m;
		y >>= 1;
	}
	return res;
}

pl findpar(long x)
{
	pl node = par.find(x)->ss;
	if(node.ff == x)
		return node;
	pl temp = findpar(par[x].ff);
	return par[x] = {temp.ff, temp.ss ^ par[x].ss};
}

void concat(long e1, long e2, long weight)
{
	if(flag == 1)
		return;
	auto p1 = findpar(e1);
	auto p2 = findpar(e2);
	long we = p1.ss ^ p2.ss;

	if(p1.ff == p2.ff && we == weight)
	{
		return;
	}
	
	if(p1.ff == p2.ff && we != weight)
	{
		flag = 1;
		return;
	}

	counter += 1;
	if(p1.ff < p2.ff)
		swap(p1, p2);
	tot[p1.ff] += tot[p2.ff];
	par[p2.ff] = {p1.ff, we ^ weight};
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m >> k >> x;

	long a, b, c;
	for(int i = 0; i<k; i++)
	{
		cin >> a >> b >> c;
		b += INF;
		if(par.find(a) == par.end())
		{
			par.insert({a, {a, 0}});
			tot.insert({a, 1});
		}

		if(par.find(b) == par.end())
		{
			par.insert({b, {b, 0}});
			tot.insert({b, 1});
		}
		

		concat(a, b, c);
		if(flag)
			continue;
		h.push_back(n + m - 1 - counter);
		//cout << h.back() << " " << counter << "\n";
		//cout << par[a].ff << " " << par[b].ff << "\n";
	}

	long finpow = 0;
	for(auto i : h)
	{
		long pow = 30*i;
		long res = 1;
		long mult = 2;
		while(pow > 0)
		{
			if(pow & 1)
			{
				res *= mult;
				res %= MOD-1;
			}

			mult *= mult;
			mult %= MOD-1;
			pow >>= 1;
		}
		finpow += res;
		finpow %= MOD-1;
	}

	long resfinal = 1;
	long mult = x;
	//cout << finpow << "\n";
	while(finpow > 0)
	{
		if(finpow & 1)
		{
			resfinal *= mult;
			resfinal %= MOD;
		}

		mult *= mult;
		mult %= MOD;
		finpow >>= 1;
	}

	cout << resfinal << "\n";
}