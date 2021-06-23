#include<iostream>
#include<vector>
#define long long long
#define min(a,b) (a<b?a:b)
 
using namespace std;
 
vector<long> graph[100005], price[100005];
long vis[100005], count = 0;
 
void dfs(long x, long pri)
{
    count++;
    vis[x] = 1;
    for(long i = 0; i<graph[x].size(); i++)
        if(!vis[graph[x][i]] && price[x][i] <= pri)
            dfs(graph[x][i], pri);
}
 
 
long count_conn(long n, long pri)
{
    long c = 0;
    long res = 0, mastercount = 0;
    for(long i = 0; i<100005; i++)
        vis[i] = 0;
    for(long i = 1; i<=n; i++)
    {
        if(!vis[i])
        {
            c++;
            count = 0;
            dfs(i, pri);
            mastercount += res * count;
            res = res + count;
        }
    }
    return mastercount;
}
 
int main()
{
    for(int i = 0; i<100005; i++)
        graph[i].clear(), price[i].clear(), vis[i] = 0;
    int n,m;
    long thresh;
    cin >> n >> m;
    while(m--)
    {
        long a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        price[a].push_back(c);
        if(b != a)
        {
            price[b].push_back(c);
            graph[b].push_back(a);
        }
    }
    cin >> thresh;
    long ans, mid, min = 0, max = 1000000005;
    while( max - min != 1)
    {
        mid = (min + max)/2;
        ans = count_conn(n, mid);
        if(ans > thresh)
            min = mid;
        else
        {
            max = mid;
            //index = min(mid,index);
        }
        //cout<<min<<" "<<max<<" "<<ans<<"\n";
    }
 
    cout<<max<<"\n";
}