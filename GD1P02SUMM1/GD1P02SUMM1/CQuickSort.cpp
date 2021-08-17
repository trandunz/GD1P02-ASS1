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

int CQuickSort::Partition(int* m_Array, int _smallestValueIndex, int _largestValueIndex)
{
	int largestValue = m_Array[_largestValueIndex];
	int tempIndex = _smallestValueIndex - 1;

	for (int i = _smallestValueIndex; i < _largestValueIndex; i++)
	{
		if (m_Array[i] <= largestValue)
		{
			tempIndex++;
			Swap(&m_Array[tempIndex], &m_Array[i]);
		}
	}
	Swap(&m_Array[tempIndex + 1], &m_Array[_largestValueIndex]);
	return (tempIndex + 1);
}

void CQuickSort::QuickSort(int* m_Array, int _smallestValueIndex, int _largestValueIndex)
{
	if (_smallestValueIndex < _largestValueIndex)
	{
		int q = Partition(m_Array, _smallestValueIndex, _largestValueIndex);
		QuickSort(m_Array, _smallestValueIndex, q - 1);
		QuickSort(m_Array, q + 1, _largestValueIndex);
	}
}

void CQuickSort::Display(int* m_Array)
{
	int n = sizeof(*m_Array) / sizeof(m_Array[0]);
	for (int i = 0; i < n; i++)
	{
		std::cout << m_Array[i] << " ";
	}
		
}
