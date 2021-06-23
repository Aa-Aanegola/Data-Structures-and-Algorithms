#include <iostream>
#include <vector>
#include <cstring>
#include <string>
//#include <queue>
//#include <deque>
//#include <stack>
#include <algorithm>
#include <cmath>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>

#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(), a.end()
#define ql queue<long>
#define sl stack<long>
#define MAX (long)(1e6+5)
#define INF (long)(1e18)
#define MOD (long)(1e9+7)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define Set set<long, greater<long>>


using namespace std;


long power(long mult, long pow, long mod = MOD);

vl temparr, p, h;
long Q, P, X, n;

class Map
{
public:
	vl arr;
	
	Map(vl &temp)
	{
		arr.pb(temparr[0]);
		for(auto i : temparr)
			if(arr.back() != i)
				arr.pb(i);
	}
	long index(long val);
};


long Map::index(long val)
{
	long mid, l = 0, r = arr.size()-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(arr[mid] == val)
			return mid;
		else if(arr[mid] < val)
			l = mid+1;
		else
			r = mid-1;
	}
	return mid;
}

struct node
{
	long val, cnt, hash, mult;
};

class SegTree
{
public:
	vector<node> data;
	
	SegTree(long n)
	{
		data.resize(4*n);
	}

	void build(long left, long right, long v);
	void join(long v);
	bool check(long pos, long left, long right, long v);
	void insert(long val, long pos, long left, long right, long v); 	
	void del(long val, long pos, long left, long right, long v);
};

void SegTree::build(long left, long right, long v = 1)
{
	data[v].mult = 1;
	if(left == right)
	{
		data[v].val = 0;
		data[v].cnt = 0;
		data[v].hash = 0;
		data[v].mult = 1;
		return;
	}

	long mid = (left+right)>>1;
	build(left, mid, 2*v);
	build(mid+1, right, 2*v+1);
}


void SegTree::join(long v)
{
	data[v].val = 0;
	data[v].cnt = data[2*v].cnt + data[2*v+1].cnt;
	data[v].mult = data[2*v].mult * data[2*v+1].mult;
	data[v].mult %= MOD;
	data[v].hash = data[2*v].hash;
	data[v].hash += (data[2*v+1].hash * data[2*v].mult)%MOD;
	data[v].hash %= MOD;
}


bool SegTree::check(long pos, long left, long right, long v = 1)
{
	if(left == right)
	{
		if(data[v].cnt>0)
			return true;
		return false;
	}

	long mid = (left+right)>>1;

	if(pos <= mid)
		return check(pos, left, mid, 2*v);

	return check(pos, mid+1, right, 2*v+1);
}


void SegTree::insert(long val, long pos, long left, long right, long v = 1)
{
	if(left == right)
	{
		data[v].val = val;
		data[v].cnt += 1;
		data[v].mult *= P;
		data[v].mult %= MOD;
		data[v].hash = data[v].cnt * val;
		data[v].hash %= MOD;
		data[v].hash *= data[v].mult;
		data[v].hash %= MOD;
		return;  
	}

	long mid = (left+right)>>1;

	if(pos <= mid)
		insert(val, pos, left, mid, 2*v);
	else
		insert(val, pos, mid+1, right, 2*v+1);

	join(v);
}

void SegTree::del(long val, long pos, long left, long right, long v = 1)
{
	if(left == right)
	{
		data[v].cnt -= 1;
		data[v].mult = data[v].mult * power(P, MOD-2);
		data[v].mult %= MOD;
		data[v].hash = data[v].cnt * val;
		data[v].hash %= MOD;
		data[v].hash *= data[v].mult;
		data[v].hash %= MOD;
		return;
	}

	long mid = (left+right)>>1;

	if(pos <= mid)
		del(val, pos, left, mid, 2*v);
	else
		del(val, pos, mid+1, right, 2*v+1);

	join(v);
}


int main()
{
	fastio;

    int t = 1;
    //cin >> t;

    vector<pl> quer; 

    while(t--)
    {
    	cin >> Q >> P >> X;
    	p.pb(1);
    	for(int i = 1; i<MAX; i++)
    	{
    		long temp = P * p.back();
    		temp %= MOD;
    		p.pb(temp);
    	}

    	while(Q--)
    	{
    		char c;
    		cin >> c;
    		long k;
    		switch(c)
    		{
    			case 'A':
    				cin >> k;
    				temparr.pb(k);
    				quer.pb({k, 1});
    				break;
    			case 'D':
    				long k;
    				cin >> k;
    				temparr.pb(k);
    				quer.pb({k, 2});
    				break;
    			default:
    				quer.pb({3, 3});
    		}
    	}

    	sort(all(temparr));
    	Map m(temparr);
    	n = m.arr.size();

    	
		
    	if(n == 0)
    		n = 1;
    	SegTree AVLol(n+1);
    	AVLol.build(0, n);

    	for(auto i : quer)
    	{
    		switch(i.ss)
    		{
    			case 1:
    				AVLol.insert(i.ff, m.index(i.ff), 0, n-1);
    				break;
    			case 2:
    				if(AVLol.check(m.index(i.ff), 0, n-1))
    					AVLol.del(i.ff, m.index(i.ff), 0, n-1);
    				break;
    			default:
    				h.pb(AVLol.data[1].hash);
    		}
    	}

    	long V = 1;
    	for(auto i : h)
    	{
    		//cout << i << " ";
    		V *= power(X, i);
    		V %= MOD;
    	}
    	//cout << "\n";
    	cout << V << "\n";
    }

	return 0;
}



// Helper functions
long power(long mult, long pow, long mod)
{
	long res = 1;
	while(pow > 0)
	{
		if(pow&1)
		{
			res *= mult;
			res %= mod;
		}
		mult *= mult;
		mult %= mod;
		pow >>= 1;
	}
	return res;
}