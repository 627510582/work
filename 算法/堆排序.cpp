#include "pch.h"


//构建最大堆
void max_heapify(int arr[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		//找出最大的子节点
		if (son + 1 < end && arr[son] < arr[son + 1])
		{
			son++;
		}
		if (arr[dad] > arr[son])
		{
			return;
		}
		else
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = son * 2 + 1;
		}
	}
}


void heap_sort(int n)
{
	//-----------生成随机数组------
	srand((unsigned)time(NULL));
	int* a;
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
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout << setw(3) << setfill(' ') << left << a[i];
	// }
	// cout << endl;
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		max_heapify(a, i, n - 1);
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout << setw(3) << setfill(' ') << left << a[i];
	// }
	// cout << endl;
	for (int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		max_heapify(a, 0, i - 1);
	}

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout << setw(3) << setfill(' ') << left << a[i];
	// }
	// cout << endl;
}
