#include"pch.h"



//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[], int size)
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}
	for (size_t i = 0; i < k; i++)
	{
		a[first + i] = temp[i];
	}
	/*for (size_t i = 0; i < size; i++)
	{
		cout << setw(3) << setfill(' ') << left << a[i];
	}
	cout << endl;*/

}

void mergesort(int* a, int first, int last, int *temp, int size)
{


	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp, size);    //左边有序
		mergesort(a, mid + 1, last, temp, size); //右边有序
		mergearray(a, first, mid, last, temp, size); //再将二个有序数列合并

	}
}

void MergeSort(int n)
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

	//cout << "并归排序：\t";
	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << setw(3) << setfill(' ') << left << a[i];
	//}
	//cout << endl;
	int *p = new int[n];
	mergesort(a, 0, n - 1, p, n);

	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << setw(3) << setfill(' ') << left << a[i];
	//}
	delete p,a;

	//cout << endl;
}