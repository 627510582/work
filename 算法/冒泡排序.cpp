#include"pch.h"

int maopao(int n)
{
	
	srand((unsigned)time(NULL));
	int *a;
	a = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		a[i] = i;
	}
	
	for (size_t i = n - 1; i >0; i--)
	{
		swap(a[i], a[rand() % i ]);
	}
	
	//cout << "冒泡排序:\t";
	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << setw(3) << setfill(' ') << left << a[i];
	//}

	for (size_t i = 0; i < n; i++)
	{
		//cout << endl;
		int flag = 0;
		for (size_t j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
	/*	cout << "第" << i << "次排序结果\t";
		for (size_t y = 0; y < n; y++)
		{
			cout << setw(3) << setfill(' ') << left << a[y];
		}*/
		

		if (flag == 0) {
			break;
		}
	}
	//cout<<endl;
	/*for (size_t i = 0; i < n; i++)
	{
		cout << setw(3) << setfill(' ') << left << a[i] ;
	}
	cout << endl;*/
	delete[] a;
	return 0;
}