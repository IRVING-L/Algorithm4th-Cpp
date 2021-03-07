/*
参数1：arr。一维数组的首地址
参数2：length。一维数组的元素个数（长度）
*/
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