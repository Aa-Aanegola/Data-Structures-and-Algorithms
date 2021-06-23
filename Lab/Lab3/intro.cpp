#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int mat[6][6];
	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<=i; j++)
		{
			cout<<"number of links between "<<i<<" and "<<j<<"\n";
			cin>>mat[i][j];
		}
	}
	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<=i; j++)
			cout<<mat[i][j]<<"\t";
		cout<<"\n";
	}
}