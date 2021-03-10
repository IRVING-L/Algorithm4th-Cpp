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
	//���캯��
	Bag()  
	{
		root = new BagNode;
		root->next = nullptr;
	}
	//��Ա����
	void add(T item)
	{
		//�������Ԫ�ز�����ͷ�巨
		BagNode* temp = new BagNode;
		temp->val = item;
		temp->next = root->next;
		root->next = temp;
	}

	int size()
	{
		//˳���������ͳ�ƽ�����
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
	//��ӡ������˳���ӡ�����е�Ԫ��ֵ
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
	//����ӿڣ����ظ���㣬�����ⲿ���ʶ����ڲ�������
	BagNode* getRoot() { return root; }
};
