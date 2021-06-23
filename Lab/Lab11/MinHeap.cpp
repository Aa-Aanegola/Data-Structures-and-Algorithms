#include<bits/stdc++.h>
#define long long long
#define SIZE (long)(1e5 + 5)


using namespace std;


class MinHeap
{
	long data[SIZE];
	long size;

public:
	MinHeap()
	{
		size = 0;
	}
	void insert(long value);
	void del(long value);
	long extract_min();
	void heapify(long i);
	long return_min();
	void print();
};


void MinHeap::insert(long value)
{
	data[++size] = value;
	long pos = size;
	while(pos != 1)
	{
		if(data[pos] < data[pos/2])
			swap(data[pos], data[pos/2]);
		else
			break;
		pos /= 2;
	}
}

long MinHeap::extract_min()
{
	long ret = data[1];
	data[1] = data[size];
	size --;
	heapify(1);
	return ret;
}

void MinHeap::heapify(long i)
{
	long left = 2*i;
	long right = 2*i+1;
	long smallest = i;
	if(left <= size && data[left] < data[i])
		smallest = left;
	if(right <= size && data[right] < data[smallest])
		smallest = right;
	swap(data[smallest], data[i]);
	if(smallest != i)
		heapify(smallest);
}

long MinHeap::return_min()
{
	return data[1];
}

void MinHeap::print()
{
	for(int i = 1; i<=size; i++)
		cout << data[i] << " ";
	cout << "\n";
}

int main()
{
	MinHeap pq;
	pq.insert(1);
	pq.insert(10);
	pq.insert(6);
	pq.insert(-3);
	pq.print();
	cout << pq.extract_min() << "\n";
	pq.print();
	cout << pq.return_min() << "\n";
	pq.print();
	cout << pq.extract_min() << "\n";
	pq.print();
	cout << pq.extract_min() << "\n";
	pq.print();
	cout << pq.extract_min() << "\n";
	

	return 0;
}