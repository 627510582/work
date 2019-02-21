

#include"pch.h"
#include <stdlib.h>
#include <time.h>
int selectsort(int n) 
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


	/*cout << "选择排序：\t";
	for (size_t i = 0; i < n; i++)
	{
		cout << setw(3) << setfill(' ') << left << a[i];
	}*/
	int min;
	int k;
	for (size_t i = 0; i < n; i++)
	{
		int flag = 0;
		min = a[i];
		k = i;
		for (size_t j = i; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				k = j;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		swap(a[i], a[k]);
	/*	cout << endl;
		cout << "第" << i << "次排序结果\t";
		for (size_t y = 0; y < n; y++)
		{
			cout << setw(3) << setfill(' ') << left << a[y] ;
		}*/
	}
	//cout << endl;

	delete[]a;
	return 0;
}


