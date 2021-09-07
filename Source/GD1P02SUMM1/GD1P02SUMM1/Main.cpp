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
#include <string>
#include <sstream>

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

std::string m_StringOutput;

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

		if (m_iInput != ZERO && m_iInput != ONE)
		{
			std::cout << "  Sorry. I Only Accept The Integers 1 & 0.";
			m_iInput = _getch();

			// Valid
			if (m_iInput == ZERO || m_iInput == ONE)
			{
				break;
			}

			// Clear Screen
			system("cls");
			m_iInput = NULL;
		}
		system("cls");
	}
	
	// Set Line 1 Output Value
	if (m_iInput == ZERO)
	{
		m_iAscendingValue = 0;
		m_bIsDescending = false;
	}
	else if (m_iInput == ONE)
	{
		m_iAscendingValue = 1;
		m_bIsDescending = true;
	}

	// Clear Input And Screen
	m_iInput = NULL;
	system("cls");
	m_StringOutput = "";

	// Line 2 Input Check Loop 
	while (m_StringOutput.size() < 7)
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
		std::cout << m_StringOutput;

		// Input
		m_iInput = _getch();

		// Invalid
		if ((m_iInput < ZERO || m_iInput > NINE) && m_iInput != 13)
		{
			std::cout << "  Sorry. I Only Accept Integers";
			
			m_iInput = _getch();

			// Valid After Invalid
			if (m_iInput >= ZERO && m_iInput <= NINE)
			{
				// Take In The Input
				m_StringOutput += (m_iInput);

				m_iInput = NULL;
				system("cls");
				continue;
			}
			// Carriage Return Pressed And Size > 0?
			else if (m_iInput == 13 && m_StringOutput != "")
			{
				m_iInput = NULL;
				break;
			}
			// Carriage Return And Empty
			else if (m_iInput == 13 && m_StringOutput == "")
			{
				m_iInput = NULL;
				system("cls");
				continue;
			}

			// Clear Screen
			system("cls");
			m_iInput = NULL;
		}
		// Carriage Return Pressed and Size > 0?
		else if (m_iInput == 13 && m_StringOutput != "")
		{
			m_iInput = NULL;
			break;
		}
		// Carriage Return And Empty
		else if (m_iInput == 13 && m_StringOutput == "")
		{
			m_iInput = NULL;
			system("cls");
			continue;
		}
		// Valid
		else
		{
			m_StringOutput += (m_iInput);

			m_iInput = NULL;
			m_StringOutput == "";
			system("cls");
		}
	}

	// Convert String To Int And Set Line 2 Output Value
	std::stringstream stream(m_StringOutput);
	stream >> m_iNumberOfElements;

	// Clear Input And Screen
	int inputCounter = NULL;
	m_iInput = NULL;
	m_StringOutput = "";
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
		// While Input Value Is Less Than 7 Digits
		while (m_StringOutput.size() < 7)
		{
			// Title
			iSort::PrintTitle();

			// LINE 1
			iSort::PrintPrompt(1);
			std::cout << m_iAscendingValue << std::endl << std::endl;

			// LINE 2
			iSort::PrintPrompt(2);
			std::cout << m_iNumberOfElements << std::endl << std::endl;

			iSort::PrintPrompt(3);

			if (m_StringOutput == "")
			{
				for (int i = 0; i < m_iNumberOfElements; i++)
				{
					if (m_iArray[i] != -1)
					{
						std::cout << m_iArray[i] << " ";
					}
				}
			}
			else
			{
				for (int i = 0; i < m_iNumberOfElements; i++)
				{
					if (m_iArray[i] != -1)
					{
						std::cout << m_iArray[i] << " ";
					}
				}
				std::cout << m_StringOutput;
			}

			// Input
			m_iInput = _getch();

			// Invalid
			if ((m_iInput < ZERO || m_iInput > NINE) && m_iInput != 32)
			{
				// Error
				std::cout << "  Sorry. I Only Accept Integers";

				// Wait For Next Input
				m_iInput = _getch();

				// Valid After Invalid
				if (m_iInput >= ZERO && m_iInput <= NINE)
				{
					// Take In The Input
					m_StringOutput += (m_iInput);

					m_iInput = NULL;
					system("cls");
					continue;
				}
				// Space Pressed And Size > 0?
				else if (m_iInput == 32 && m_StringOutput != "")
				{
					m_iInput = NULL;
					break;
				}
				// Space Check And Empty
				else if (m_iInput == 32 && m_StringOutput == "")
				{
					m_iInput = NULL;
					system("cls");
					continue;
				}

				// Clear Screen
				system("cls");
				m_iInput = NULL;
			}
			// Space Pressed And Size > 0?
			else if (m_iInput == 32 && m_StringOutput != "")
			{
				m_iInput = NULL;
				break;
			}
			// Space Check And Empty
			else if (m_iInput == 32 && m_StringOutput == "")
			{
				m_iInput = NULL;
				system("cls");
				continue;
			}
			// Valid
			else
			{
				// Take In The Input
				m_StringOutput += (m_iInput);

				m_iInput = NULL;
				system("cls");
				continue;
			}
		}

		// Convert String To Int And Set Line 3 Output Value
		std::stringstream stream(m_StringOutput);
		stream >> m_iArray[i];

		m_StringOutput = "";
		system("cls");
	}

	//
	// Final Result / Output
	//
	
	// Title
	iSort::PrintTitle();

	// LINE 1 (Ascending?)
	iSort::PrintPrompt(1);
	std::cout << m_iAscendingValue << std::endl << std::endl;

	// LINE 2 (Number Of Elements)
	iSort::PrintPrompt(2);
	std::cout << m_iNumberOfElements << std::endl << std::endl;

	// Number Of Elements Is 0
	if (m_iNumberOfElements == 0)
	{
		std::cout << "Nothing To Sort." << std::endl;
		Sleep(unsigned(1000));
		std::cout << "Exiting Program." << std::endl;
		Sleep(unsigned(1000));
	}
	// else, Valid Size
	else
	{
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
		Sleep(unsigned(1000));
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
		std::cout << std::endl << std::endl;
	}

	//
	// Cleanup
	//
	delete[] m_iArray;
	m_iArray = nullptr;

	//
	// Return Holt
	//
	std::cout << "Press Any Key To Exit.";
	m_iInput = _getch();
	std::cout << std::endl << std::endl;

	//
	// Return
	//
	return NULL;
}