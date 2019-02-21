
#include"pch.h"



void shellsort(int n) {

	//-----------生成随机数组------
	srand(static_cast<unsigned>(time(nullptr)));
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

	// cout << "希尔排序：\t";
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout << setw(3) << setfill(' ') << left << a[i];
	// }
	// cout << endl;

	//列数
	int nop = n / 2;
	int temp;
	while (nop)
	{
		for (size_t i = 0; i < nop; i++)
		{
			for (int j = i+nop; j < n; j+=nop)
			{
				if (a[j]<a[j-nop])
				{
					int temp = a[j];
					int k = j - nop;
					while (k>=0&&a[k]>temp)
					{
						a[k + nop] = a[k];
						k -= nop;
					}
					a[k + nop] = temp;
				}
			}
		}
		nop /= 2;
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout << setw(3) << setfill(' ') << left << a[i];
	// }
	// cout << endl;
	//

}