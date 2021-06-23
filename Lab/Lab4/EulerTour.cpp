#include<iostream>
#include<vector>

using namespace std;

vector<int> arr[10000], converted;
int vis[10000];


void dfs(int x)
{
	vis[x] = 1;
	converted.push_back(x);
	for(int i = 0; i<arr[x].size(); i++)
	{
		if(!vis[arr[x][i]])
			dfs(arr[x][i]);
	}
	converted.push_back(x);
}


int main()
{
	for(int i = 0; i<10000; i++)
		vis[i] = 0;
	converted.clear();
	int n;
	cin >> n;
	int root;
	cin >> root;
	while(n--)
	{
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		if(a != b)
			arr[b].push_back(a);
	}
	dfs(root);
	for(int i = 0; i<converted.size(); i++)
		cout<<converted[i]<<" ";
	cout<<"\n";
}