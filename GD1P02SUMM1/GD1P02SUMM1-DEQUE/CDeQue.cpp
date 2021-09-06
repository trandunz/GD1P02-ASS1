// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CDeQue.cpp
// Description : The Implementation File For The CDeQue Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

// Local Includes
#include "CDeQue.h"

/// <summary>
/// Defualt Constructor For CDeQue Instances
/// </summary>
CDeQue::CDeQue()
{
    // Init
    m_bIsStack = true;
}

/// <summary>
/// Destructor For CDeQue Instances
/// </summary>
CDeQue::~CDeQue()
{
    // Empty List
    while (m_iNodeCount > 0 && m_firstNode != nullptr)
    {
        Dequeue();
    }

    std::cout << "Destructed Queue" << std::endl << std::endl;
}

/// <summary>
/// Enqueue's A Node With The Specified Data.
/// Takes In: int (Desired Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Enqueue(int _data)
{
    InsertAtTheEnd(_data);
    std::cout << "Enqueue'd (Frt::Node " << _data << ")" << std::endl;
}

/// <summary>
/// Enqueue's A Node At The Back With The Specified Data.
/// Takes In: int (Desired Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Enqueue_Back(int _data)
{
    InsertAtTheEnd(_data);
    std::cout << "Enqueue'd From Back (Frt::Node " << _data << ")" << std::endl;
}

/// <summary>
/// Enqueue's A Node At The Front With The Specified Data.
/// Takes In: int (Desired Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Enqueue_Front(int _data)
{
    InsertAtTheFront(_data);
    std::cout << "Enqueue'd From Front (Frt::Node " << _data << ")" << std::endl;
}

/// <summary>
/// Dequeues's The Node With The Specified Data.
/// Takes In: int (Desired Nodes Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Dequeue(int _data)
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        // Delete All Nodes In Front Of The Desired Node
        while (m_firstNode->GetData() != _data)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
            DeleteFromTheFront();
        }

        // Delete The Node
        std::cout << "Dequeue'd (Frt::Node " << _data << ")" << std::endl;
        DeleteFromTheFront();
        break;
    }
    }
}

/// <summary>
/// Dequeues's A Node From The Queue.
/// </summary>
void CDeQue::Dequeue()
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
        DeleteFromTheFront();
        break;
    }
    }
}

/// <summary>
/// Dequeues's The Node With The Specified Data From The Queue.
/// Takes In: int (Desired Nodes Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Dequeue_Back(int _data)
{
    
}

/// <summary>
/// Dequeues's A Node From The Back Of The Queue.
/// </summary>
void CDeQue::Dequeue_Back()
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        CNode* CTemp = m_firstNode;

        // Increment Temp
        while (CTemp->GetNextNode() != nullptr)
        {
            CTemp = CTemp->GetNextNode();
        }

        // Delete Node
        std::cout << "Dequeue'd From Back (Frt::Node " << CTemp->GetData() << ")" << std::endl;
        DeleteFromTheEnd();

        // Cleanup
        CTemp = nullptr;

        break;
    }
    }
}

/// <summary>
/// Dequeues's The Node With The Specified Data From The Queue.
/// Takes In: int (Desired Nodes Data).
/// </summary>
/// <param name="_data"></param>
void CDeQue::Dequeue_Front(int _data)
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        // Delete All Nodes In Front Of The Desired Node
        while (m_firstNode->GetData() != _data)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
            DeleteFromTheFront();

        }

        // Delete The Node
        std::cout << "Dequeue'd From Front (Frt::Node " << _data << ")" << std::endl;
        DeleteFromTheFront();
        break;
    }
    }
}

/// <summary>
/// Dequeues's The Front Node From The Queue.
/// </summary>
void CDeQue::Dequeue_Front()
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd From Front (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
        DeleteFromTheFront();
        break;
    }
    }
}

/// <summary>
/// Peaks The DeQueue.
/// </summary>
void CDeQue::Peek()
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Peak Success (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
        break;
    }
    }
}

/// <summary>
/// Peaks The Front Of The DeQueue.
/// </summary>
void CDeQue::Peek_Front()
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
		break;
	}
	default:
	{
		std::cout << "Peak Success (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
		break;
	}
	}
}

/// <summary>
/// Peaks The Back Of The DeQueue.
/// </summary>
void CDeQue::Peek_Back()
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		std::cout << "Peak Failed (End::No Nodes Found)" << std::endl;
		break;
	}
	default:
	{
		CNode* CTemp = m_firstNode;

        // Increment Temp
		while (CTemp->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}

        // Debug
		std::cout << "Peak Success (End::Node " << CTemp->GetData() << ")" << std::endl;

        // Cleanup
		CTemp = nullptr;

		break;
	}
	}
}

/// <summary>
/// Prints The DeQueue To The Console Window.
/// </summary>
void CDeQue::Display()
{
    switch (m_iNodeCount)
    {
    case 0:
    {
        std::cout << "Display Failed (Dis::No Nodes Found)" << std::endl << std::endl;
        break;
    }
    default:
    {
        CNode* CTemp = m_firstNode;

         // Increment Temp
        for (int i = 0; i < m_iNodeCount; i++)
        {
            std::cout << CTemp->GetData() << std::endl;
            if (CTemp->GetNextNode() != nullptr)
            {
                CTemp = CTemp->GetNextNode();
            }
        }

        // Cleanup
        CTemp = nullptr;
        std::cout << "Display Successful" << std::endl << std::endl;
        break;
    }
    }
}

/// <summary>
/// Returns A Bool Corresponding To The Emptyness Of The DeQueue.
/// </summary>
/// <returns></returns>
bool CDeQue::IsEmpty()
{
    if (m_iNodeCount == 0)
    {
        return true;
    }
	return false;
}
