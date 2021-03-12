#pragma once
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
//自底向上的归并算法Down-Top
class MergeSortD2T
{
private:
	int* aux;//辅助数组
	//合并两个有序序列
	void merge(int* arr, int lo, int mid, int hi)
	{
		//设置两个指针
		int i = lo, j = mid + 1;
		//拷贝区间元素
		for (int k = lo; k <= hi; ++k)
			aux[k] = arr[k];
		//合并两个有序线性表
		for (int k = lo; k <= hi; ++k)
		{
			if (i > mid) arr[k] = aux[j++];
			else if (j > hi) arr[k] = aux[i++];
			else if (aux[i] < aux[j]) arr[k] = aux[i++];
			else arr[k] = aux[j++];
		}
	}
	//排序
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
		//初始化辅助数组
		aux = new int[length] {};
		//排序过程计时
		clock_t beg = clock();
		sort(arr, length);
		clock_t end = clock();
		//直接输出排序耗时
		cout << "time is " << end - beg << "ms" << endl;
	}
};