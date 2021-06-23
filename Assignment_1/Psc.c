#include<stdio.h>


int main()
{
	int t, arr[105];
	scanf("%d",&t);
	while(t--)
	{
		for(int i = 0; i<105; i++)
			arr[i] = 0;
		int n,flag = 0, stack[105],top = -1, c = 1;
		scanf("%d",&n);
		for(int i = 0; i<n; i++)
			scanf("%d",&arr[i]);
			//arr[i] = i+1;
			
		//arr[50] = arr[2];
		//arr[2] = 51;

		for(int i = 0; i<n; i++)
		{
			if(arr[i] == c)
				c++;
			else
			{
				if(top != -1 && stack[top] == c)
				{
					c++;
					top--;
					i--;
				}
				else
				{
					stack[++top] = arr[i];
				}
			}
			/*printf("Stack: ");
			for(int j = 0; j<=top; j++)
				printf("%d ",stack[j]);
			printf("\n");*/
		}
		

		for(int i = top; i>0; i--)
			if(stack[i] > stack[i-1] && stack[i-1] != 0)
			{	
				flag = 1;
				break;
			}
		

		if(flag == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}