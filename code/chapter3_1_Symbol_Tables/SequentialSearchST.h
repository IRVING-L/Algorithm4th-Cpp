#pragma once
#include<iostream>
using namespace std;

class SequentialSearchST
{
	typedef int KeyType;
	typedef int ValueType;
private:
	//链表结点
	struct Node
	{
		KeyType key;
		ValueType val;
		Node* next;
		//构造函数
		Node(KeyType k, ValueType v, Node* n)
			:key(k), val(v), next(n) {}
	};

	Node* first = nullptr;//只是指针，并非头结点
public:
	//成员函数
	ValueType get(KeyType k)
	{
		for (Node* it = first; it != nullptr; it = it->next)
			if (k == it->val) return it->val;
		return NULL;
	}
	void put(KeyType k, ValueType v)
	{
		// 查找给定的键，找到则更新其值，否则在表中新建结点
		for (Node* it = first; it != nullptr; it = it->next)
			if (k == it->val)
			{
				it->val = v;
				return;
			}
		first = new Node(k, v, first);//没有头结点的头插法
	}
};