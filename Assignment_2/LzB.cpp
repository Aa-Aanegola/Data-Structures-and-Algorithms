#include<iostream>
#include<vector>

using namespace std;

vector<int> arr, vis, ans, par;
int cyc_start;
void check_cycle(int x)
{
	if(vis[x] == 2)
		return;
	else if(vis[x] == 1)
	{
		vis[x] = 2;
		ans[x] = x;
		int temp = par[x];
		while(temp != x)
		{
			//cout<<"here";
			ans[temp] = temp;
			temp = par[temp];
		}
		return;
	}
	else
	{
		par[arr[x]] = x;
		vis[x] = 1;
		check_cycle(arr[x]);
		vis[x] = 2;
	}
	return;
}


int fin_search(int x)
{
	//cout<<x<<"  ";
	if(ans[x] == 0)
		ans[x] = fin_search(arr[x]);
	return ans[x];
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		arr.clear();
		ans.clear();
		vis.clear();
		par.clear();
		int n;
		cin>>n;
		arr.resize(n+1);
		vis.resize(n+1, 0);
		ans.resize(n+1, 0);
		par.resize(n+1, 0);
		for(int i = 1; i<=n; i++)
			cin>>arr[i];
		for(int i = 1; i<=n; i++)
		{
			//cout<<i<<"\n";
			if(!vis[i])
			{
				check_cycle(i);
					//for(int i = 1; i<=n; i++)
					//	cout<<ans[i]<<" ";
					//cout<<"\n";
				//cout<<"cycle detected\n";
			}
			if(!ans[i])
			{
				//cout<<"no cycle\n";
				fin_search(i);
			}
		}	
		for(int i = 1; i<=n; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
}