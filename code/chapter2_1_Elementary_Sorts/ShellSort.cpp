/*
参数1：arr。一维数组的首地址
参数2：flag。确定间隔的递减序列数组首地址
参数3：length1。一维数组的元素个数（长度）
参数4：length2。递减数组的元素个数（长度）

flag间隔数组的取值是希尔排序的一个难点之一，该数组没有唯一取值方式。
如果待排序序列数量很大（>1e4），flag数组的建议值为int flag[] = { 121,40,13,4,1 };
*/
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