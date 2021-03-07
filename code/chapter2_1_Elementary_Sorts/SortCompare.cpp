#include<iostream>
#include<time.h>
using namespace std;

#define MAXSIZE 100000

int* RandomArr(int length)
{
	//第一步：在堆区创建数组，可以容纳更多元素便于大序列排序测试
	int* arr = new int[length + 1];
	//第二步：先将序列初始化为升序，方便确定排序结果是否准确
	for (int i = 0; i <= length; ++i)
		arr[i] = i;
	//第三步：打乱序列
	for (int i = length; i >= 1; --i)
	{
		int loc = rand() & length;
		int temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	}
	return arr;
}
void InsertSort(int* arr, int length)
{
	for (int i = 2; i <= length; ++i)
	{
		//设置哨兵
		arr[0] = arr[i];
		int j = i - 1;
		for (; arr[j] > arr[0]; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = arr[0];
	}
}
void PrintArr(int* arr, int length)
{
	for (int i = 1; i <= length; ++i) cout << arr[i] << " ";
	cout << endl;
}

bool IsSorted(int* arr, int length)
{
	for (int i = 1; i < length; ++i)
		if (arr[i] > arr[i + 1]) return false;
	return true;
}

int main()
{
	int* arr = RandomArr(MAXSIZE);
	clock_t beg = clock();
	InsertSort(arr, MAXSIZE);
	clock_t end = clock();
	cout << "sort time is " << end - beg << " ms" << endl;
	IsSorted(arr, MAXSIZE) ? (cout << "is sorted") : (cout << "not sorted");
	delete[] arr;
	return 0;
}
