#include <bits/stdc++.h>
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
#define Set set<long>


using namespace std;

vl S, arr;

int main()
{
	//fastio;

    int t = 1;
    cin >> t;
    fflush(NULL);

    S.resize(10000);
    arr.resize(4);

    while(t--)
    {
    	for(int i = 0; i<10; i++)
    		for(int j = 0; j<10; j++)
    			for(int k = 0; k<10; k++)
    				for(int l = 0; l<10; l++)
    				{
    					if(i == j || i == k || i == l)
    						S[i*1000 + j*100 + k*10 + l] = 0;
    					else if(j == k || j == l)
    						S[i*1000 + j*100 + k*10 + l] = 0;
    					else if(k == l)
    						S[i*1000 + j*100 + k*10 + l] = 0;
    					else
    						S[i*1000 + j*100 + k*10 + l] = 1;
    				}


    	int c, d;

    	int g = 0, mflag = 0;
    	while(g < 7)
    	{
    		g += 1;
            int guess;
            
			for(int i = 0; i<S.size(); i++)
        	{
            	if(S[i])
            	{
          	    	guess = i;
                	break;
            	}
			}
			

    		cout << "TIK " << guess << endl;
    		cin >> c >> d;

    		if(c == 4 && d == 0)
    		{
    			mflag = 1;
    			cout << "TOK " << guess << endl;
    			break;
    		}


    		for(int i = 0; i<4; i++)
    		{
    			arr[i] = (guess%10);
    			guess /= 10;
    		}

    		for(int i = 0; i<S.size(); i++)
    		{
                if(!S[i])
                    continue;
    			int tempc = 0, tempd = 0;
    			int num = i;
    			for(int j = 0; j<4; j++)
    			{
    				int flag = 0;
    				int temp = num%10;
    				num /= 10;
    				if(temp == arr[j])
    				{
    					tempc++;
    					flag = 1;
    				}
    				else
    				{
    					for(int j = 0; j<4; j++)
    						if(temp == arr[j])
    							flag = 1;
    						
    				}
    				if(!flag)
    					tempd++;

    			}
    			if(tempd != d || tempc != c)
    				S[i] = 0;
    		}
    	}

    	if(!mflag)
    	{
    		for(int i = 0; i<S.size(); i++)
    			if(S[i])
    			{
    				cout << "TOK " << i << endl;
    				break;
    			} 		
    	}
	}
	return 0;
    
}
