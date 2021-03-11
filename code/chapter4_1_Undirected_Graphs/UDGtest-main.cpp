#include<iostream>
#include<fstream>
#include"Graph.h"
#include"DepthFirstSearch.h"
#include"DepthFisrtPaths.h"
#include"BreadthFirstPaths.h"
#include"CC.h"
#include"Bag.h"
#include"Cycle.h"

using namespace std;

int main()
{
	/**********************读取文件，创建无向图**********************/
	ifstream infile("data.txt");
	Graph myG(infile);
	myG.PrintGraph();
	cout << "E is " << myG.Enum() << endl;
	infile.close();


	/********************DepthFirstSearch.h测试********************/
	/*DepthFirstSearch search(myG, 0);
	for (int v = 0; v < myG.Vnum(); ++v)
		if (search.isMakered(v))
			cout << v << " ";
	cout << "\nsearch's count is " << search.getCount() << endl;
	if (search.getCount() != myG.Vnum())
		cout << "NOT ";
	cout << "Connected" << endl; */


	/*******************DepthFisrtPaths.h测试**********************/
	//int beg = 0;
	//DepthFirstPaths search(myG, beg);
	//for (int i = 0; i < myG.Vnum(); ++i)
	//{
	//	cout << beg << "-to-" << i << "-:-";
	//	if (search.hasPathTo(i))
	//	{
	//		//Path这块动态内存什么时候释放合适？
	//		stack<int>* Path = search.pathTO(i);
	//		while (!Path->empty())
	//		{
	//			auto elem = Path->top();
	//			if (elem == beg) cout << elem;
	//			else cout << "-" << elem;
	//			Path->pop();
	//		}
	//		//为什么是delete命令，而不是delete[]?
	//		//因为Path指向的内存，已经被栈stack的pop()命令给删除到只剩下一个头结点了，内存中只有一个元素了
	//		delete Path;
	//	}
	//	cout << endl;
	//}

	/******************BreadthFirstPaths.h测试********************/
	//int beg = 0;
	//BreadthFirstPaths search(myG, beg);
	//for (int i = 0; i < myG.Vnum(); ++i)
	//{
	//	cout << beg << "-to-" << i << "-:-";
	//	if (search.hasPathTo(i))
	//	{
	//		//Path这块动态内存什么时候释放合适？
	//		stack<int>* Path = search.pathTO(i);
	//		while (!Path->empty())
	//		{
	//			auto elem = Path->top();
	//			if (elem == beg) cout << elem;
	//			else cout << "-" << elem;
	//			Path->pop();
	//		}
	//		//为什么是delete命令，而不是delete[]?
	//		//因为Path指向的内存，已经被栈stack的pop()命令给删除到只剩下一个头结点了，内存中只有一个元素了
	//		delete Path;
	//	}
	//	cout << endl;
	//}

	/***************************CC.h测试**************************/
	/*CC cc(myG);

	int M = cc.getCount();
	cout << M << " component " << endl;

	Bag<int>* components = new Bag<int>[M] {};

	for (int v = 0; v < myG.Vnum(); ++v)
		components[cc.getId(v)].add(v);

	for (int i = 0; i < M; ++i)
	{
		auto it = components[i].getRoot()->next;
		while (it)
		{
			cout << it->val << " ";
			it = it->next;
		}
		cout << endl;
	}

	delete[] components;*/

	/***************************Cycle.h测试**************************/
	Cycle c(myG);
	c.isCycle() ? (cout << "has cycle" << endl) : (cout << "no cycle" << endl);

	return 0;
}