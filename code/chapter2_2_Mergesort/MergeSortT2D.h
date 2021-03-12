#pragma once
#include<iostream>
#include<time.h>
using namespace std;
//自顶向下的归并排序Top-Down
class MergeSortT2D
{
private:
	int* aux;//辅助数组
	//合并两个有序数组
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
		//初始化辅助数组
		aux = new int[length] {};
		//排序过程计时
		clock_t beg = clock();
		sort(arr, 0, length - 1);
		clock_t end = clock();
		//直接输出排序耗时
		cout << "time is " << end - beg << "ms" << endl;
	}
};