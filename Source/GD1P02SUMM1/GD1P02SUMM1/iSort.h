// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : iSort.h
// Description : The Header File For The iSort Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma warning (disable :  26812) // "Prefer Enum Class" :P

#pragma once
#ifndef _iSort_H__
#define _iSort_H__

// Non-Local Includes
#include <iostream>
#include <vector>

// #defines (followed visual studio's recommendation and made them constexpr)
constexpr auto ASCIIOFFSET = 48;
constexpr auto nullInput = -1;

namespace iSORT
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

static class iSort
{
public:
	static void PrintTitle();
	static void PrintPrompt(int _prompNumber);

	static void Swap(int* _value1, int* _value2);

	static void QuickSort(int* _array, int _arrayStartIndex, int _arrayEndIndex, bool _ascending);
	static void QuickSort(int* _array, int _arrayLength, bool _ascending);

	static void InsertSort(int* _array, int _arrayLength);

	static void SelectionSort(int* _array, int _arrayLength);

	static void BubbleSort(int* _array, int _arrayLength);

	static void Display(int* _array, int _arrayLength);
};
#endif
