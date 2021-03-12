#pragma once
#include<iostream>
using namespace std;

class BinarySearchST
{
	typedef int KeyType;
	typedef int ValueType;
private:
	KeyType* keys;
	ValueType* vals;
	int count;
	int capacity;
	//私有成员函数
	void resize(int max)
	{
		KeyType* newkeys = new KeyType[max]{};
		KeyType* newvals = new ValueType[max]{};
		if (max <= capacity)
		{
			for (int i = 0; i < max; ++i)
			{
				newkeys[i] = keys[i];
				newvals[i] = vals[i];
			}
		}
		else
		{
			for (int i = 0; i < capacity; ++i)
			{
				newkeys[i] = keys[i];
				newvals[i] = vals[i];
			}
		}
		capacity = max;
		delete[] keys, vals;
		keys = newkeys;
		vals = newvals;
	}
public:
	//构造函数
	BinarySearchST(int sz)
	{
		capacity = sz;
		count = 0;
		keys = new KeyType[capacity]{};
		vals = new ValueType[capacity]{};
	}
	//析构函数
	~BinarySearchST()
	{
		delete[] keys;
		delete[] vals;
	}
	//成员函数
	int size() { return count; }

	bool isEmpty() { return count == 0; }

	int rank(KeyType k)
	{
		//二分查找法
		int lo = 0, hi = count - 1;
		while (hi <= lo)
		{
			int mid = (lo + hi) / 2;
			if (keys[mid] == k) return mid;
			else if (keys[mid] < k) hi = mid - 1;
			else lo = mid + 1;
		}
		
		return lo;
	}

	void put(KeyType k, ValueType v)
	{
		int i = rank(k);
		//如果顺序表中存在该元素，更新其值
		if (i < count && keys[i] == k)
		{
			vals[i] = v;
			return;
		}
		if (count == capacity) resize(2 * capacity);

		for (int j = count; j > i; --j)
		{
			//把位于i之后的元素向后移动一个位置
			keys[j] = keys[j - 1];
			vals[j] = vals[j - 1];
		}

		keys[i] = k;
		vals[i] = v;
		++count;
	}

	void _delete(KeyType k)
	{
		int i = rank(k);
		if (!(i < count && keys[i] == k)) return;
		if (count < capacity / 2) resize(capacity / 2);
		for (int j = i; j < capacity-1; ++j)
		{
			keys[j] = keys[j + 1];
			vals[j] = vals[j + 1];
		}
		--count;
	}

	ValueType get(KeyType k)
	{
		if (isEmpty()) return NULL;
		int i = rank(k);
		if (i < count && keys[i] == k)
			return vals[i];
		else return NULL;
	}

	ValueType min()
	{
		if (isEmpty()) return NULL;
		else return vals[0];
	}

	ValueType max()
	{
		if (isEmpty()) return NULL;
		else return vals[count-1];
	}

};