#include<iostream>

using namespace std;


int main()
{	
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
		cin>>arr[i];
	int k;
	cin>>k;
	int wind[k], sum = 0, max = 0, f = 0, r = k;
	for(int i = 0; i<k; i++)
		sum += arr[i];
	if(sum>max)
		max = sum;
	while(r<n)
	{
		sum -= arr[f];
		f++;
		sum += arr[r];
		r++;
		if(sum > max)
			max = sum; 
	}
	cout<<"Max: "<<max<<"\n";
}