//��������<���ݽṹ��Ƶ�ΰ汾>
int partition(int* arr, int low, int high)
{
	//�����ڱ�
	int sen = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= sen) --high;
		arr[low] = arr[high];
		while (low < high && arr[low] < sen) ++low;
		arr[high] = arr[low];
	}
	arr[low] = sen;
	return low;
}
void QuickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		QuickSort(arr, low, mid - 1);
		QuickSort(arr, mid + 1, high);
	}
}