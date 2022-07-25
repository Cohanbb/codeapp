#ifndef __SORT_H__
#define __SORT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Insert Sort 直接插入排序 */
void insert_sort(int a[], int n);

/* Binary Insert Sort 折半插入排序 */
void insert_sortt(int a[], int n);

/* Shell Sort 希尔排序 */
void shell_sort(int a[], int n);

/* Select Sort 选择排序 */
void select_sort(int a[], int n);

/* Heap Sort 堆排序 */
void heap_sort(int a[], int n);

/* Bubble Sort 冒泡排序 */
void bubble_sort(int a[], int n);

/* Quick Sort 快速排序 */
void quick_sort(int a[], int low, int high);

/* 非递归实现归并排序 */
void merge_sort(int a[], int n);

void showarray(int a[], int n);

#endif