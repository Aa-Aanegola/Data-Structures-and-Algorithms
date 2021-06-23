#include <iostream>
#include<vector>
#include<math.h>
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


long extendedinv(long a, long m)
{
	int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    {    
        int q = a / m; 
        int t = m; 
  
        
        m = a % m, a = t; 
        t = y; 
  
        
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
}



vector<long> op;


long toit(long n)
{
	long result = n;
    for (long i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


void generate(long L = 3, long R = 1048573) {

	vector<bool> is_prime(R+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= R; i++) 
	{
		if (is_prime[i]) 
		{
			for (int j = i * i; j <= R; j += i)
		        is_prime[j] = false;
		}
	}

	for(int i = 3; i<=1048573; i++)
		if(is_prime[i])
			op.pb(i);
}


int search(int num)
{
	int s = 0, e = 82023;
	while(s <= e)
	{
		int mid = (s+e)>>1;
		if(op[mid] == num)
			return mid+1;
		if(num < op[mid])
			e = mid-1;
		else
			s = mid+1;
	}
	return -1;
}


int main()
{
	fastio;

    int t = 1;
    cin >> t;

    generate();


    /*for(auto i : op)
    	cout << i << "\n";
    cout << op.size() << endl;
*/

    while(t--)
    {
    	long height, prev, cur, i = 1, D, p;
    	cin >> height >> prev;

    	long ranges[2][2] = {{2, 1 << (height-1)}, {(1<<(height-1))+1, (1 << height)+1}};
    	while(true)
    	{
    		cout << "DARE " << i << endl;
    		cin >> cur >> p >> D;

    		long T = (cur * extendedinv(prev, MOD))%MOD;
    		
    		//cout << search(p) << "\n";
    		long U = (T * extendedinv(search(p), MOD)) % MOD;

    		long V = extendedinv(U, D)%MOD;

    		//cout << "T: " << T << " U: " << U << " V: " << V << endl;

    		if(V == 1)
    		{
    			cout << "TRUTH " << toit(i) << endl;
    			break;
    		}

    		if(V >= ranges[0][0] && V <= ranges[0][1])
    			i = 2*i;
    		else
    			i = 2*i+1;

    		prev = cur;
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
			res %= mod;
		}
		mult *= mult;
		mult %= mod;
		pow >>= 1;
	}
	return res;
}