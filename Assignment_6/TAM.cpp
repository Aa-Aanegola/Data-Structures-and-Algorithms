#include <iostream>
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
	//fastio;

    int t = 1;
    cin >> t;

    while(t--)
    {
    	int n;
    	cin >> n;
    	int posf = -1, post = -1, countf = 0, countt = 0;

    	string str;
    	for(int i = 0; i<n; i++)
    	{
    		cout <<"READ " << i << "\n";
    		fflush(NULL);
    		cin >> str;
    		if(str == "false")
    		{
    			posf = i;
    			countf++;
    		}
    		else
    		{
    			post = i;
    			countt++;
    		}
    	}

    	if(countt == 1)
    		cout << "OUTPUT " << post << "\n";
    	else
    		cout << "OUTPUT " << posf << "\n";
        fflush(NULL);
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