#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"Graph.h"
using namespace std;

class BreadthFirstPaths
{
private:
	bool* marked;//�������
	int* edgeTo;//��¼���ʶ��㵽ͼ�ķ�������·���������鱣��˫�׽���λ�����꣬ͬUnionFind�㷨
	int s;//ͼ�������
	//������ȱ�������
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
	//���캯��
	BreadthFirstPaths(Graph& G, int v)
	{
		//��������ʼ����������marked
		marked = new bool[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) marked[i] = false;
		//��������ʼ����������edgeTo
		edgeTo = new int[G.Vnum()];
		for (int i = 0; i < G.Vnum(); ++i) edgeTo[i] = 0;
		s = v;
		bfs(G, v);
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