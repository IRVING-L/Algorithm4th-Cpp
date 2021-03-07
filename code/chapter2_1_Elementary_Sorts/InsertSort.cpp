void InsertSort(int* arr, int length)
{
	for (int i = 2; i <= length; ++i)
	{
		//ÉèÖÃÉÚ±ø
		arr[0] = arr[i];
		int j = i - 1;
		for (; arr[j] > arr[0]; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = arr[0];
	}
}