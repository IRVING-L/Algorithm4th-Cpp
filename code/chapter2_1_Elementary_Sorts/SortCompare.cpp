#include<iostream>
#include<time.h>
using namespace std;

#define MAXSIZE 100000
//�����������ɺ��������ظ�Ԫ�أ�
int* RandomArr(int length)
{
	//��һ�����ڶ����������飬�������ɸ���Ԫ�ر��ڴ������������
	int* arr = new int[length + 1];
	//�ڶ������Ƚ����г�ʼ��Ϊ���򣬷���ȷ���������Ƿ�׼ȷ
	for (int i = 0; i <= length; ++i)
		arr[i] = i;
	//����������������
	for (int i = length; i >= 1; --i)
	{
		int loc = rand() & length;
		int temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	}
	return arr;
}
//ѡ�������㷨
void SelectSort(int* arr, int length)
{
	for (int i = 1; i <= length; ++i)
	{
		int min = i;
		for (int j = i + 1; j <= length; ++j)
		{
			if (arr[j] < arr[min]) min = j;
		}
		//����ӵ�ǰԪ��i֮����������ҵ���һ����i���Ԫ�أ�����������λ��
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
//���������㷨
void InsertSort(int* arr, int length)
{
	for (int i = 2; i <= length; ++i)
	{
		//�����ڱ�
		arr[0] = arr[i];
		int j = i - 1;
		for (; arr[j] > arr[0]; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = arr[0];
	}
}
//ϣ�������㷨
void ShellSort(int* arr, int* flag, int length1, int length2)
{
	for (int p = 0; p < length2; ++p)
	{
		int h = flag[p];//���
		//�������Ǽ��Ϊh�Ĳ�������
		for (int i = h + 1; i <= length1; ++i)
		{
			arr[0] = arr[i];//�ڱ�λ
			int j = i - h;
			for (; j > 0 && arr[j] > arr[0]; j -= h)
			{
				arr[j + h] = arr[j];
			}
			arr[j + h] = arr[0];
		}
	}
}
//������ȷ�Լ�⺯��
bool IsSorted(int* arr, int length)
{
	for (int i = 1; i < length; ++i)
		if (arr[i] > arr[i + 1]) return false;
	return true;
}

int main()
{
	cout << "�������г���Ϊ��" << MAXSIZE << endl;

	cout << "***********ѡ������**************" << endl;
	int* arr1 = RandomArr(MAXSIZE);
	clock_t beg1 = clock();
	SelectSort(arr1, MAXSIZE);
	clock_t end1 = clock();
	cout << "sort time is " << end1 - beg1 << " ms" << endl;
	IsSorted(arr1, MAXSIZE) ? (cout << "is sorted\n") : (cout << "not sorted\n");

	cout << "***********��������**************" << endl;
	int* arr2 = RandomArr(MAXSIZE);
	clock_t beg2 = clock();
	InsertSort(arr2, MAXSIZE);
	clock_t end2 = clock();
	cout << "sort time is " << end2 - beg2 << " ms" << endl;
	IsSorted(arr2, MAXSIZE) ? (cout << "is sorted\n") : (cout << "not sorted\n");

	cout << "***********ϣ������**************" << endl;
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
