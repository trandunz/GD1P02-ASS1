#pragma once
#include <iostream>
#include <vector>

class CQuickSort
{
public:
	CQuickSort();
	~CQuickSort();

	void Swap(int* _value1, int* _value2);

	bool IndexGreaterThan(int index1, int index2)
	{
		if (index1 > index2)
		{
			return true;
		}
		return false;
	}

	int Partition(int* m_Array, int _smallestValueIndex, int _largestValueIndex);
	
	void QuickSort(int* m_Array, int _smallestValueIndex, int _largestValueIndex);
	
	void Display(int* m_Array);
};

