#include "CDeQue.h"
#include <iostream>

CDeQue::CDeQue()
{
    m_isStack = true;
    
}

CDeQue::~CDeQue()
{
    std::cout << "Destructing Queue" << std::endl << std::endl;
    while (m_nNodeCount > 0 && m_CfirstNode != nullptr)
    {
        Dequeue();
    }
}

void CDeQue::Enqueue(int _iData)
{
    insertAtTheEnd(_iData);
    std::cout << "Enqueue'd (Frt::Node " << _iData << ")" << std::endl;
}

void CDeQue::Enqueue_Back(int _iData)
{
    insertAtTheEnd(_iData);
    std::cout << "Enqueue'd From Back (Frt::Node " << _iData << ")" << std::endl;
}

void CDeQue::Enqueue_Front(int _iData)
{
    insertAtTheFront(_iData);
    std::cout << "Enqueue'd From Front (Frt::Node " << _iData << ")" << std::endl;
}

void CDeQue::Dequeue(int _iData)
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        while (m_CfirstNode->getData() != _iData)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd (Frt::Node " << _iData << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CDeQue::Dequeue()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CDeQue::Dequeue_Back(int _iData)
{
    
}

void CDeQue::Dequeue_Back()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd From Back (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheEnd();
        break;
    }
    }
}

void CDeQue::Dequeue_Front(int _iData)
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        while (m_CfirstNode->getData() != _iData)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd From Front (Frt::Node " << _iData << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CDeQue::Dequeue_Front()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd From Front (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CDeQue::Peek()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Peak Success (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        break;
    }
    }
}

void CDeQue::Peek_Front()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
		break;
	}
	default:
	{
		std::cout << "Peak Success (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
		break;
	}
	}
}

void CDeQue::Peek_Back()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
		break;
	}
	default:
	{
		CNode* CTemp = m_CfirstNode;

		while (CTemp->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();
		}
		std::cout << "Peak Success (Frt::Node " << CTemp->getData() << ")" << std::endl;

		CTemp = nullptr;

		break;
	}
	}
}

bool CDeQue::IsEmpty()
{
    if (m_nNodeCount == 0)
    {
        return true;
    }
	return false;
}
