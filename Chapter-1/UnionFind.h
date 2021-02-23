#pragma once
#include<iostream>
using namespace std;
#define N 10
class UF
{
public:
	//构造函数，完成分量的初始化工作
	UF() 
	{
		m_count = N;
		id = new int[N];
		for (int i = 0; i < N; ++i) id[i] = i;
	}
	int count() { return m_count; }
	bool connect(int p, int q) { return find(p) == find(q); }
	void Print()
	{
		cout << "num: ";
		for (int i = 0; i < N; ++i) cout << i << " ";
		cout << "\nval: ";
		for (int i = 0; i < N; ++i) cout << id[i] << " ";
		cout << endl;
	}
	virtual int find(int p) = 0;
	virtual void _union(int p, int q) = 0;
protected:
	int* id;//分量id，int型指针，指向一个堆区的数组
	int m_count;//分量数量
};
//第一种算法：quick_find
class QuickFindUF :public UF
{
public:
	QuickFindUF(){}//会自动调用基类的构造函数完成对从基类继承下来的成员的初始化
	int find(int p) override { return id[p]; }
	void _union(int p, int q) override
	{
		int pID = find(p);
		int qID = find(q);
		//如果p和q的元素值不相等，代表两个元素还未形成连通关系
		if (pID != qID)
		{
			for (int i = 0; i < N; ++i)
				if (id[i] == pID) id[i] = qID;
			--m_count;
		}
	}
};
//第二种算法：quick_union
class QuickUnionUF :public UF
{
public:
	//构造函数
	QuickUnionUF() {}
	int find(int p) override
	{
		//找根结点：只有根结点的元素，元素值等于本身在数组中的位置，也就是p == id[p]
		//不是根结点都不满足这个条件
		//p = id[p] 类似于链表中的 p = p->next
		while (p != id[p]) p = id[p];
		return p;
	}
	void _union(int p, int q) override
	{
		int pROOT = find(p);
		int qROOT = find(q);
		if (pROOT != qROOT)
		{
			id[pROOT] = qROOT;
			--m_count;
		}
	}
};
//第三种算法：带权的quick_union算法
class WeightQuickUnionUF :public UF
{
public:
	//构造函数
	WeightQuickUnionUF() 
	{
		sz = new int[N];
		for (int i = 0; i < N; ++i) sz[i] = 1;
	}
	int find(int p) override
	{
		//找根结点：只有根结点的元素，元素值等于本身在数组中的位置，也就是p == id[p]
		//不是根结点都不满足这个条件
		//p = id[p] 类似于链表中的 p = p->next
		while (p != id[p]) p = id[p];
		return p;
	}
	void _union(int p, int q) override
	{
		int pROOT = find(p);
		int qROOT = find(q);
		if (pROOT != qROOT)
		{
			if (sz[pROOT] < sz[qROOT])
			{
				id[pROOT] = qROOT;
				sz[qROOT] += sz[pROOT];
			}
			else
			{
				id[qROOT] = pROOT;
				sz[pROOT] += sz[qROOT];
			}
			--m_count;
		}
	}
private:
	int* sz;
};