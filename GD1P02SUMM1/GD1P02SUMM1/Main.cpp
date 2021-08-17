#include <conio.h>
#include "CQuickSort.h"

#define ASCIIOFFSET 48

using namespace std;

enum INPUT
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
INPUT m_InputValues = INPUT::ZERO;

bool m_bIsDescending = false;

int m_iInput = NULL;
int m_iAscendingValue = NULL;

int m_iArraySize = NULL;
int m_iNumberOfElements = NULL;

void PrintTitle()
{

	string m_Art = " _____       _      _    _____            _  "  "\n"
					"|  _  |     (_)    | |  /  ___|          | | " "\n"
					"| | | |_   _ _  ___| | _\ `--.  ___  _ __| |_" "\n"
					"| | | | | | | |/ __| |/ /`--. \/ _ \| '__| __|" "\n"
					"\ \/' / |_| | | (__|   </\__/ / (_) | |  | |_ " "\n"
					" \_/\_\\__,_|_|\___|_|\_\____/ \___/|_|   \__|" "\n"
				"                                              ";

	cout << m_Art << endl;
}

int main()
{
	system("cls");

	CQuickSort* newQuickSort = new CQuickSort();

	// Line 1 Input Check
	while (m_iInput != ZERO && m_iInput != ONE)
	{
		PrintTitle();
		m_iInput = _getch();
		system("cls");
	}
	
	// Set Line 1 Output Value
	if (m_iInput == ZERO)
	{
		m_iAscendingValue = 0;
		m_bIsDescending = false;
		PrintTitle();
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}
	else if (m_iInput == ONE)
	{
		m_iAscendingValue = 1;
		m_bIsDescending = true;
		PrintTitle();
		std::cout << m_iAscendingValue << std::endl << std::endl;
	}

	// Set Line 2 Output Value
	m_iInput = NULL;
	system("cls");
	while (m_iInput <= ZERO)
	{
		PrintTitle();
		if (!m_bIsDescending)
		{
			std::cout << 0 << std::endl << std::endl;
		}
		else if (m_bIsDescending)
		{
			std::cout << 1 << std::endl << std::endl;
		}
		
		m_iInput = _getch();
		system("cls");
	}
	m_iNumberOfElements = m_iInput - ASCIIOFFSET;
	

	// Declare And Calculate Size Of Input Array	
	int* m_iArray = new int[m_iNumberOfElements];																		//int m_iArray[10]{ 20, 45, 71, 91, 1, 5, 40, 31, 9, 6 };
	

	// Set Line 3 Output Value
	int inputCounter = 0;
	system("cls");
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		PrintTitle();
		if (!m_bIsDescending)
		{
			std::cout << 0 << std::endl << std::endl;
		}
		else if (m_bIsDescending)
		{
			std::cout << 1 << std::endl << std::endl;
		}

		m_iInput = NULL;
		if (m_iInput == NULL)
		{
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
		system("cls");
	}
	
	m_iArraySize = sizeof(*m_iArray) / sizeof(m_iArray[0]);
	PrintTitle();


	// LINE 1
	cout << m_iAscendingValue << endl << endl;
	//

	// LINE 2
	cout << m_iNumberOfElements << endl << endl;
	//

	// LINE 3
	newQuickSort->QuickSort(m_iArray, 0, m_iArraySize - 1);
	//
	
	// Print Sorted Array
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		std::cout << m_iArray[i] << " ";
	}

	// Cleanup
	delete[] m_iArray;
	delete newQuickSort;
	m_iArray = nullptr;
	newQuickSort = nullptr;


	return NULL;
}