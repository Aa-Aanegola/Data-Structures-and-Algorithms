#include<iostream>

using namespace std;

int main()
{
	char str[20];
	cin>>str;
	char stack[20];
	int top = -1, i = 0, flag = 0;
	while(str[i] != '\0')
	{
		if(top != -1)
		{	
			if(str[i] == ')')
			{
				if(stack[top] == '(')
					top--;
				else
				{
					flag = 1;
					break;
				}
			}
			if(str[i] == '}')
			{
				if(stack[top] == '{')
					top--;
				else
				{
					flag = 1;
					break;
				}
			}
			if(str[i] == ']')
			{
				if(stack[top] == '[')
					top--;
				else
				{
					flag = 1;
					break;
				}
			}
		}
		else if(top == -1 && (str[i] == ')' || str[i] == ']' || str[i] == '}'))
		{
			flag = 1;
			break;
		}
		else
			stack[++top] = str[i];
		i++;
	}
	if(top == -1 && flag == 0)
		cout<<"Valid\n";
	else
		cout<<"Invalid\n";
}