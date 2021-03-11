#include<iostream>
#include<fstream>
#include"Graph.h"
#include"DepthFirstSearch.h"
#include"DepthFisrtPaths.h"
#include"BreadthFirstPaths.h"

using namespace std;

int main()
{
	/**********************��ȡ�ļ�����������ͼ**********************/
	ifstream infile("data.txt");
	Graph myG(infile);
	myG.PrintGraph();
	cout << "E is " << myG.Enum() << endl;
	infile.close();


	/********************DepthFirstSearch.h����********************/
	/*DepthFirstSearch search(myG, 0);
	for (int v = 0; v < myG.Vnum(); ++v)
		if (search.isMakered(v))
			cout << v << " ";
	cout << "\nsearch's count is " << search.getCount() << endl;
	if (search.getCount() != myG.Vnum())
		cout << "NOT ";
	cout << "Connected" << endl; */


	/*******************DepthFisrtPaths.h����**********************/
	//int beg = 0;
	//DepthFirstPaths search(myG, beg);
	//for (int i = 0; i < myG.Vnum(); ++i)
	//{
	//	cout << beg << "-to-" << i << "-:-";
	//	if (search.hasPathTo(i))
	//	{
	//		//Path��鶯̬�ڴ�ʲôʱ���ͷź��ʣ�
	//		stack<int>* Path = search.pathTO(i);
	//		while (!Path->empty())
	//		{
	//			auto elem = Path->top();
	//			if (elem == beg) cout << elem;
	//			else cout << "-" << elem;
	//			Path->pop();
	//		}
	//		//Ϊʲô��delete���������delete[]?
	//		//��ΪPathָ����ڴ棬�Ѿ���ջstack��pop()�����ɾ����ֻʣ��һ��ͷ����ˣ��ڴ���ֻ��һ��Ԫ����
	//		delete Path;
	//	}
	//	cout << endl;
	//}

	/******************BreadthFirstPaths.h����********************/
	int beg = 0;
	BreadthFirstPaths search(myG, beg);
	for (int i = 0; i < myG.Vnum(); ++i)
	{
		cout << beg << "-to-" << i << "-:-";
		if (search.hasPathTo(i))
		{
			//Path��鶯̬�ڴ�ʲôʱ���ͷź��ʣ�
			stack<int>* Path = search.pathTO(i);
			while (!Path->empty())
			{
				auto elem = Path->top();
				if (elem == beg) cout << elem;
				else cout << "-" << elem;
				Path->pop();
			}
			//Ϊʲô��delete���������delete[]?
			//��ΪPathָ����ڴ棬�Ѿ���ջstack��pop()�����ɾ����ֻʣ��һ��ͷ����ˣ��ڴ���ֻ��һ��Ԫ����
			delete Path;
		}
		cout << endl;
	}
	return 0;
}