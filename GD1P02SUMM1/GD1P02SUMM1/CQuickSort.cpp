#include "CQuickSort.h"

CQuickSort::CQuickSort()
{
}

CQuickSort::~CQuickSort()
{
}

void CQuickSort::Swap(int* _value1, int* _value2)
{
	int temp = *_value1;
	*_value1 = *_value2;
	*_value2 = temp;
}

int CQuickSort::Partition(int m_Array[], int _smallestValueIndex, int _largestValueIndex)
{
	int pivot = m_Array[_largestValueIndex]; // pivot 
	int i = (_smallestValueIndex - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = _smallestValueIndex; j <= _largestValueIndex - 1; j++)
	{
		// If current element is smaller than the pivot 
		if (m_Array[j] < pivot)
		{
			i++; // increment index of smaller element 
			Swap(&m_Array[i], &m_Array[j]);
		}
	}
	Swap(&m_Array[i + 1], &m_Array[_largestValueIndex]);
	return (i + 1);
}

void CQuickSort::QuickSort(int m_Array[], int _smallestValueIndex, int _largestValueIndex)
{
	if (_smallestValueIndex < _largestValueIndex)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = Partition(m_Array, _smallestValueIndex, _largestValueIndex);

		// Separately sort elements before 
		// partition and after partition 
		QuickSort(m_Array, _smallestValueIndex, pi - 1);
		QuickSort(m_Array, pi + 1, _largestValueIndex);
	}
}

void CQuickSort::Display(int m_Array[])
{
	int n = sizeof(*m_Array) / sizeof(m_Array[0]);
	for (int i = 0; i < n; i++)
	{
		std::cout << m_Array[i] << " ";
	}
		
}
