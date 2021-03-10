#pragma once
#include<iostream>
#include<stack>
#include"Graph.h"
using namespace std;

class DepthFirstPaths
{
private:
	bool* marked;//标记数组
	int* edgeTo;//记录访问顶点到图的访问起点的路径。用数组保存双亲结点的位置坐标，同UnionFind算法
	int s;//图遍历起点
	void dfs(Graph& G, int v)
	{
		marked[v] = true;//访问了该顶点，便将该顶点对应位置的marked数组做标记
		//it的数据类型是BagNode*，指向顶点v的背包Bag的第一个元素
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			if (!marked[it->val]) 
			{
				//没有被访问过得顶点，在递归访问前，用数组edgeTo保存其双亲结点
				edgeTo[it->val] = v;
				dfs(G, it->val);
			}
			it = it->next;
		}
	}
public:
	//构造函数
	DepthFirstPaths(Graph& G, int v)
	{
		//创建并初始化堆区数组marked
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		//创建并初始化堆区数组edgeTo
		edgeTo = new int[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) edgeTo[i] = 0;
		s = v;
		//深度优先遍历函数
		dfs(G, s);
	}
	//成员函数
	bool hasPathTo(int v) { return marked[v]; }//判断顶点是否被访问过
	//用栈保存从起点到某顶点v的遍历路径，栈是创建在堆区的，用指针指向其首地址，可以返回其首地址
	stack<int>* pathTO(int v)
	{
		//v代表终点，s是起点
		if (!hasPathTo(v)) return nullptr;//
		stack<int>* path = new stack<int>;
		for (int x = v; x != s; x = edgeTo[x])
			path->push(x);
		path->push(s);
		return path;
	}
};