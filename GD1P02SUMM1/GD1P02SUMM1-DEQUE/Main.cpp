#pragma warning( disable : 26812)

#include <iostream>
#include <conio.h>
#include "CDeQue.h"

#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54
#define SEVEN 55
#define EIGHT 56

using namespace std;

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

STATE m_RuntimeState = STATE::MainMenu;

void PrintMainMenu();
void PrintTitle();

int m_iMenuChoice = NULL;
bool m_bExit = false;

int main()
{
	CDeQue* newQueue = new CDeQue;
	
	while (!m_bExit)
	{
		switch (m_RuntimeState)
		{
		case STATE::MainMenu:
		{
			m_iMenuChoice = NULL;
			
			while (m_iMenuChoice < ONE || m_iMenuChoice > EIGHT)
			{
				
				m_iMenuChoice = NULL;
				
				// Title
				PrintTitle();

				// Print Menu Options
				PrintMainMenu();

				m_iMenuChoice = _getch();
				system("cls");
				
			}

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

		case STATE::EnqueueFront:
		{
			newQueue->Enqueue_Front(1);

			// Display
			newQueue->display();
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::EnqueueBack:
		{
			newQueue->Enqueue_Back(2);

			// Display
			newQueue->display();
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::DequeueFront:
		{
			newQueue->Dequeue_Front();

			// Display
			newQueue->display();
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::DequeueBack:
		{
			newQueue->Dequeue_Back();

			// Display
			newQueue->display();
			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::PeekFront:
		{
			newQueue->Peek_Front();
			cout << std::endl;

			m_RuntimeState = STATE::MainMenu;

			break;
		}

		case STATE::PeekBack:
		{
			newQueue->Peek_Back();
			cout << std::endl;

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