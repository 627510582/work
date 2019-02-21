#include "pch.h"


int big_size(int arr[] ,int n)
{
	int max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
	}
	int d = 1;
	while (max>=10)
	{
		max /= 10;
		d++;
	}
	return d;
}


void radixsort(int n)
{
	//-----------生成随机数组------
	srand((unsigned)time(NULL));
	int *a = new int[n];
	


	for (size_t i = 0; i < n; i++)
	{
		a[i] = i;
	}
	for (size_t i = n - 1; i > 0; i--)
	{
		swap(a[i], a[rand() % i]);

	}
	//-----------------------------


	int *count = new int[n];

	 int bigsize=big_size(a, n);
	cout <<"数字最大长度为："<< n << endl;
	int re = 1;
	for (int i = 0; i < bigsize; ++i)
	{
		int p = 0;
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if ((a[k]/re)%10==j)
				{
					count[p++] = a[k];
				}
			}
		}
		for (int j = 0; j < n; ++j)
		{
			a[j] = count[j];
		}
		re = re * 10;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << setw(5) << setfill(' ') << left <<a[i];
	}




}