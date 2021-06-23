#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define long long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;


vector<pair<long,long>> graph[100005], ans;
long pizzaboy[100005];
int vis[100005];
long n,q;



bool comparator(const pair<long, long> e1, const pair<long, long> e2)
{
	if(e1.second != e2.second)
	{
		if(e1.second < e2.second)
			return 1;
		else
			return 0;
	}
	else
	{
		if(e1.first > e2.first)
			return 1;
		else
			return 0;
	}
}

void remove_par(long start, long check)
{
	for(int i = 0; i<graph[start].size(); i++)
	{
		if(graph[start][i].first == check)
		{
			graph[start][i].first = -1;
			graph[start][i].second = 1000000000000;
			continue;
		}
		remove_par(graph[start][i].first, start);
	}
}


void dfs(long dfsfrom, long weight, long left, long right)
{
    if(weight > right)
    	return; 
    if(right < left)
        return;
    long flag = 0;
    for (int i = 0; i < graph[dfsfrom].size(); i++)
    {
        if (graph[dfsfrom][i].first == -1)
            continue;
        else
        {
        	if (i > 0 && graph[dfsfrom][i].second == graph[dfsfrom][i - 1].second)
            	continue;
            else
            {
        		if (graph[dfsfrom][i].second <= weight)
            	flag = 1;
            }
        }
        long j = i + 1;
        while(graph[dfsfrom][i].second == graph[dfsfrom][j].second)
            j++;
        long newleft = max(graph[dfsfrom][i].second + 1, weight + 1);
        long newright = min(graph[dfsfrom][j].second, right);
        long newweight = max(graph[dfsfrom][i].second, weight);
        
        dfs(graph[dfsfrom][i].first, newweight, newleft, newright);
    }

    if (!flag)
    {
    	pair<long, long> tem;
    	tem.first = weight;
    	tem.second = dfsfrom;
        ans.push_back(tem);
    }
}

int main()
{
	cin >> n >> q;
	long a,b,c;
	for(int i = 0; i<n-1; i++)
	{
		cin >> a >> b >> c;
		pair<long, long> tem;
		tem.first = b-1;
		tem.second = c;
		graph[a-1].push_back(tem);
		tem.first = a-1;
		graph[b-1].push_back(tem);
	}
	graph[0].push_back({0, 1000000000000});

	for(int i = 0; i<q; i++)
		cin>>pizzaboy[i];

	remove_par(0, 0);


	int i = 0;
	while(i < n)
	{
		sort(graph[i].begin(), graph[i].end(), comparator);
		i+=1;
	}
	//for(int i = 0; i<n; i++)
	//{
	//	for(int j = 0; j<graph[i].size(); j++)
	//		cout<<i<<"\t"<<graph[i][j].first<<"\t"<<graph[i][j].second<<"\n";
	//}
	
	dfs(0, 0, 0, 1000000000000);
	sort(ans.begin(), ans.end());
	//for(int i = 0; i<ans.size(); i++)
		//cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	//cout<<"\n";

	long  finans = 0; //mid, min, max, house, thresh, tempans = -1;
	//cout<<ans.size()<<"\n";
	//cout<<"\n\n";
	for(int i = 0; i<q; i++)
	{
		pair<long,long> per = {pizzaboy[i], -1};
   		auto it = lower_bound(ans.begin(), ans.end(), per);
		it--;   	

   		finans += it->second + 1;
	}
	cout<<finans<<"\n";
}