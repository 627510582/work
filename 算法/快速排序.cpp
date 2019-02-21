#include"pch.h"

void quick(int* array, int left, int right, int n);
int PartSort(int* array, int left, int right,int n);
void print_array(int* array, int n);

int quickSort(int n) {
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

	//cout << "快速排序：\t";
	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << setw(3) << setfill(' ') << left << a[i];
	//}
	//cout << endl;
	int left = 0;
	int right = n-1;
	quick(a, left, right, n);
	delete a;
	return 0;
}

void quick(int* array, int left, int right, int n)
{
	//print_array(array, n);
	if (left >= right)
	{
		return;
	}
	int index = PartSort(array, left, right,n);
	quick(array, left, index-1, n);
	//cout << "right--------" << right << endl;
	quick(array, index+1, right, n);
}

int PartSort(int* array, int left, int right,int n)
{
	//cout << "i=" << left << "  j=" << right << endl;
	//cout << "left=" << array[left] << "  right=" << array[right] << endl;

	int& key = array[right];
	//cout << "key=" << key << endl;
	while (left < right)
	{
		while (left < right && array[left] <= key)
		{
			++left;
		}
		while (left < right && array[right] >= key)
		{
			--right;
		}
		//cout << "i=" << left << "  j=" << right << endl;
		//cout << "left=" << array[left] << "  right=" << array[right] << endl;
		
		swap(array[left], array[right]);
		//print_array(array, n);
	}

	swap(array[left], key);
	

	//print_array(array, n);
	//cout << "index=" << left << endl;
	
	return left;

}

void print_array(int* array, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << setw(3) << setfill(' ') << left << array[i];
	}
	cout << endl;
}