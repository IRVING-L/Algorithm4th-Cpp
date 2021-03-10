#pragma once
#include<iostream>
#include<string>
using namespace std;
//删除最大元素和插入新元素的优先队列，基于二叉堆实现
class MaxPQ
{
	typedef string KeyType;
public:
	//构造函数
	MaxPQ():pq(new KeyType) {}
	MaxPQ(int M)
	{
		pq = new KeyType[2*M + 1];
		N = M;
	}
	MaxPQ(KeyType* arr, int size)
	{
		pq = new KeyType[2*size + 1]{};
		for (int i = 0; i < size; ++i) pq[i + 1] = arr[i];
		N = size;
	}
	//成员函数
	bool isEmpty() { return N == 0; }
	int size() { return N; }
	void insert(KeyType v)
	{
		pq[++N] = v;
		swim(N);
	}
	KeyType delMax()
	{
		KeyType max = pq[1];
		exch(1, N--);
		sink(1);
		return max;
	}
	void Print()
	{
		for (int i = 0; i < N; ++i) cout << pq[i + 1] << " ";
		cout << endl;
	}
private:
	KeyType* pq;
	int N = 0;
	void swim(int k)
	{
		while (k > 1 && pq[k] > pq[static_cast<int>(k / 2)])
		{
			exch(k, static_cast<int>(k / 2));
			k = k / 2;
		}
	}
	void sink(int k)
	{
		while (2 * k <= N)
		{
			int j = 2 * k;
			if (j < N && pq[j] < pq[j + 1]) ++j;
			if (pq[k] > pq[j]) break;
			exch(k, j);
			k = j;
		}
	}
	void exch(int i, int j)
	{
		int pos1 = i, pos2 = j;
		KeyType temp = pq[pos1];
		pq[pos1] = pq[pos2];
		pq[pos2] = temp;
	}
};