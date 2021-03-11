#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;

class CC
{
private:
	bool* marked;//�������
	int* id;
	int count;
	//��Ա����
	void dfs(Graph& G, int v)
	{
		marked[v] = true;
		id[v] = count;
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			if (!marked[it->val]) dfs(G, it->val);
			it = it->next;
		}
	}
public:
	//���캯��
	CC(Graph& G)
	{
		//��������ʼ����������marked
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		id = new int[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) id[i] = 0;
		count = 0;
		for (int s = 0; s < G.Vnum(); ++s)
		{
			if (!marked[s])
			{
				dfs(G, s);
				++count;
			}
		}
	}
	~CC()
	{
		delete[] marked;
		delete[] id;
	}
	//��Ա����
	bool connected(int v, int w) { return id[v] == id[w]; }
	int getId(int v) { return id[v]; }
	int getCount() { return count; }
};