#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;

class Cycle
{
private:
	bool* marked;//标记数组
	bool hasCycle;//标记
	void dfs(Graph& G, int v, int u)
	{
		marked[v] = true;
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			if (!marked[it->val]) dfs(G, it->val, v);
			else if (it->val != u) hasCycle == true;
			it = it->next;
		}
	}
public:
	Cycle(Graph& G)
	{
		//创建marked数组并将数组元素的值统一初始化为false
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		for (int s = 0; s < G.Vnum(); ++s)
		{
			if (!marked[s])
				dfs(G, s, s);
		}
	}
	~Cycle()
	{
		delete[] marked;
	}
	//成员函数
	bool isCycle() { return hasCycle; }
};