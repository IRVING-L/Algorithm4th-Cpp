#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;

class CC
{
private:
	bool* marked;//标记数组
	int* id;
	int count;
	//成员函数
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
	//构造函数
	CC(Graph& G)
	{
		//创建并初始化堆区数组marked
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
	//成员函数
	bool connected(int v, int w) { return id[v] == id[w]; }
	int getId(int v) { return id[v]; }
	int getCount() { return count; }
};