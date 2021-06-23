#include<bits/stdc++.h>
#define long long long
#define INF (long)(1e14)
#define pi pair<int, int>
#define ff first
#define ss second


using namespace std;



int main()
{
	int n, m, d, l;
	cin >> n >> m >> d >> l;
	char mat[n+1][m+1];
	long dis[n+1][m+1][n+1][m+1];
	
	for(int i = 1; i<n+1; i++)
		for(int j = 1; j<m+1; j++)
			for(int k = 1; k<n+1; k++)
				for(int l1 = 1; l1<m+1; l1++)
					dis[i][j][k][l1] = INF;
	
	for(int i = 1; i<n+1; i++)
	{
		for(int j = 1; j<m+1; j++)
		{
			dis[i][j][i][j] = 0;
			if(i-1 > 0)
				dis[i][j][i-1][j] = 1;
			if(j-1 > 0)
				dis[i][j][i][j-1] = 1;
			if(i+1 <= n)
				dis[i][j][i+1][j] = 1;
			if(j+1 <= m)
				dis[i][j][i][j+1] = 1;
		}
	}

	for(int i = 1; i<n+1; i++)
		for(int j = 1; j<m+1; j++)
			mat[i][j] = 'S';

	for(int i = 0; i<d; i++)
	{
		int x, y;
		cin >> x >> y;
		mat[x][y] = 'D';
		for(int j = 1; j<n+1; j++)
			for(int k = 1; k<m+1; k++)
				dis[j][k][x][y] = -1;
	}

	int c = 0, flag = 0;

	vector<pi> live;

	for(int i = 0; i<l; i++)
	{
		int x, y;
		cin >> x >> y;
		if(mat[x][y] == 'D')
			flag = 1;
		if(mat[x][y] == 'L')
		{
			c++;
			continue;
		}
		mat[x][y] = 'L';
		live.push_back({x,y});
	}

	l-= c;
	int arr[l];
	for(int i = 0; i<l; i++)
		arr[i] = i;

	if(flag || (mat[n][m] == 'D' || mat[1][1] == 'D'))
	{	
		cout << "-1\n";
		return 0;
	}
	
	else
	{
		for(int a = 1; a<n+1; a++)
		{
			for(int b = 1; b<m+1; b++)
			{
				for(int c = 1; c<n+1; c++)
				{
					for(int d = 1; d<m+1; d++)
					{
						for(int e = 1; e<n+1; e++)
						{
							for(int f = 1; f<m+1; f++)
							{
								if(dis[a][b][e][f] == -1 || dis[c][d][a][b] == -1 || dis[c][d][e][f] == -1)
									;
								else
								{
									if(dis[c][d][a][b] + dis[a][b][e][f] < dis[c][d][e][f])
										dis[c][d][e][f] = dis[c][d][a][b] + dis[a][b][e][f];
								}

							}
						}
					}
				}	
			}
		}


		/*for(int i = 1; i<n+1; i++)
		{
			for(int j = 1; j<m+1; j++)
			{
				for(int k = 1; k<n+1; k++)
				{
					for(int l = 1; l<m+1; l++)
						cout << dis[i][j][k][l] << " ";
					cout << "\n";
				}
				cout << "\n\n";
			}
		}*/

		if(l == 0)
		{
			if(dis[1][1][n][m] >= INF)
				dis[1][1][n][m] = -1;
			cout << dis[1][1][n][m] << "\n";
			return 0;
		}

		else
		{
			long count = 1, min = INF;
			for(int i = 1; i<=l; i++)
				count *= i;
			long dist = 0;

			for(int i = 0; i<count; i++)
			{
				dist = 0;
				pi cur = live[arr[0]];
				pi next;
				//cout << cur.ff << " " << cur.ss << "\n";
				dist = dis[1][1][cur.ff][cur.ss];
				//cout << dist << "\n";
				for(int j = 1; j<l; j++)
				{
					next = live[arr[j]];
					dist += dis[cur.ff][cur.ss][next.ff][next.ss];
				//	cout << cur.ff << " " << cur.ss << "  " << next.ff << " " << next.ss << " " << dist<< "\n";
					cur = next;
				}
				dist += dis[live[arr[l-1]].ff][live[arr[l-1]].ss][n][m];
				//cout << live[arr[l-1]].ff << " " << dist << "\n";
				if(dist < min)
					min = dist;
				next_permutation(arr, arr+l);

			}

			if(min >= INF)
				cout << "-1\n";
			else
				cout << min << "\n";
		}
	}
}