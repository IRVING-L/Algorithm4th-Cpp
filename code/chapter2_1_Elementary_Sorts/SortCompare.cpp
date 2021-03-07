#include<iostream>
#include<time.h>
using namespace std;

#define MAXSIZE 100000
//无序数组生成函数（无重复元素）
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
//选择排序算法
void SelectSort(int* arr, int length)
{
	for (int i = 1; i <= length; ++i)
	{
		int min = i;
		for (int j = i + 1; j <= length; ++j)
		{
			if (arr[j] < arr[min]) min = j;
		}
		//如果从当前元素i之后的序列中找到了一个比i大的元素，交换他俩的位置
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
//插入排序算法
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
//希尔排序算法
void ShellSort(int* arr, int* flag, int length1, int length2)
{
	for (int p = 0; p < length2; ++p)
	{
		int h = flag[p];//间隔
		//接下来是间隔为h的插入排序
		for (int i = h + 1; i <= length1; ++i)
		{
			arr[0] = arr[i];//哨兵位
			int j = i - h;
			for (; j > 0 && arr[j] > arr[0]; j -= h)
			{
				arr[j + h] = arr[j];
			}
			arr[j + h] = arr[0];
		}
	}
}
//排序正确性检测函数
bool IsSorted(int* arr, int length)
{
	for (int i = 1; i < length; ++i)
		if (arr[i] > arr[i + 1]) return false;
	return true;
}

int main()
{
	cout << "无序序列长度为：" << MAXSIZE << endl;

	cout << "***********选择排序**************" << endl;
	int* arr1 = RandomArr(MAXSIZE);
	clock_t beg1 = clock();
	SelectSort(arr1, MAXSIZE);
	clock_t end1 = clock();
	cout << "sort time is " << end1 - beg1 << " ms" << endl;
	IsSorted(arr1, MAXSIZE) ? (cout << "is sorted\n") : (cout << "not sorted\n");

	cout << "***********插入排序**************" << endl;
	int* arr2 = RandomArr(MAXSIZE);
	clock_t beg2 = clock();
	InsertSort(arr2, MAXSIZE);
	clock_t end2 = clock();
	cout << "sort time is " << end2 - beg2 << " ms" << endl;
	IsSorted(arr2, MAXSIZE) ? (cout << "is sorted\n") : (cout << "not sorted\n");

	cout << "***********希尔排序**************" << endl;
	int* arr3 = RandomArr(MAXSIZE);
	clock_t beg3 = clock();
	int flag[] = { 121,40,13,4,1 };
	ShellSort(arr3, flag, MAXSIZE, 5);
	clock_t end3 = clock();
	cout << "sort time is " << end3 - beg3 << " ms" << endl;
	IsSorted(arr3, MAXSIZE) ? (cout << "is sorted\n") : (cout << "not sorted\n");

	delete[] arr1, arr2, arr3;
	return 0;
}
