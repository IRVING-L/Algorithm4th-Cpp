#pragma once
#include<iostream>
using namespace std;

class SequentialSearchST
{
	typedef int KeyType;
	typedef int ValueType;
private:
	//������
	struct Node
	{
		KeyType key;
		ValueType val;
		Node* next;
		//���캯��
		Node(KeyType k, ValueType v, Node* n)
			:key(k), val(v), next(n) {}
	};

	Node* first = nullptr;//ֻ��ָ�룬����ͷ���
public:
	//��Ա����
	ValueType get(KeyType k)
	{
		for (Node* it = first; it != nullptr; it = it->next)
			if (k == it->val) return it->val;
		return NULL;
	}
	void put(KeyType k, ValueType v)
	{
		// ���Ҹ����ļ����ҵ��������ֵ�������ڱ����½����
		for (Node* it = first; it != nullptr; it = it->next)
			if (k == it->val)
			{
				it->val = v;
				return;
			}
		first = new Node(k, v, first);//û��ͷ����ͷ�巨
	}
};