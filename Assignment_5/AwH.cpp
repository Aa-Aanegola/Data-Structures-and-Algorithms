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

long pow(long mult, long pow, long mod);

struct node
{
	long cost;
	long index;
	long used;
};


bool comparator(node e1, node e2)
{
	return e1.cost < e2.cost;
}

vector<node> sorted;
vl s1, s2;
long n, x, mx, curx = 0;


long cost(long p)
{	
	curx = x;
	fill(all(s2), 0);
    for(auto &i : sorted)
    	i.used = 0;
    
    /*for(auto i : s2)
    	cout << i << " ";
    cout << "\n";*/

	//cout << "iteration " << p << "\n";
	long res = 0;
	for(int i = 0; i<sorted.size(); i++)
	{
		if(s1[sorted[i].index] - s2[sorted[i].index] > p)
		{
			//cout << "selecting: " << sorted[i].cost << "\n";
			s2[sorted[i].index] += 1;
			res += sorted[i].cost;
			sorted[i].used = 1;
			curx += 1;
		}
	}

	int i = 0;
	while(curx <= p && i<sorted.size())
	{
		if(!sorted[i].used)
		{
			//cout << "selecting not less: " << sorted[i].cost << "\n";
			sorted[i].used = true;
			res += sorted[i].cost;
			curx += 1;
		}
		i++;
	}

	if(curx <= p)
		return INF;
	return res;
}


int main()
{
	fastio;

    int t = 1;
    //cin >> t;

    while(t--)
    {
    	cin >> x;
    	cin >> n;
    	
    	mx = x;
    	for(int i = 0; i<n; i++)
    	{
    		int size, temp;
    		cin >> size;
    		s1.pb(size);
    		s2.pb(0);
    		if(size > mx)
    			mx = size;
    		while(size--)
    		{
    			cin >> temp;
    			sorted.pb({temp, i, 0});
    		}
    	}

    	sort(all(sorted), comparator);

    	/*for(auto i : sorted)
    	{
    		cout << i.cost << " " << i.index << " " << i.used << "\n";
    	}
    	for(int i = 0; i<n; i++)
    	{
    		for(auto j : arr[i])
    			cout << j << " ";
    		cout << "\n";
    	}*/

    	long l = -1, r = mx;
    	while(r-l > 1)
    	{
    		
    		long mid = (r+l)>>1;
    		long c1 = cost(mid);
    		long c2 = cost(mid+1);
    		
    		if(c1 < c2)
    			r = mid;
    		else
    			l = mid;
    	}

    	cout << cost(l+1) << "\n";
    }

	return 0;
}



// Helper functions
long pow(long mult, long pow, long mod = MOD)
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