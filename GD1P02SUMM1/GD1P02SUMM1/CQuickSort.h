#pragma once
#include <iostream>
#include <vector>

// #defines (followed visual studio's recommendation and made them constexpr)
constexpr auto ASCIIOFFSET = 48;
constexpr auto nullInput = -1;

namespace QST
{
	enum KINPUT
	{
		ZERO = 48,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
	};

	enum SORT_TYPE
	{
		ASCENDING,
		DESCENDING,
	};
};

static class CQuickSort
{
public:
	static void PrintTitle();
	static void PrintPrompt(int _prompNumber);

	static void Swap(int* _value1, int* _value2);

	static void QuickSort(int* _array, int _arrayStartIndex, int _arrayEndIndex, bool _ascending);
	static void QuickSort(int* _array, int _arrayLength, bool _ascending);

	static void Display(int* _array, int _arrayEndIndex);
};

