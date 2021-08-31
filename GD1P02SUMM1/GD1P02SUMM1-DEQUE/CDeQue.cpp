// Local Includes
#include "CDeQue.h"


CDeQue::CDeQue()
{
    m_bIsStack = true;
}

CDeQue::~CDeQue()
{
    std::cout << "Destructing Queue" << std::endl << std::endl;
    while (m_iNodeCount > 0 && m_firstNode != nullptr)
    {
        Dequeue();
    }
}

void CDeQue::Enqueue(int _data)
{
    insertAtTheEnd(_data);
    std::cout << "Enqueue'd (Frt::Node " << _data << ")" << std::endl;
}

void CDeQue::Enqueue_Back(int _data)
{
    insertAtTheEnd(_data);
    std::cout << "Enqueue'd From Back (Frt::Node " << _data << ")" << std::endl;
}

void CDeQue::Enqueue_Front(int _data)
{
    insertAtTheFront(_data);
    std::cout << "Enqueue'd From Front (Frt::Node " << _data << ")" << std::endl;
}

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
        while (m_firstNode->GetData() != _data)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd (Frt::Node " << _data << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

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
        deleteFromTheFront();
        break;
    }
    }
}

void CDeQue::Dequeue_Back(int _data)
{
    
}

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

        while (CTemp->GetNextNode() != nullptr)
        {
            CTemp = CTemp->GetNextNode();
        }
        std::cout << "Dequeue'd From Back (Frt::Node " << CTemp->GetData() << ")" << std::endl;
        deleteFromTheEnd();

        CTemp = nullptr;
        break;
    }
    }
}

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
        while (m_firstNode->GetData() != _data)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_firstNode->GetData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd From Front (Frt::Node " << _data << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

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
        deleteFromTheFront();
        break;
    }
    }
}

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

void CDeQue::Peek_Back()
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
		CNode* CTemp = m_firstNode;

		while (CTemp->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}
		std::cout << "Peak Success (Frt::Node " << CTemp->GetData() << ")" << std::endl;

		CTemp = nullptr;

		break;
	}
	}
}

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
        for (int i = 0; i < m_iNodeCount; i++)
        {
            std::cout << CTemp->GetData() << std::endl;
            if (CTemp->GetNextNode() != nullptr)
            {
                CTemp = CTemp->GetNextNode();
            }
        }
        CTemp = nullptr;
        std::cout << "Display Successful" << std::endl << std::endl;
        break;
    }
    }
}

bool CDeQue::IsEmpty()
{
    if (m_iNodeCount == 0)
    {
        return true;
    }
	return false;
}
