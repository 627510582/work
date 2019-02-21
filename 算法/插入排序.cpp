#include"pch.h"

int insertSort(int n)
{
	//-----------生成随机数组------
	srand((unsigned)time(NULL));
	int *a;
	a = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		a[i] = i;
	}
	for (size_t i = n - 1; i > 0; i--)
	{
		swap(a[i], a[rand() % i]);

	}
	//-----------------------------

	/*cout << "插入排序：\t";
	for (size_t i = 0; i < n; i++)
	{
		cout << setw(3) << setfill(' ') << left << a[i];
	}*/
	
	for (size_t  i = 0; i < n; i++)
	{
		int temp = a[i];
		for (size_t j = i; j >=0; j--)
		{
			if (temp<a[j-1])
			{
				a[j] = a[j - 1];
				continue;
			}
			else
			{
				a[j] = temp;
				break;
			}
		}
	}
	//cout << endl;
	/*for (size_t y = 0; y < n; y++)
	{
		cout << setw(3) << setfill(' ') << left << a[y];
	}*/

	//cout << endl;
	delete a;
	return 0;

}