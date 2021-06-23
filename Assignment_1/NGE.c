#include<stdio.h>
#define long long long


int main()
{
	long n;
	scanf("%lld",&n);
	long arr[n], stack[n], top = -1, nge[n][2];
	for(long i = 0; i<n; i++)
	{
		scanf("%lld",&arr[i]);
		nge[i][0] = 0;
		nge[i][1] = 0;
	}
	

	for(int i = n-1; i>=0; i--)
	{
		while((top != -1) && (stack[top] <= arr[i]))
			top--;
		if(top == -1)
			;
		else
			nge[i][0] = stack[top];
		stack[++top] = arr[i];
	}
	

	top = -1;
	for(int i = 0; i<n; i++)
	{
		while((top != -1) && (stack[top] <= arr[i]))
			top--;
		if(top == -1)
			;
		else
			nge[i][1] = stack[top];
		stack[++top] = arr[i];
	}
	//for(int i = 0; i<n; i++)
	//	printf("%lld %lld\n",nge[i][0], nge[i][1]);

	long prod,max = -10000;
	for(int i = 0; i<n; i++)
	{
		prod = nge[i][0] * nge[i][1];
		//printf("%lld",max);
		if(prod > max)
			max = prod;
	}
	printf("%lld\n",max);
}