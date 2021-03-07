/*
����1��arr��һά������׵�ַ
����2��flag��ȷ������ĵݼ����������׵�ַ
����3��length1��һά�����Ԫ�ظ��������ȣ�
����4��length2���ݼ������Ԫ�ظ��������ȣ�

flag��������ȡֵ��ϣ�������һ���ѵ�֮һ��������û��Ψһȡֵ��ʽ��
������������������ܴ�>1e4����flag����Ľ���ֵΪint flag[] = { 121,40,13,4,1 };
*/
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