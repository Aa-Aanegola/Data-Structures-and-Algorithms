#include <iostream>
#include<vector>
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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define Set set<long, greater<long>>


using namespace std;

long pow(long mult, long pow, long mod);



int main()
{
	fastio;

	int n;
	cin >> n;
    int t = 1;
    cin >> t;

    int num, find, temp, desc = -1;
    int first, last;

    while(t--)
    {
    	cin >> find;
    	if(desc == -1)
    	{
    		cout << "READ " << 0 << endl;
    		cin >> first;
    		cout << "READ " << n-1 << endl;
    		cin >> last;

    		if(first <= last)
    			desc = 0;
    		else
    			desc = 1;
    	}

    	if(!desc)
    	{
    		int pos = -1, num, mid, s = 0, e = n-1;
    		while(s <= e)
    		{
    			mid = (s+e)>>1;
    			cout << "READ " << mid << endl;
    			cin >> num;
    			if(num == find)
    				pos = mid;
    			if(find > num)
    				s = mid+1;
    			else
    				e = mid-1;
    		}

    		cout << "OUTPUT " << pos << endl;
    	}

    	else
    	{
    		int pos = -1, num, mid, s = 0, e = n-1;
    		while(s <= e)
    		{
    			mid = (s+e)>>1;
    			cout << "READ " << mid << endl;
    			cin >> num;
    			if(num == find)
    				pos = mid;
    			if(find < num)
    				s = mid+1;
    			else
    				e = mid-1;
    		}

    		cout << "OUTPUT " << pos << endl;	
    	}
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
			res %= mult;
		}
		mult *= mult;
		mult %= mult;
	}
	return res;
}