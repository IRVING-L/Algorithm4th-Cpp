/*
����1��arr��һά������׵�ַ
����2��length��һά�����Ԫ�ظ��������ȣ�
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
		//����ӵ�ǰԪ��i֮����������ҵ���һ����i���Ԫ�أ�����������λ��
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}