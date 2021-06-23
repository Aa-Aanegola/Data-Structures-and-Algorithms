#include<iostream>
#include<vector>
#include<stack>
#define long long long


using namespace std;


int main()
{

	long n;
	cin >> n;
	long arr[n], maxl[n], maxr[n], minl[n], minr[n];
	for(long i = 0; i<n; i++)
	{
		cin >> arr[i];
		maxl[i] = 0;
		maxr[i] = 0;
		minl[i] = 0;
		minr[i] = 0;
	}
	stack<long> s1, s2;
	for(long i = 0; i<n; i++)
	{
		while(s1.size() && (arr[s1.top()] <= arr[i]))
		{
			maxl[i] += maxl[s1.top()] + 1;
			s1.pop();
		} 
		s1.push(i);
	//	cout<<maxl[i]<<" ";
	}
	//cout<<"\n";

	while(s1.size())
		s1.pop();
	

	for(int i = n-1; i >= 0; i--)
	{
		while(s1.size() && (arr[s1.top()] < arr[i]))
		{
			maxr[i] += maxr[s1.top()] + 1;
			s1.pop();
		}
		s1.push(i);
	//	cout<<maxr[i]<<" ";
	}
	//cout<<"\n";

	while(s1.size())
		s1.pop();

	long summax = 0;
	for(int i = 0; i<n; i++)
		summax += (maxl[i] + 1) * (maxr[i] + 1) * arr[i];
	//cout<<summax<<"\n";


	for(long i = 0; i<n; i++)
	{
		while(s2.size() && (arr[s2.top()] >= arr[i]))
		{
			minl[i] += minl[s2.top()] + 1;
			s2.pop();
		} 
		s2.push(i);
	//	cout<<minl[i]<<" ";
	}
	//cout<<"\n";

	while(s2.size())
		s2.pop();
	

	for(int i = n-1; i >= 0; i--)
	{
		while(s2.size() && (arr[s2.top()] > arr[i]))
		{
			minr[i] += minr[s2.top()] + 1;
			s2.pop();
		}
		s2.push(i);
	//	cout<<minr[i]<<" ";
	}
	//cout<<"\n";

	long summin = 0;
	for(int i = 0; i<n; i++)
		summin += (minl[i] + 1) * (minr[i] + 1) * arr[i];
	//cout<<summin<<"\n";

	cout << summax - summin << "\n";
}