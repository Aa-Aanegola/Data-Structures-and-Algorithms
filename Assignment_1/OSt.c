#include<stdio.h>
#define long long long
#define min(a,b) (a<b?a:b)


int main()
{
	long n;
	scanf("%lld",&n);
	long sum = 0, arr[n], nge[n][2], max = -10;
	for(long i = 0; i<n; i++)
	{
		scanf("%lld",&arr[i]);
		nge[i][0] = 0;
		nge[i][1] = 0;
	}

	for(int i = 1; i<n; i++)
	{
		if(arr[i-1] > max)
			max = arr[i-1];
		nge[i][0] = max;
	}

	max = -10;
	for(int i = n-2; i>=0; i--)
	{
		if(arr[i+1] > max)
			max = arr[i+1];
		if(arr[i] > max)
			max = arr[i];
		nge[i][1] = max;
	}

	nge[0][0] = 0;
	nge[n-1][1] = arr[n-1];
	//for(int i = 0; i<n; i++)
	//printf("%lld %lld\n",nge[i][0], nge[i][1]);
	for(int i = 0; i<n; i++)
		sum += min(nge[i][0],nge[i][1]);
	printf("%lld\n",sum);
}