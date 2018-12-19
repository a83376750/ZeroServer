#pragma once

class GameSort
{
public:
	static void BucketSort(int *array, size_t array_size, size_t bucket_size, int cond = 0);
	static void QuickSort(int *array, int beg, int end);
	static void InsertSort(int *array, size_t array_size);
	static void BubbleSort(int *array, size_t array_size);
};

