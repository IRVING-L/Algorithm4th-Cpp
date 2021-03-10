#pragma once
#include<iostream>
#include<fstream>
#include"Bag.h"
using namespace std;

class Graph
{
private:
	int V;//������Ŀ
	int E;//�ߵ���Ŀ
	Bag<int>* adj;//ָ��̬�����ָ��adj�������Ԫ��������Bag����
	
public:
	//���캯��
	Graph(int Vnum)
	{
		V = Vnum;
		E = 0;
		//adj��ָ����������׵�ַ��ָ�룬����Ԫ�ص�����������Bag<int>
		//�ڴ������������ʱ�򣬶����һ��������{}�����Ե���Bag<int>������޲ι��캯������ɶ�������Ԫ�صĳ�ʼ��
		adj = new Bag<int>[V] {};
	}
	Graph(ifstream& infile)
	{
		E = 0;
		infile >> V ;//���ļ��ж�ȡ������
		adj = new Bag<int>[V] {};
		int v, w;
		while (infile >> v >> w) addEdge(v, w);
	}
	//��Ա���������������㴴��һ����
	void addEdge(int v, int w)
	{
		adj[v].add(w);
		adj[w].add(v);
		++E;
	}
	//��ӡ�ڽӱ������ͼ����һ��������ͼ�Ķ��㣬�����ŵ�����ö������ڵĶ�����
	void PrintGraph()
	{
		for (int i = 0; i < V; ++i)
		{
			cout << i << ": ";
			adj[i].BagPrint(cout);
		}
	}
	int Vnum() { return V; }//����ӿڣ��������еĶ�����
	int Enum() { return E; }//����ӿڣ��������еı���
	auto adjData(int v) { return adj[v]; }//����ӿڣ�����ָ������v�����ڵĶ����ǣ��ñ���Bag�洢��
};