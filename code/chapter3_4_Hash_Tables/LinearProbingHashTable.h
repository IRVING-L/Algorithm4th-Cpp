#pragma once
#include<iostream>
using namespace std;
#define NULLKEY INT32_MIN

//基于线性探测法的哈希表
class LinearProbingHashTable
{
	typedef int KeyType;
	typedef int ValueType;
private:
	//成员变量
	int N = 0;// 键值对的个数
	int M = 16;//线性探测表的大小
	KeyType* _keys; //存储键的动态数组指针
	ValueType* _vals;//存储值的动态数组指针
	//成员函数
	int hash(KeyType k) { return k % M; }
	void resize(int cap) 
	{
		/*
		哈希表的resize函数不同于strVec,只是扩容那么简单
		不仅是扩容，还要把以前的元素重新散列，元素之间的相对位置会发生改变
		*/
		/*
		这个temp变量被坑了好久。之前定义成了函数内部的局部变量，
		退出resize函数后temp直接就调用析构函数解体了，新创建的keys和vals就消失了
		我还以为是get_keys函数造成的问题，退出函数解体了
		*/
		LinearProbingHashTable* temp = new LinearProbingHashTable(cap);
		for (int i = 0; i < M; ++i)
			if (_keys[i] != NULLKEY)
				temp->put(_keys[i], _vals[i]);
		delete[] _keys;
		delete[] _vals;
		_keys = temp->get_keys();
		_vals = temp->get_vals();

	}
public:
	//构造函数
	LinearProbingHashTable() 
	{
		_keys = new KeyType[M];
		for (int i = 0; i < M; ++i) _keys[i] = NULLKEY;
		_vals = new ValueType[M];
		for (int i = 0; i < M; ++i) _vals[i] = NULLKEY;
		
	}
	LinearProbingHashTable(int m)
	{
		M = m;
		_keys = new KeyType[M];
		for (int i = 0; i < M; ++i) _keys[i] = NULLKEY;
		_vals = new ValueType[M];
		for (int i = 0; i < M; ++i) _vals[i] = NULLKEY;
	}
	~LinearProbingHashTable()
	{
		delete[] _keys;
		delete[] _vals;
	}
	//成员函数
	bool contains(KeyType k)
	{
		for (int i = hash(k); _keys[i] != NULLKEY; i = (i + 1) % M)
			if (_keys[i] == k) return true;
		return false;
	}
	ValueType get(KeyType k)
	{
		for (int i = hash(k); _keys[i] != NULLKEY; i = (i + 1) % M)
			if (_keys[i] == k) return _vals[i];
		return NULLKEY;
	}
	void put(KeyType k, ValueType v)
	{
		if (N > M / 2) resize(2*M);//判断存储空间是否足够
		int i = hash(k);
		for (; _keys[i] != NULLKEY; i = (i + 1) % M)
		{
			if (_keys[i] == k)
			{
				_vals[i] = v;
				return;
			}
		}
		_keys[i] = k;
		_vals[i] = v;
		++N;
	}
	void _delete(KeyType k)
	{
		if (!contains(k)) return;
		if (N < M / 4) resize(M / 2);

		int i = hash(k);
		for (; _keys[i] != k; i = (i + 1) % M);
		_keys[i] = NULLKEY;
		_vals[i] = NULLKEY;
		--N;

		i = (i + 1) % M;
		for (;_keys[i] != NULLKEY; i = (i + 1) % M)
		{
			KeyType newk = _keys[i];
			ValueType newv = _vals[i];
			_keys[i] = NULLKEY;
			_vals[i] = NULLKEY;
			--N;
			//重新散列
			put(newk, newv);
		}
	}

	//为了实现resize函数，新增的两个成员函数
	KeyType* get_keys() { return this->_keys; }
	ValueType* get_vals() { return this->_vals; }
};