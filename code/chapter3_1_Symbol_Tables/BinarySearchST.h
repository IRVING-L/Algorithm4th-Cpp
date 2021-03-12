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
	//˽�г�Ա����
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
	//���캯��
	BinarySearchST(int sz)
	{
		capacity = sz;
		count = 0;
		keys = new KeyType[capacity]{};
		vals = new ValueType[capacity]{};
	}
	//��������
	~BinarySearchST()
	{
		delete[] keys;
		delete[] vals;
	}
	//��Ա����
	int size() { return count; }

	bool isEmpty() { return count == 0; }

	int rank(KeyType k)
	{
		//���ֲ��ҷ�
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
		//���˳����д��ڸ�Ԫ�أ�������ֵ
		if (i < count && keys[i] == k)
		{
			vals[i] = v;
			return;
		}
		if (count == capacity) resize(2 * capacity);

		for (int j = count; j > i; --j)
		{
			//��λ��i֮���Ԫ������ƶ�һ��λ��
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