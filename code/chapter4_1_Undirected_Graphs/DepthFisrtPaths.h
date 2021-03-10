#pragma once
#include<iostream>
#include<stack>
#include"Graph.h"
using namespace std;

class DepthFirstPaths
{
private:
	bool* marked;//�������
	int* edgeTo;//��¼���ʶ��㵽ͼ�ķ�������·���������鱣��˫�׽���λ�����꣬ͬUnionFind�㷨
	int s;//ͼ�������
	void dfs(Graph& G, int v)
	{
		marked[v] = true;//�����˸ö��㣬�㽫�ö����Ӧλ�õ�marked���������
		//it������������BagNode*��ָ�򶥵�v�ı���Bag�ĵ�һ��Ԫ��
		auto it = G.adjData(v).getRoot()->next;
		while (it)
		{
			if (!marked[it->val]) 
			{
				//û�б����ʹ��ö��㣬�ڵݹ����ǰ��������edgeTo������˫�׽��
				edgeTo[it->val] = v;
				dfs(G, it->val);
			}
			it = it->next;
		}
	}
public:
	//���캯��
	DepthFirstPaths(Graph& G, int v)
	{
		//��������ʼ����������marked
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		//��������ʼ����������edgeTo
		edgeTo = new int[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) edgeTo[i] = 0;
		s = v;
		//������ȱ�������
		dfs(G, s);
	}
	//��Ա����
	bool hasPathTo(int v) { return marked[v]; }//�ж϶����Ƿ񱻷��ʹ�
	//��ջ�������㵽ĳ����v�ı���·����ջ�Ǵ����ڶ����ģ���ָ��ָ�����׵�ַ�����Է������׵�ַ
	stack<int>* pathTO(int v)
	{
		//v�����յ㣬s�����
		if (!hasPathTo(v)) return nullptr;//
		stack<int>* path = new stack<int>;
		for (int x = v; x != s; x = edgeTo[x])
			path->push(x);
		path->push(s);
		return path;
	}
};