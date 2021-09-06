//			  ---------
//			  | iSort |
//			  ---------
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : Main.cpp
// Description : The Main Implementation File For The QuickSort Program.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma warning (disable :  26812) // "Prefer Enum Class" :P

// Non-Local Includes
#include <conio.h>
#include <Windows.h>

// Local Includes
#include "iSort.h"

using namespace iSORT;

// Global Variables
SORT_TYPE m_SortType = ASCENDING;
KINPUT m_InputValues = ZERO;

bool m_bIsDescending = false;

int m_iInput = NULL;
int m_iAscendingValue = NULL;
int m_iNumberOfElements = NULL;

/// <summary>
/// Main Implementation Function For The Programs Implementation File.
/// </summary>
/// <returns></returns>
int main()
{
	system("cls");

	// Line 1 Input Check
	while (m_iInput != ZERO && m_iInput != ONE)
	{
		iSort::PrintTitle();
		iSort::PrintPrompt(1);

		m_iInput = _getch();
		system("cls");
	}
	
	// Set Line 1 Output Value
	if (m_iInput == ZERO)
	{
		m_iAscendingValue = 0;
		m_bIsDescending = false;
		iSort::PrintTitle();
		iSort::PrintPrompt(1);
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}
	else if (m_iInput == ONE)
	{
		m_iAscendingValue = 1;
		m_bIsDescending = true;

		iSort::PrintTitle();
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}

	// Clear Input And Screen
	m_iInput = NULL;
	system("cls");

	// Line 2 Input Check
	while (m_iInput <= ZERO)
	{
		// Title
		iSort::PrintTitle();
		
		// Line 1
		iSort::PrintPrompt(1);
		if (!m_bIsDescending)
		{
			std::cout << 0 << std::endl << std::endl;
		}
		else if (m_bIsDescending)
		{
			std::cout << 1 << std::endl << std::endl;
		}
		
		// Line 2
		iSort::PrintPrompt(2);

		// Input
		m_iInput = _getch();

		// Clear Screen
		system("cls");
	}

	// Set Line 2 Output Value
	m_iNumberOfElements = m_iInput - ASCIIOFFSET;
	

	// Clear Input And Screen
	int inputCounter = NULL;
	system("cls");

	// Declare And Init Input Array
	int* m_iArray = new int[m_iNumberOfElements] {};
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		m_iArray[i] = nullInput;
	}


	// Line 3 Input Check and Set Output Value
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		// Title
		iSort::PrintTitle();

		// LINE 1
		iSort::PrintPrompt(1);
		std::cout << m_iAscendingValue << std::endl << std::endl;

		// LINE 2
		iSort::PrintPrompt(2);
		std::cout << m_iNumberOfElements << std::endl << std::endl;

		// LINE 3
		m_iInput = NULL;
		if (m_iInput == NULL)
		{
			
			iSort::PrintPrompt(3);
			for (int i = 0; i < m_iNumberOfElements; i++)
			{
				if (m_iArray[i] != -1)
				{
					std::cout << m_iArray[i] << " ";
				}
			}
			m_iInput = _getch();

			// Set OutPut Value
			if (m_iInput >= ZERO && m_iInput <= NINE)
			{
				m_iArray[i] = m_iInput - ASCIIOFFSET;
			}
			else
			{
				i = 0;
			}
		}

		// Clear Screen Ready For Final Result
		system("cls");
	}

	//
	// Final Result
	//
	
	// Title
	iSort::PrintTitle();

	// LINE 1 (Ascending?)
	iSort::PrintPrompt(1);
	std::cout << m_iAscendingValue << std::endl << std::endl;

	// LINE 2 (Number Of Elements)
	iSort::PrintPrompt(2);
	std::cout << m_iNumberOfElements << std::endl << std::endl;

	// LINE 3 (Unsorted Array)
	iSort::PrintPrompt(3);
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		std::cout << m_iArray[i] << " ";
	}

	// Sort
	iSort::QuickSort(m_iArray, m_iNumberOfElements, m_bIsDescending);
	//CSort::InsertSort(m_iArray, m_iNumberOfElements);
	//CSort::SelectionSort(m_iArray, m_iNumberOfElements);
	//CSort::BubbleSort(m_iArray, m_iNumberOfElements);

	// Pretending To Sort (Its Already Sorted!)
	std::cout << std::endl << std::endl;
	std::cout << "Sorting.";
	Sleep(unsigned (1000));
	std::cout << ".";
	Sleep(unsigned(1000));
	std::cout << ".";
	Sleep(unsigned(1000));

	// Spacing
	std::cout << std::endl << std::endl;
	
	// Print Sorted Array
	iSort::PrintPrompt(4);
	iSort::Display(m_iArray, m_iNumberOfElements);

	// Spacing
	std::cout <<  std::endl << std::endl;

	//
	// Cleanup
	//
	delete[] m_iArray;
	m_iArray = nullptr;

	//
	// Return
	//
	return NULL;
}