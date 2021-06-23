#include<bits/stdc++.h>
#define long long long
#define INF 100000000
#define SIZE (long)(1e6)
#define pl pair<long, long>
#define ff first
#define ss second


using namespace std;

vector<long> sorted, counter;
long arr[1000][1000];

class MinHeap
{
	vector<pl> data;
	long size;

public:
	MinHeap()
	{
		data.resize(SIZE);
		size = 0;
	}
	void insert(pl value);
	pl extract_min();
	void heapify(long i);
	pl return_min();
	void print();
};


void MinHeap::insert(pl value)
{
	data[++size] = value;
	long pos = size;
	while(pos != 1)
	{
		if(data[pos].ff < data[pos/2].ff)
			swap(data[pos], data[pos/2]);
		else
			break;
		pos /= 2;
	}
}

pl MinHeap::extract_min()
{
	pl ret = data[1];
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
	if(left <= size && data[left].ff < data[i].ff)
		smallest = left;
	if(right <= size && data[right].ff < data[smallest].ff)
		smallest = right;
	swap(data[smallest], data[i]);
	if(smallest != i)
		heapify(smallest);
}

pl MinHeap::return_min()
{
	return data[1];
}

void MinHeap::print()
{
	for(int i = 1; i<=size; i++)
		cout << data[i].ff << " ";
	cout << "\n";
}


int main()
{
	int N, K;
	cin >> K >> N;
	
	for(int i = 0; i<K; i++)
		for(int j = 0; j<N; j++)
			cin >> arr[i][j];

	MinHeap H;

	for(int i = 0; i<K; i++)
		H.insert({arr[i][0], (long)i});

	for(int i = 0; i<K; i++)
		counter.push_back(1);

	for(int i = 0; i< N*K; i++)
	{
		pl node = H.extract_min();
		sorted.push_back(node.ff);
		long arrno = node.ss;
		if(counter[arrno] < N)
		{
			H.insert({arr[arrno][counter[arrno]], arrno});
			counter[arrno] += 1;
		}
	}

	for(int i = 0; i<sorted.size(); i++)
		cout << sorted[i] << " ";
	cout << "\n";
}