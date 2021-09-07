//			  ---------
//			  | DeQue |
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
// Description : The Main Implementation File For The DeQue Program.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma warning( disable : 26812) // "Prefer Enum Class" :P

// Non-Local Includes 
#include <conio.h>

// Local Includes
#include "CDeQue.h"

// #Defines
constexpr auto ZERO = 48;
constexpr auto ONE = 49;
constexpr auto TWO = 50;
constexpr auto THREE = 51;
constexpr auto FOUR = 52;
constexpr auto FIVE = 53;
constexpr auto SIX = 54;
constexpr auto SEVEN = 55;
constexpr auto EIGHT = 56;
constexpr auto NINE = 57;

using namespace std;

// The Different States The Program Can Be In
enum STATE
{
	MainMenu,
	EnqueueFront,
	EnqueueBack,
	DequeueFront,
	DequeueBack,
	PeekFront,
	PeekBack,
	IsEmpty,
	Exit,
};

// Global Variables
STATE m_RuntimeState = STATE::MainMenu;

void PrintMainMenu();
void PrintTitle();

int m_iMenuChoice = NULL;

bool m_bExit = false;

/// <summary>
/// Main Implementation Function For The Programs Implementation File.
/// </summary>
/// <returns></returns>
int main()
{
	CDeQue* newQueue = new CDeQue;
	
	// While The Program Is Open...
	while (!m_bExit)
	{
		switch (m_RuntimeState)
		{
		case STATE::MainMenu:
		{
			// Init Menu Choice
			m_iMenuChoice = NULL;
			
			// Menu Choice Check Loop
			while (m_iMenuChoice < ONE || m_iMenuChoice > EIGHT)
			{
				// Reset Input
				m_iMenuChoice = NULL;
				
				// Title
				PrintTitle();

				// Print Menu Options
				PrintMainMenu();

				// Get Input
				m_iMenuChoice = _getch();

				// Invalid
				if (m_iMenuChoice < ONE || m_iMenuChoice > EIGHT)
				{
					// Error
					std::cout << "  Sorry. I Only Accept The Given Inputs.";

					// Wait For Next Input
					m_iMenuChoice = _getch();

					// Valid After Invalid
					if (m_iMenuChoice >= ONE && m_iMenuChoice <= EIGHT)
					{
						// Clear Screen
						system("cls");
						break;
					}
				}
				system("cls");
			}

			// Menu Choices
			switch (m_iMenuChoice)
			{
			case ONE:
			{
				m_RuntimeState = STATE::EnqueueFront;
				break;
			}
			case TWO:
			{
				m_RuntimeState = STATE::EnqueueBack;
				break;
			}
			case THREE:
			{
				m_RuntimeState = STATE::DequeueFront;
				break;
			}
			case FOUR:
			{
				m_RuntimeState = STATE::DequeueBack;
				break;
			}
			case FIVE:
			{
				m_RuntimeState = STATE::PeekFront;
				break;
			}
			case SIX:
			{
				m_RuntimeState = STATE::PeekBack;
				break;
			}
			case SEVEN:
			{
				m_RuntimeState = STATE::IsEmpty;
				break;
			}
			case EIGHT:
			{
				m_RuntimeState = STATE::Exit;
				break;
			}
			default:
			{
				continue;
			}
			}

			break;
		}

		//
		// RunTime States
		//
		case STATE::EnqueueFront:
		{
			newQueue->Enqueue_Front(rand() % 100);

			// Display
			newQueue->Display();

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::EnqueueBack:
		{
			newQueue->Enqueue_Back(rand() % 100);

			// Display
			newQueue->Display();

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::DequeueFront:
		{
			newQueue->Dequeue_Front();

			// Display
			newQueue->Display();

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::DequeueBack:
		{
			newQueue->Dequeue_Back();

			// Display
			newQueue->Display();

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::PeekFront:
		{
			newQueue->Peek_Front();
			cout << std::endl;

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::PeekBack:
		{
			newQueue->Peek_Back();
			cout << std::endl;

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::IsEmpty:
		{
			// Display
			if (newQueue->IsEmpty())
			{
				cout << "Deque is Empty (Empty::true)" << endl << endl;
			}
			else
			{
				cout << "Deque Contains Nodes (Empty::false)" << endl << endl;
			}

			// Return To Main Menu
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::Exit:
		{
			system("cls");
			m_bExit = true;
			break;
		}

		default:
		{
			cout << "MENU OPTION FAILED" << endl;
			break;
		} 
		}
	}
	
	// Cleanup
	delete newQueue;
	newQueue = nullptr;

	// End
	return NULL;
}

/// <summary>
/// Prints The Main Menu Options To The Console Window.
/// </summary>
void PrintMainMenu()
{
	// Print Menu Options
	cout << "1. Enqueue_Front" << endl
		<< "2. Enqueue_Back" << endl
		<< "3. Dequeue_Front" << endl
		<< "4. Dequeue_Back" << endl
		<< "5. Peek_Front" << endl
		<< "6. Peek_Back" << endl
		<< "7. IsEmpty" << endl
		<< "8. Exit" << endl;
}

/// <summary>
/// Prints The ASSCI Art "QuickSort" To The Console Window.
/// </summary>
void PrintTitle()
{
	std::cout << R"(
-----------------------------------------
  _____   ______  ____   _    _  ______ 
 |  __ \ |  ____|/ __ \ | |  | ||  ____|
 | |  | || |__  | |  | || |  | || |__   
 | |  | ||  __| | |  | || |  | ||  __|  
 | |__| || |____| |__| || |__| || |____ 
 |_____/ |______|\___\_\ \____/ |______|

-----------------------------------------
)" << '\n';
}