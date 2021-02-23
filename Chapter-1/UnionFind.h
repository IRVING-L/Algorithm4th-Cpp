#pragma once
#include<iostream>
using namespace std;
#define N 10
class UF
{
public:
	//���캯������ɷ����ĳ�ʼ������
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
	int* id;//����id��int��ָ�룬ָ��һ������������
	int m_count;//��������
};
//��һ���㷨��quick_find
class QuickFindUF :public UF
{
public:
	QuickFindUF(){}//���Զ����û���Ĺ��캯����ɶԴӻ���̳������ĳ�Ա�ĳ�ʼ��
	int find(int p) override { return id[p]; }
	void _union(int p, int q) override
	{
		int pID = find(p);
		int qID = find(q);
		//���p��q��Ԫ��ֵ����ȣ���������Ԫ�ػ�δ�γ���ͨ��ϵ
		if (pID != qID)
		{
			for (int i = 0; i < N; ++i)
				if (id[i] == pID) id[i] = qID;
			--m_count;
		}
	}
};
//�ڶ����㷨��quick_union
class QuickUnionUF :public UF
{
public:
	//���캯��
	QuickUnionUF() {}
	int find(int p) override
	{
		//�Ҹ���㣺ֻ�и�����Ԫ�أ�Ԫ��ֵ���ڱ����������е�λ�ã�Ҳ����p == id[p]
		//���Ǹ���㶼�������������
		//p = id[p] �����������е� p = p->next
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
//�������㷨����Ȩ��quick_union�㷨
class WeightQuickUnionUF :public UF
{
public:
	//���캯��
	WeightQuickUnionUF() 
	{
		sz = new int[N];
		for (int i = 0; i < N; ++i) sz[i] = 1;
	}
	int find(int p) override
	{
		//�Ҹ���㣺ֻ�и�����Ԫ�أ�Ԫ��ֵ���ڱ����������е�λ�ã�Ҳ����p == id[p]
		//���Ǹ���㶼�������������
		//p = id[p] �����������е� p = p->next
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