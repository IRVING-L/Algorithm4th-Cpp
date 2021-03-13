#pragma once
#include<iostream>
using namespace std;
#define NULLKEY INT32_MIN

//��������̽�ⷨ�Ĺ�ϣ��
class LinearProbingHashTable
{
	typedef int KeyType;
	typedef int ValueType;
private:
	//��Ա����
	int N = 0;// ��ֵ�Եĸ���
	int M = 16;//����̽���Ĵ�С
	KeyType* _keys; //�洢���Ķ�̬����ָ��
	ValueType* _vals;//�洢ֵ�Ķ�̬����ָ��
	//��Ա����
	int hash(KeyType k) { return k % M; }
	void resize(int cap) 
	{
		/*
		��ϣ���resize������ͬ��strVec,ֻ��������ô��
		���������ݣ���Ҫ����ǰ��Ԫ������ɢ�У�Ԫ��֮������λ�ûᷢ���ı�
		*/
		/*
		���temp���������˺þá�֮ǰ������˺����ڲ��ľֲ�������
		�˳�resize������tempֱ�Ӿ͵����������������ˣ��´�����keys��vals����ʧ��
		�һ���Ϊ��get_keys������ɵ����⣬�˳�����������
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
	//���캯��
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
	//��Ա����
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
		if (N > M / 2) resize(2*M);//�жϴ洢�ռ��Ƿ��㹻
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
			//����ɢ��
			put(newk, newv);
		}
	}

	//Ϊ��ʵ��resize������������������Ա����
	KeyType* get_keys() { return this->_keys; }
	ValueType* get_vals() { return this->_vals; }
};