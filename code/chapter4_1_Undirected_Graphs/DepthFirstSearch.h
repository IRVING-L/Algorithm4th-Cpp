#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;
class DepthFirstSearch
{
private:
	bool* marked;//�������
	int count;//�������ͳ��
	//˽�г�Ա����
	void dfs(Graph& G, int v)
	{
		marked[v] = true;//�����˸ö��㣬�㽫�ö����Ӧλ�õ�marked���������
		++count;
		//it������������BagNode*��ָ�򶥵�v�ı���Bag�ĵ�һ��Ԫ��
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			//���it->val��Ӧ�Ķ���û�б����ʣ��ݹ����dfs���ʸö���
			if (!marked[it->val]) dfs(G, it->val);
			//����������ˣ��Ǿ��ƶ�itָ�룬ָ����һ�����ڶ���
			it = it->next;
		}
	}
public:
	//���캯��
	DepthFirstSearch(Graph& G, int s)
	{
		//����marked���鲢������Ԫ�ص�ֵͳһ��ʼ��Ϊfalse
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		count = 0;
		//��Ա������ʼ����ɺ󣬽��еݹ飬������ȱ�������ͼ
		dfs(G, s);
	}
	~DepthFirstSearch()
	{
		delete[] marked;
	}
	//��Ա����
	bool ismarked(int w) { return marked[w]; }//�ж�ĳ�����Ƿ񱻷���
	int getCount() { return count; }//����DFS�������ö�����
};