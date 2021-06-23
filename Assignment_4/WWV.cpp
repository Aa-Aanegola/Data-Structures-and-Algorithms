#include<bits/stdc++.h>
#define long long long
#define pl pair<long, long>
#define vl vector<long>
#define ff first
#define ss second
const long INF = 100000;

using namespace std;


struct edge
{
    long from, to, weight, secondary, ind;
};

long n, m, k;
vector<edge> edge_list;
long par[5050], res[5050];
long total = 0, numcom = 0;
vector<long> wei;
int root = 1;

bool comparator(edge e1, edge e2)
{
    if(e1.secondary == e2.secondary)
        return e1.from < e2.from;
    return e1.secondary < e2.secondary;
    
}

long findPar(long node)
{
    if(par[node] != node)
        return (par[node] = findPar(par[node]));
    return node;
}

void concat(long x)
{

    for(int i = 1; i<n+1; i++)
        par[i] = i;

    total = 0;
    numcom = 0;

    for(auto &i : edge_list)
    {
        i.secondary = i.weight;

        if(i.from == root)
            i.secondary += x;
    }

    sort(edge_list.begin(), edge_list.end(), comparator);

    long tempcom;

    for(auto &i : edge_list)
    {
        if(total >= n)
            break;

        long p1 = findPar(i.from);
        long p2 = findPar(i.to);
            
        tempcom = numcom;

        if(p1 == p2)
            continue;
        
        if(i.from == root)
            tempcom += 1;

        if(tempcom <= k)
        {
            numcom = tempcom;
            par[p1] = p2;
            total += 1;
            res[total] = i.ind;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    wei.push_back(0);

    long f, t, w, temp;

    for(int i = 0; i<m; i++)
    {
        cin >> f >> t >> w;
        
        if(f > t)
            swap(f, t);

        edge_list.push_back({f, t, w, w, i+1});
        wei.push_back(w);
    }

    long mn = -INF, mx = INF, mid;
    while(mn < mx)
    {
        mid = (1 + mn + mx)/2;
        concat(mid);

        if(numcom < k)
            mx = mid - 1;
        else
            mn = mid;
    }

    concat(mn);

    if(numcom < k)
    {
        cout << "-1\n";
        return 0;
    }


    if(total < n - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    
    long finans = 0;
    for(int i = 1; i < total+1; i++)
        finans += wei[res[i]];

    cout << finans << "\n";

    return 0;
}