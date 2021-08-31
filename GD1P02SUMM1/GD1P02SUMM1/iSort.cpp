// Local Includes
#include "iSort.h"

/// <summary>
/// Prints The ASSCI Art "QuickSort" To The Console Window.
/// </summary>
void iSort::PrintTitle()
{
	std::cout << R"(
-----------------------------------------------------------
   ____          _        _      _____               _   
  / __ \        (_)      | |    / ____|             | |  
 | |  | | _   _  _   ___ | | __| (___    ___   _ __ | |_ 
 | |  | || | | || | / __|| |/ / \___ \  / _ \ | '__|| __|
 | |__| || |_| || || (__ |   <  ____) || (_) || |   | |_ 
  \___\_\ \__,_||_| \___||_|\_\|_____/  \___/ |_|    \__|
                                                         
-----------------------------------------------------------
)" << '\n';
}

/// <summary>
/// Prints The Prompt Specified By The Input Parameter. Inputting A Prompt Number Other Than 1,2,3 or 4 Will Print Out All Prompts.
/// Takes In: int (Prompt Number To Display).
/// </summary>
/// <param name="_promptNumber"></param>
void iSort::PrintPrompt(int _promptNumber)
{
	switch (_promptNumber)
	{
	case 1:
	{
		std::cout << "QuickSort In, Ascending (1)/Descending (0) ,Order" << std::endl << "---------------------------------------------------" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << "Number Of Elements" << std::endl << "--------------------" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "Element Values" << std::endl << "----------------" << std::endl;
		break;
	}
	case 4:
	{
		std::cout << "Sorted Values" << std::endl << "---------------" << std::endl;
		break;
	}
	default:
	{
		PrintPrompt(1);
		PrintPrompt(2);
		PrintPrompt(3);
		PrintPrompt(4);
		break;
	}
	}
}

/// <summary>
/// Swaps The Two Specified Values (Meant To Be Two int's Inside Of The Same Array).
/// Takes In: int*, int*.
/// </summary>
/// <param name="_value1"></param>
/// <param name="_value2"></param>
void iSort::Swap(int* _value1, int* _value2)
{
	int temp = *_value1;
	*_value1 = *_value2;
	*_value2 = temp;
}

/// <summary>
/// QuickSorts A Section Of The Specified int Array Bounded Between The  Start And End Index Values. The Sort Occurs In Eather Ascending Or Descending Order Based On The Input Parameter (_ascending).
/// Takes In: int* (The Array), int (Start Index), int (End Index), bool (Ascending?).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayStartIndex"></param>
/// <param name="_arrayEndIndex"></param>
/// <param name="_ascending"></param>
void iSort::QuickSort(int* _array, int _arrayStartIndex, int _arrayEndIndex, bool _ascending)
{
	// Ascending
	if (_ascending)
	{
		int start = _arrayStartIndex;
		int pivot = _array[start]; // Picking Start For Best Complexity
		int end = _arrayEndIndex;

		if (_arrayStartIndex < _arrayEndIndex)
		{
			// Increment And Decrement Counters Then Swap There Values Until They Cross Over
			while (start < end)
			{
				// Decrement End Counter Until Pivot < End Counter Value
				while (_array[end] >= pivot && start < end)
				{
					end--;
				}
				// Swap Start Counter Value With End Counter Value
				Swap(&_array[start],&_array[end]);

				// Increment Start Counter Until Pivot > Start Counter Value
				while (_array[start] <= pivot && start < end)
				{
					start++;
				}
				// Swap End Counter Value With Start Counter Value
				Swap(&_array[end], &_array[start]);
			}

			// Assign Pivot To Correct Position In Array
			_array[start] = pivot;

			// Repeat For Left Of Pivot
			QuickSort(_array, _arrayStartIndex, start - 1, _ascending);

			// Repeat For Right Of Pivot
			QuickSort(_array, end + 1, _arrayEndIndex, _ascending);
		}
	}
	// Descending
	else if (!_ascending)
	{
		int start = _arrayStartIndex;
		int pivot = _array[start]; // Picking Start For Best Complexity
		int end = _arrayEndIndex;
		
		if (_arrayStartIndex < _arrayEndIndex)
		{
			// Increment And Decrement Counters Then Swap There Values Until They Cross Over
			while (start < end)
			{
				// Decrement End Counter Until Pivot > End Counter Value
				while (_array[end] <= pivot && start < end)
				{
					end--;
				}
				// Swap Start Counter Value With End Counter Value
				Swap(&_array[start], &_array[end]);

				// Increment Start Counter Until Pivot < Start Counter Value
				while (_array[start] >= pivot && start < end)
				{
					start++;
				}
				// Swap End Counter Value With Start Counter Value
				Swap(&_array[end], &_array[start]);
			}

			// Assign Pivot To Correct Position In Array
			_array[start] = pivot;

			// Repeat For Left Of Pivot
			QuickSort(_array, _arrayStartIndex, start - 1, _ascending);

			// Repeat For Right Of Pivot
			QuickSort(_array, end + 1, _arrayEndIndex, _ascending);
		}
	}
}

/// <summary>
/// QuickSorts The Specified int Array. The Sort Occurs In Eather Ascending Or Descending Order Based On The Input Parameter (_ascending).
/// Takes In: int* (The Array), int (Array Length), bool (Ascending?).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayLength"></param>
/// <param name="_ascending"></param>
void iSort::QuickSort(int* _array, int _arrayLength, bool _ascending)
{
	// Calls QuickSort For The Whole Array
	iSort::QuickSort(_array, 0 , _arrayLength - 1, _ascending);
}

/// <summary>
/// InsertSorts The Specified int Array. 
/// Takes In: int* (The Array), int (Array Length).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayLength"></param>
void iSort::InsertSort(int* _array, int _arrayLength)
{
	int i = NULL;
	int key = NULL;
	int j = NULL;

	for (i = 1; i < _arrayLength; i++)
	{
		key = _array[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && _array[j] > key)
		{
			_array[j + 1] = _array[j];
			j = j - 1;
		}
		_array[j + 1] = key;
	}
}

/// <summary>
/// SelectionSorts The Specified int Array. 
/// Takes In: int* (The Array), int (Array Length).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayLength"></param>
void iSort::SelectionSort(int* _array, int _arrayLength)
{
	int i = NULL;
	int j = NULL;
	int min_idx = NULL;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < _arrayLength - 1; i++)
	{
		min_idx = i;

		// Find the minimum element in unsorted array
		for (j = i + 1; j < _arrayLength; j++)
		{
			if (_array[j] < _array[min_idx])
			{
				min_idx = j;
			}
		}

		// Swap the found minimum element with the first element
		Swap(&_array[min_idx], &_array[i]);
	}
}

/// <summary>
/// BubbleSorts The Specified int Array. 
/// Takes In: int* (The Array), int (Array Length).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayLength"></param>
void iSort::BubbleSort(int* _array, int _arrayLength)
{
	int i = NULL;
	int j = NULL;

	for (i = 0; i < _arrayLength - 1; i++)
	{
		// Last i elements are already in place 
		for (j = 0; j < _arrayLength - i - 1; j++)
		{
			if (_array[j] > _array[j + 1])
			{
				Swap(&_array[j], &_array[j + 1]);
			}
		}
	}
}

/// <summary>
/// Prints The Values For The Specified Input Array Up Until The Specified Index (_arrayEndIndex).
/// Takes In; int* (The Array), int (End Index).
/// </summary>
/// <param name="_array"></param>
/// <param name="_arrayEndIndex"></param>
void iSort::Display(int* _array, int _arrayLength)
{
	for (int i = 0; i < _arrayLength; i++)
	{
		std::cout << _array[i] << " ";
	}
}
