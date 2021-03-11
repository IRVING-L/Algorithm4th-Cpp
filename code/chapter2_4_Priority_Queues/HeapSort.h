#pragma once
#include<iostream>
using namespace std;


void ArrSwap(int* arr, int pos1, int pos2)
{
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void sink(int* arr, int length, int loc)
{
	while (2 * loc <= length)
	{
		int lchild = 2 * loc;
		if ((lchild + 1) < length && arr[lchild] < arr[lchild + 1])
			++lchild;
		if (arr[loc] > arr[lchild]) break;
		//swap
		ArrSwap(arr, loc, lchild);

		loc = lchild;
	}
}

void swim(int* arr, int length, int loc)
{
	while (loc > 1 && arr[loc] > arr[loc / 2])
	{
		//swap
		ArrSwap(arr, loc, loc / 2);
		loc /= 2;
	}
}

void CreateBHT(int* arr, int length)
{
	int first = length / 2;
	for (int i = first; i > 0; --i)
	{
		sink(arr, length, i);
	}
}

void HeapSort(int* arr, int length)
{
	//step 1: create BinaryHeap
	CreateBHT(arr, length);
	//step 2: sort
	for (int i = length; i > 1; --i)
	{
		//swap
		ArrSwap(arr, i, 1);
		sink(arr, i - 1, 1);
	}
}



