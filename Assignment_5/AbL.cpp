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
#define INF (long)(1e12)
#define MOD (long)(1e9+7)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define Set set<long, greater<long>>


using namespace std;

long pow(long mult, long pow, long mod);

class MinHeap
{
	vl data;
	long size;

public:
	MinHeap()
	{
		data.resize(MAX);
		size = 0;
	}
	bool empty()
	{
		if(!size)
			return true;
		return false;
	}
	void insert(long value);
	void del(long value);
	long extract_min();
	void heapify(long i);
	long return_min();
	void print();
};


void MinHeap::insert(long value)
{
	data[++size] = value;
	long pos = size;
	while(pos != 1)
	{
		if(data[pos] < data[pos/2])
			swap(data[pos], data[pos/2]);
		else
			break;
		pos /= 2;
	}
}

long MinHeap::extract_min()
{
	long ret = data[1];
	data[1] = data[size];
	size --;
	heapify(1);
	return ret;
}

void MinHeap::heapify(long i)
{
	long left = 2*i;
	long right = 2*i+1;
	long smallest = i;
	if(left <= size && data[left] < data[i])
		smallest = left;
	if(right <= size && data[right] < data[smallest])
		smallest = right;
	swap(data[smallest], data[i]);
	if(smallest != i)
		heapify(smallest);
}

long MinHeap::return_min()
{
	return data[1];
}

void MinHeap::print()
{
	for(int i = 1; i<=size; i++)
		cout << data[i] << " ";
	cout << "\n";
}



vector<vl> graph;
vl vis, dep, indeg;
long cyc = 0;
long n, k;	
vl sorted;



bool DFS(long node)
{
	dep[node] = 1;
	for(auto i : graph[node])
	{
		if(dep[i] == 0)
		{
			if(DFS(i))
				return true;
		}
		else if(dep[i] == 1)
		{
			cyc = 1;
			return true;
		}
	}
	dep[node] = 2;
	return false;
}

bool cycle()
{
	vis.resize(k);
	dep.resize(k);
	fill(all(vis), 0);
	fill(all(dep), 0);

	for(int i = 0; i<k; i++)
	{
		if(dep[i] == 0 && DFS(i))
			break;
	}

	if(cyc)
		return true;

	return false;
}

void minTS()
{
	MinHeap q;
	fill(all(vis), 0);

	for(int i = 0; i<k; i++)
	{
		if(!indeg[i])
		{
			vis[i] = 1;
			q.insert(i);
		}
	}

	//q.print();

	while(!q.empty())
	{
		long node = q.extract_min();
		sorted.pb(node);
		
		for(auto i : graph[node])
		{
			if(!vis[i])
			{
				indeg[i]--;
				if(!indeg[i])
				{
					q.insert(i);
					vis[i] = 1;
				}
			}
		}
	}

	//cout << sorted.size() << "\n";

	for(auto i : sorted)
		cout << i+1 << " ";
	cout << "\n";
}



int main()
{
	fastio;

    int t = 1;
    //cin >> t;

    while(t--)
    {
    	cin >> n >> k;

    	graph.resize(k);
    	indeg.resize(k);
    	fill(all(indeg), 0);

    	vl arr[n];
    	for(int i = 0; i<n; i++)
    	{
    		long size;
    		cin >> size;
    		arr[i].resize(size);
    		for(int j = 0; j<size; j++)
    		{
    			cin >> arr[i][j];
    			arr[i][j]--;
    		}
    	}

    	for(int i = 0; i<n-1; i++)
    	{
    		long pos = 0, flag = 0;
    		while(arr[i][pos] == arr[i+1][pos])
    		{
    			//cout << pos << " ";
    			pos += 1;
    			if(pos >= arr[i].size() || pos >= arr[i+1].size())
    			{

    				pos = 0;
    				flag = 1;
    			}

    			if(flag)
    				break;

    		}

    		if(flag)
    		{
    			if(arr[i].size() > arr[i+1].size())
    			{
    				cout << "-1\n";
    				return 0;
    			}
    		}
    		else
    		{
    			graph[arr[i][pos]].pb(arr[i+1][pos]);
    			indeg[arr[i+1][pos]]++;
    		}
    	}

    	/*for(int i = 0; i<graph.size(); i++)
    	{
    		cout << i << "\t";
    		for(auto j : graph[i])
    			cout << j << " ";
    		cout << "\n";
    	}

    	for(int i = 0; i<k; i++)
    		cout << indeg[i] << " ";
    	cout << "\n";
*/

    	if(cycle())
    	{
    		cout << "-1\n";
    		return 0;
    	}

    	else
    		minTS();
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