// 算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include<time.h>
int selectsort(int n);
int maopao(int n);
int insertSort(int n);
int quickSort(int n);
void MergeSort(int n);
void shellsort(int n);
void heap_sort(int n);;
void radixsort(int n);
int main()
{

	int n = 3333;
	clock_t start_time;
	clock_t end_time;


	// //冒泡排序
	// start_time = clock();
	// maopao(n);
	// end_time = clock();
	// double maopao_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "冒泡排序时间:" << maopao_time << endl;
	//
	// //选择排序
	// start_time = clock();
	// selectsort(n);
	// end_time = clock();
	// double select_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "选择排序时间:" << select_time << endl;
	//
	// //插入排序
	// start_time = clock();
	// insertSort(n);
	// end_time = clock();
	// double insert_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "插入排序时间:" << insert_time << endl;
	//
	//
	// //快速排序
	// start_time = clock();
	// quickSort(n);
	// end_time = clock();
	// double quick_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "快速排序时间:" << quick_time << endl;
	//
	// //并归排序
	// start_time = clock();
	// MergeSort(n);
	// end_time = clock();
	// double merge_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "并归排序时间:" << merge_time << endl;
	//
	// //希尔排序
	//  start_time = clock();
	//  shellsort(n);
	//  end_time = clock();
	//  double shell_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	//  cout << "希尔排序时间:" << shell_time << endl;
	//
	//
	// //堆排序
	//  start_time = clock();
	// heap_sort(n);
	// end_time = clock();
	// double heap_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	// cout << "堆排序序时间:" << heap_time << endl;
	radixsort(n);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
