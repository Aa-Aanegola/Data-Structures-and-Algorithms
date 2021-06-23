#include<iostream>
#include<vector>
#include<deque>
#define long long long


using namespace std;


int main()
{
	long n;
	cin >> n;
	long arr[n], desired[n];
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	for(int i = 0; i<n; i++)
		cin >> desired[i];

	deque<long> stk;
	
	long count = 0;
	long steps = 0;

	if(arr[count] == desired[count])
		count += 1;
	else
	{
		if(arr[count] > desired[count])
		{
			stk.push_front(desired[count]);
			count += 1;
			steps += 1;
		}
		else
			; //condition for greater may be required?
	}
	while(count < n)
	{
		if(stk.size() != 0)
		{
			long max_deq = stk.back();
			long prev_checked = stk.front();
			if(max_deq <= arr[count])
			{
				if(prev_checked == desired[count])
					count += 1;
				else
				{
					if(prev_checked < desired[count])
						stk.pop_front();
					else
					{
						stk.push_front(desired[count]);
						count += 1;
						steps += 1;
					}
				}
			}
			else
				stk.pop_back();
		}
		else
		{
			if(arr[count] == desired[count])
				count += 1;
			else
			{
				if(arr[count] > desired[count])
				{	
					stk.push_front(desired[count]);
					count += 1;
					steps += 1;
				}
				else
					;
			}
		}
		//cout<<count<<"\n";
	}
	cout<<steps<<"\n";
}