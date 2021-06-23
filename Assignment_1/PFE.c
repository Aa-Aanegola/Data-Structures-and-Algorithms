#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define long long long

int main()
{
	long t;
	scanf("%lld",&t);
	getchar();
	char str[10001];
	double stack[10001];
	while(t--)
	{
		scanf("%[^\n]%*c",str);
		long len = strlen(str), top = -1;
		for(long i = 0; i<len; i++)
		{
			if(str[i] == ' ')
				;
			else
			{
				if(str[i] >= '0' && str[i] <= '9')
				{
					double num = 0;
					while(str[i] != ' ')
					{
						num *= 10;
						num += str[i++] - 48;
					}
					stack[++top] = num;
					//printf("%lf ",stack[top]);
				}
				else
				{
					double a = stack[top--];
					double b = stack[top--];
					if(str[i] == '+')
						stack[++top] = a+b;
					if(str[i] == '-')
						stack[++top] = b-a;
					if(str[i] == '*')
						stack[++top] = a*b;
					if(str[i] == '/')
						stack[++top] = b/a;
				}
			}
		}
		printf("%lf\n",stack[top]);
		for(int i = 0; i<10001; i++)
			stack[i] = 0;
	}
}