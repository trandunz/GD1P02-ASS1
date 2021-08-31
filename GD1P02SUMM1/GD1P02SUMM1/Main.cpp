#include <conio.h>
#include <Windows.h>
#include "CQuickSort.h"

#define ASCIIOFFSET 48

using namespace std;

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

SORT_TYPE m_SortType = SORT_TYPE::ASCENDING;
KINPUT m_InputValues = KINPUT::ZERO;

bool m_bIsDescending = false;

int m_iInput = NULL;
int m_iAscendingValue = NULL;

int m_iArraySize = NULL;
int m_iNumberOfElements = NULL;

void PrintTitle()
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

void PrintPromp(int _prompNumber)
{
	switch (_prompNumber)
	{
	case 1:
	{
		cout << "QuickSort In, Ascending (0)/Descending (1) ,Order" << endl << "---------------------------------------------------" << endl;
		break;
	}
	case 2:
	{
		cout << "Number Of Elements" << endl << "--------------------" << endl;
		break;
	}
	case 3:
	{
		cout << "Element Values" << endl << "----------------" << endl;
		break;
	}
	case 4:
	{
		cout << "Sorted Values" << endl << "---------------" << endl;
		break;
	}
	default:
	{
		PrintPromp(1);
		PrintPromp(2);
		PrintPromp(3);
		PrintPromp(4);
		break;
	}
	}
}

int main()
{
	system("cls");

	CQuickSort* newQuickSort = new CQuickSort();

	// Line 1 Input Check
	while (m_iInput != ZERO && m_iInput != ONE)
	{
		PrintTitle();
		PrintPromp(1);

		m_iInput = _getch();
		system("cls");
	}
	
	// Set Line 1 Output Value
	if (m_iInput == ZERO)
	{
		m_iAscendingValue = 0;
		m_bIsDescending = false;
		PrintTitle();

		PrintPromp(1);
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}
	else if (m_iInput == ONE)
	{
		m_iAscendingValue = 1;
		m_bIsDescending = true;

		PrintTitle();
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}

	// Clear Input And Screen
	m_iInput = NULL;
	system("cls");

	// Set Line 2 Output Value
	while (m_iInput <= ZERO)
	{
		// Title
		PrintTitle();
		
		// Line 1
		PrintPromp(1);
		if (!m_bIsDescending)
		{
			std::cout << 0 << std::endl << std::endl;
		}
		else if (m_bIsDescending)
		{
			std::cout << 1 << std::endl << std::endl;
		}
		
		// Line 2
		PrintPromp(2);

		// Input
		m_iInput = _getch();

		// Clear Screen
		system("cls");
	}
	m_iNumberOfElements = m_iInput - ASCIIOFFSET;
	

	// Declare And Calculate Size Of Input Array	
	int* m_iArray = new int[m_iNumberOfElements] {};																		//int m_iArray[10]{ 20, 45, 71, 91, 1, 5, 40, 31, 9, 6 };
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		m_iArray[i] = -1;
	}
	

	// Clear Input And Screen
	int inputCounter = 0;
	system("cls");

	// Line 3 Input Loop and Prompt
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		// Title
		PrintTitle();

		// LINE 1
		PrintPromp(1);
		cout << m_iAscendingValue << endl << endl;
		//

		// LINE 2
		PrintPromp(2);
		cout << m_iNumberOfElements << endl << endl;

		m_iInput = NULL;
		if (m_iInput == NULL)
		{
			
			PrintPromp(3);
			for (int i = 0; i < m_iNumberOfElements; i++)
			{
				if (m_iArray[i] != -1)
				{
					std::cout << m_iArray[i] << " ";
				}
			}
			m_iInput = _getch();
			if (m_iInput >= ZERO && m_iInput <= NINE)
			{
				m_iArray[i] = m_iInput - ASCIIOFFSET;
			}
			else
			{
				i = 0;
			}
		}

		// Clear Screen
		system("cls");
	}
	
	// Get Size Of Array
	m_iArraySize = sizeof(*m_iArray) / sizeof(m_iArray[0]);
	
	// Title
	PrintTitle();

	// LINE 1 (Ascending?)
	PrintPromp(1);
	cout << m_iAscendingValue << endl << endl;
	//

	// LINE 2 (Number Of Elements)
	PrintPromp(2);
	cout << m_iNumberOfElements << endl << endl;

	// LINE 3 (Unsorted Array)
	PrintPromp(3);
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		std::cout << m_iArray[i] << " ";
	}

	// Sort
	newQuickSort->QuickSort(m_iArray, 0, m_iArraySize - 1);
	cout << endl << endl;
	cout << "Sorting.";
	Sleep(unsigned (1000));
	cout << ".";
	Sleep(unsigned(1000));
	cout << ".";
	Sleep(unsigned(1000));

	// Spacing
	cout << endl << endl;
	
	// Print Sorted Array
	PrintPromp(4);
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		std::cout << m_iArray[i] << " ";
	}

	// Spacing
	cout <<  endl << endl;

	// Cleanup
	delete[] m_iArray;
	delete newQuickSort;
	m_iArray = nullptr;
	newQuickSort = nullptr;

	// Return
	return NULL;
}