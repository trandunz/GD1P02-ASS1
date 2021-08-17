#include <iostream>
#include <conio.h>
//#include <CQuickSort.h>

#define ZERO 48
#define ONE 49

using namespace std;

enum SORT_TYPE
{
	ASCENDING,
	DESCENDING,
};

SORT_TYPE m_SortType = SORT_TYPE::ASCENDING;

int m_Input = NULL;

int m_AscendingValue = NULL;
int m_NumberOfElements = NULL;

bool m_bIsDescending = false;

int main()
{
	// Line 1 Input Check
	while (m_Input != ZERO && m_Input != ONE)
	{
		system("cls");
		m_Input = _getch();
	}
	
	// Set Line 1 output value
	if (m_Input == ZERO)
	{
		m_AscendingValue = 0;
		m_bIsDescending = false;
	}
	else if (m_Input == ONE)
	{
		m_AscendingValue = 1;
		m_bIsDescending = true;
	}

	// Set Line 2 output value
	m_Input = NULL;
	while (m_Input <= ZERO)
	{
		system("cls");
		m_Input = _getch();
	}
	m_NumberOfElements = m_Input;

	// LINE 1
	cout << m_AscendingValue << endl << endl;
	//

	// LINE 2
	cout << m_NumberOfElements << endl << endl;
	//

	// LINE 3

	//

	if (!m_bIsDescending)
	{

	}
	else if (m_bIsDescending)
	{

	}

	return NULL;
}