#pragma once
#include<iostream>
#include<fstream>
#include"Bag.h"
using namespace std;

class Graph
{
private:
	int V;//顶点数目
	int E;//边的数目
	Bag<int>* adj;//指向动态数组的指针adj，数组的元素类型是Bag背包
	
public:
	//构造函数
	Graph(int Vnum)
	{
		V = Vnum;
		E = 0;
		//adj是指向堆区数组首地址的指针，数组元素的数据类型是Bag<int>
		//在创建堆区数组的时候，多加了一个花括号{}，可以调用Bag<int>对象的无参构造函数，完成堆区数组元素的初始化
		adj = new Bag<int>[V] {};
	}
	Graph(ifstream& infile)
	{
		E = 0;
		infile >> V ;//从文件中读取顶点数
		adj = new Bag<int>[V] {};
		int v, w;
		while (infile >> v >> w) addEdge(v, w);
	}
	//成员函数，用两个顶点创建一条边
	void addEdge(int v, int w)
	{
		adj[v].add(w);
		adj[w].add(v);
		++E;
	}
	//打印邻接表的无向图，第一列是无向图的顶点，紧跟着的是与该顶点相邻的顶点们
	void PrintGraph()
	{
		for (int i = 0; i < V; ++i)
		{
			cout << i << ": ";
			adj[i].BagPrint(cout);
		}
	}
	int Vnum() { return V; }//对外接口：返回类中的顶点数
	int Enum() { return E; }//对外接口：返回类中的边数
	auto adjData(int v) { return adj[v]; }//对外接口：返回指定顶点v所相邻的顶点们，用背包Bag存储的
};