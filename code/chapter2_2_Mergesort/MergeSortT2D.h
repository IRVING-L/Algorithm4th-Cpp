#pragma once
#include<iostream>
#include<time.h>
using namespace std;
//�Զ����µĹ鲢����Top-Down
class MergeSortT2D
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
	void sort(int* arr, int lo, int hi)
	{
		if (hi <= lo) return;
		int mid = (lo + hi) / 2;
		sort(arr, lo, mid);
		sort(arr, mid + 1, hi);
		merge(arr, lo, mid, hi);
	}
	
public:
	MergeSortT2D(int* arr, int length)
	{
		//��ʼ����������
		aux = new int[length] {};
		//������̼�ʱ
		clock_t beg = clock();
		sort(arr, 0, length - 1);
		clock_t end = clock();
		//ֱ����������ʱ
		cout << "time is " << end - beg << "ms" << endl;
	}
};