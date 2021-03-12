#pragma once
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
//�Ե����ϵĹ鲢�㷨Down-Top
class MergeSortD2T
{
private:
	int* aux;//��������
	//�ϲ�������������
	void merge(int* arr, int lo, int mid, int hi)
	{
		//��������ָ��
		int i = lo, j = mid + 1;
		//��������Ԫ��
		for (int k = lo; k <= hi; ++k)
			aux[k] = arr[k];
		//�ϲ������������Ա�
		for (int k = lo; k <= hi; ++k)
		{
			if (i > mid) arr[k] = aux[j++];
			else if (j > hi) arr[k] = aux[i++];
			else if (aux[i] < aux[j]) arr[k] = aux[i++];
			else arr[k] = aux[j++];
		}
	}
	//����
	void sort(int* arr, int length)
	{
		for (int sz = 1; sz < length; sz = 2 * sz)
			for (int lo = 0; lo < length-sz; lo += 2 * sz)
			{
				int mid = lo + sz - 1;
				int hi = fmin((lo + 2 * sz - 1), length - 1);
				merge(arr, lo, mid, hi);
			}
				
	}

public:
	MergeSortD2T(int* arr, int length)
	{
		//��ʼ����������
		aux = new int[length] {};
		//������̼�ʱ
		clock_t beg = clock();
		sort(arr, length);
		clock_t end = clock();
		//ֱ����������ʱ
		cout << "time is " << end - beg << "ms" << endl;
	}
};