#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> numconnected[100006];
	int college[n+5], colmin = 1000000;
	for(int i =1; i<n+1; i++)
	{
		cin >> college[i];
		if(college[i] < colmin)
			colmin = college[i];
	}
	for(int i = 1; i<n+1; i++)
	{
		if(!numconnected[college[i]].size())
			numconnected[college[i]].push_back(college[i]);
	}
	int x,y,cx,cy, flag;
	for(int i = 1; i<m+1; i++)
	{
		cin >> x >> y;
		cx = college[x];
		cy = college[y];
		flag = 0;
		//cout<< i <<" "<< x << ":" << cx <<" "<<y <<":"<< cy<<"\n";
		for(int j = 0; j<numconnected[cx].size(); j++)
			if(numconnected[cx][j] == cy)
			{	
				flag = 1;
				break;
			}
		if(!flag)
			numconnected[cx].push_back(cy);
		flag = 0;
		for(int j = 0; j<numconnected[cy].size(); j++)
			if(numconnected[cy][j] == cx)
			{	
				flag = 1;
				break;
			}
		if(!flag)
			numconnected[cy].push_back(cx);
	}
	
	int curmax = 0, max = 1;
	for(int i = 100005; i>=colmin ;i--)
	{
		if(numconnected[i].size() >= curmax)
		{	
			curmax = numconnected[i].size();
			max = i;
		}
	}
	cout << max << "\n";
}