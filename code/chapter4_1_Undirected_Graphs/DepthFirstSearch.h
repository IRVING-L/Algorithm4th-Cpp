#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;
class DepthFirstSearch
{
private:
	bool* marked;//标记数组
	int count;//顶点个数统计
	//私有成员函数
	void dfs(Graph& G, int v)
	{
		marked[v] = true;//访问了该顶点，便将该顶点对应位置的marked数组做标记
		++count;
		//it的数据类型是BagNode*，指向顶点v的背包Bag的第一个元素
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			//如果it->val对应的顶点没有被访问，递归调用dfs访问该顶点
			if (!marked[it->val]) dfs(G, it->val);
			//如果被访问了，那就移动it指针，指向下一个相邻顶点
			it = it->next;
		}
	}
public:
	//构造函数
	DepthFirstSearch(Graph& G, int s)
	{
		//创建marked数组并将数组元素的值统一初始化为false
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		count = 0;
		//成员变量初始化完成后，进行递归，深度优先遍历无向图
		dfs(G, s);
	}
	~DepthFirstSearch()
	{
		delete[] marked;
	}
	//成员函数
	bool ismarked(int w) { return marked[w]; }//判断某顶点是否被访问
	int getCount() { return count; }//返回DFS遍历过得顶点数
};