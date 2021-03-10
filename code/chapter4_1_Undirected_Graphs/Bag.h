#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class Bag
{
private:
	struct BagNode
	{
		T val;
		BagNode* next;
	};
	BagNode* root;
public:
	//构造函数
	Bag()  
	{
		root = new BagNode;
		root->next = nullptr;
	}
	//成员函数
	void add(T item)
	{
		//链表添加元素操作，头插法
		BagNode* temp = new BagNode;
		temp->val = item;
		temp->next = root->next;
		root->next = temp;
	}

	int size()
	{
		//顺序访问链表，统计结点个数
		BagNode* curr = root->next;
		int sz = 0;
		while (curr)
		{
			++sz;
			curr = curr->next;
		}
		return sz;
	}

	bool isEmpty() { return size() == 0; }
	//打印函数，顺序打印背包中的元素值
	ostream& BagPrint(ostream& out)
	{
		BagNode* curr = root->next;
		while (curr)
		{
			out << curr->val << " ";
			curr = curr->next;
		}
		out << endl;
		return out;
	}
	//对外接口，返回根结点，便于外部访问对象内部的数据
	BagNode* getRoot() { return root; }
};
