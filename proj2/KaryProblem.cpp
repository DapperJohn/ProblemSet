#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <time.h>

//John Anny and Selby Kendrick
//CSC 3102 Sect 001
//November 5th, 2013
//Problem #2
//
//Description:
//k-ary heap is to be implemented using an array, as min-priority queue.
//Methods insert and extract-min are supported.


using namespace std;

class krayheap
{
	private:
		int ascend(int descend);
		void krayheapifyup(int pos);
		void krayheapifydown(int pos);
		int left(int ascend);
		int right(int ascend);
	public:
		krayheap();
		krayheap(int k);
		int size()
		{
			return heap.size();
		}
		void insert(int element);
		int extract_min();
	private:
		vector<int> heap; //here // i have no idea
};

krayheap::krayheap()
{
}

int krayheap::ascend(int descend)
{
	if (descend != 0) {
		int i = (descend - 1) >> 1;
		return i;
	}
	return -1;
}

void krayheap::insert(int element)
{
	heap.push_back(element);
	krayheapifyup(heap.size() - 1);
}

int krayheap::extract_min()
{
	int min = heap.front();
	heap[0] = heap.at(heap.size() - 1);
	heap.pop_back();
	krayheapifydown(0);
	return min;
}



void krayheap::krayheapifyup(int pos)
{
	while ((pos > 0) && (ascend(pos) >= 0) && (heap[ascend(pos)] > heap[pos])) {
		int tmp = heap[ascend(pos)];
		heap[ascend(pos)] = heap[pos];
		heap[pos] = tmp;
		pos = ascend(pos);
	}
}

void krayheap::krayheapifydown(int pos)
{
	int descend = left(pos);
	if ((descend > 0) && (right(pos) > 0) && (heap[descend] > heap[right(pos)])) {
		descend = right(pos);
	}
	if (descend > 0) {
		int tmp = heap[pos];
		heap[pos] = heap[descend];
		heap[descend] = tmp;
		krayheapifydown(descend);
	}
}

int krayheap::left(int ascend)
{
	int i = (ascend << 1) + 1;
	if (i < heap.size()) {
		return i;
	} else {
		return -1;
	}
	return -1;
}

int krayheap::right(int ascend)
{
	int i = (ascend << 1) + 2;
	if (i < heap.size()) {
		return i;
	} else {
		return -1;
	}
	return -1;
}

int main()
{
	krayheap * mykrayheap = new krayheap();
	const int SIZE = 3;
	char input[SIZE];
	ifstream datafile;
	datafile.open("input.txt");
	int temp;
	clock_t t1, t2;
	t1 = clock();
	while (datafile.eof() == false) {
		datafile >> input;
		if (input[0] == 'I') {
			datafile >> input;
			temp = atoi(input);
			mykheap->insert(temp);
		} else if (input[0] == 'E')
			cout << mykheap->extract_min() << endl;
	}
	t2 = clock();
	float diff((float)t2 - (float)t1);
	float miseconds = (diff / CLOCKS_PER_SEC) * 1000000;
	cout << "Microseconds: " << miseconds << endl;
}
