#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"Graph.h"
using namespace std;

class BreadthFirstPaths
{
private:
	bool* marked;//标记数组
	int* edgeTo;//记录访问顶点到图的访问起点的路径。用数组保存双亲结点的位置坐标，同UnionFind算法
	int s;//图遍历起点
	//广度优先遍历函数
	void bfs(Graph& G, int s)
	{
		queue<int> Q;
		marked[s] = true;
		Q.push(s);
		while (!Q.empty())
		{
			int par = Q.front();
			Q.pop();
			auto it = G.adjData(par).getRoot()->next;
			while (it)
			{
				if (!marked[it->val])
				{
					edgeTo[it->val] = par;
					marked[it->val] = true;
					Q.push(it->val);
				}
				it = it->next;
			}
		}
	}
public:
	//构造函数
	BreadthFirstPaths(Graph& G, int v)
	{
		//创建并初始化堆区数组marked
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		//创建并初始化堆区数组edgeTo
		edgeTo = new int[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) edgeTo[i] = 0;
		s = v;
		bfs(G, v);
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