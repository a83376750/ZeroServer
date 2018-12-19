#include "Sort.h"

#include <map>

void GameSort::BucketSort(int *array, size_t array_size, size_t bucket_size, int cond /*= 0*/)
{
	if (array == nullptr || array_size <= 0 || bucket_size <= 0)
		return;

	typedef std::map<int, size_t> BucketMap;
	BucketMap buckets;
	for (size_t i = 0; i < array_size; ++i)
	{
		buckets[array[i]]++;
	}

	size_t i = 0;
	for (BucketMap::iterator it = buckets.begin(); it != buckets.end(); ++it)
	{
		while ((int)it->second-- > cond)
			array[i++] = it->first;
	}
}

void GameSort::QuickSort(int *array, int beg, int end)
{
	if (beg < end)
	{
		int left = beg;
		int right = end;
		int pivot = array[beg];
		while (left < right)
		{
			while (left < right && array[right] >= pivot)
				right--;
			if (left < right)
				array[left++] = array[right];

			while (left < right && array[left] < pivot)
				left++;
			if (left < right)
				array[right--] = array[left];
		}
		array[left] = pivot;
		QuickSort(array, beg, left - 1);
		QuickSort(array, left + 1, end);
	}
}

void GameSort::InsertSort(int *array, size_t array_size)
{
	for (int i = 1; i < (int)array_size; ++i)
	{
		int temp = array[i];
		int j = 0;
		for (j = i - 1; j >= 0, array[j] > temp; --j)
			array[j + 1] = array[j];
		array[j + 1] = temp;
	}
}

void GameSort::BubbleSort(int *array, size_t array_size)
{
	for (int i = 0; i < (int)array_size; ++i)
	{
		for (int j = i + 1; j < (int)array_size; ++j)
		{
			if (array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
