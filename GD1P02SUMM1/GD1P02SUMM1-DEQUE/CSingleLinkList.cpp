// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CSingleLinkList.cpp
// Description : The Implementation File For The CSingleLinkList Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma warning( disable : 26812) // "Prefer Enum Class" :P

// Local Includes
#include "CSingleLinkList.h"

/// <summary>
/// Defualt Constructor For CSingleLinkList Instances
/// </summary>
CSingleLinkList::CSingleLinkList()
{
	// Init
	m_bIsStack = false;
	m_iNodeCount = 0;
	m_firstNode = nullptr;

	// RNG Seeding
	srand(time(NULL));
}


/// <summary>
/// Destructor For CSingleLinkList Instances
/// </summary>
CSingleLinkList::~CSingleLinkList()
{
	// Cleanup
	m_firstNode = nullptr;

	// If Link List Is Not A Stack/Que (They Have There Own Cleanup)
	if (!m_bIsStack)
	{
		// Delete EveryNode In The Link List
		std::cout << "Destructing LinkList" << std::endl;
		while (m_iNodeCount > 0)
		{
			DeleteFromTheEnd();
		}
	}
}


/// <summary>
/// Inserts A Node At The Front Of The List.
/// Takes In: int (Data You Want To Store)
/// </summary>
/// <param name="_data"></param>
void CSingleLinkList::InsertAtTheFront(int _data)
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		m_iNodeCount++;
		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(m_firstNode);

		CNewNode->SetData(_data);

		m_firstNode = CNewNode;

		if (!m_bIsStack)
		{
			std::cout << "Inserted At Start (Frt::No Nodes Found)" << std::endl;
		}

		break;
	}
	default:
	{
		m_iNodeCount++;
		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(m_firstNode);

		CNewNode->SetData(_data);

		m_firstNode = CNewNode;

		if (!m_bIsStack)
		{
			std::cout << "Inserted at start (Frt::Node " << CNewNode->GetData() << ")" << std::endl;
		}

		break;
	}
	}
}

/// <summary>
/// Inserts A Node At In The Middle Of The List.
/// Takes In: int (Data You Want To Store)
/// </summary>
/// <param name="_data"></param>
void CSingleLinkList::InsertInTheMiddle(int _data)
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		m_iNodeCount++;
		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(m_firstNode);

		CNewNode->SetData(_data);

		m_firstNode = CNewNode;

		if (!m_bIsStack)
		{
			std::cout << "Inserted At Start (Mid::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_iNodeCount++;
		CNode* CTemp = m_firstNode;

		// Increment Temp Counter
		for (int i = 0; i < (m_iNodeCount / 2) - 1; i++)
		{
			if (CTemp->GetNextNode() != nullptr)
			{
				CTemp = CTemp->GetNextNode();
			}
		}

		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(CTemp->GetNextNode());

		CTemp->SetNextNode(CNewNode);

		CTemp = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Inserted At End (Mid::Only One Node)" << std::endl;
		}
		
		break;
	}
	default:
		m_iNodeCount++;
		CNode* CTemp = m_firstNode;

		// Increment Temp Counter
		for (int i = 0; i < (m_iNodeCount / 2) - 1; i++)
		{
			if (CTemp->GetNextNode() != nullptr)
			{
				CTemp = CTemp->GetNextNode();
			}
		}

		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(CTemp->GetNextNode());

		CTemp->SetNextNode(CNewNode);

		CTemp = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Inserted In The Middle (Mid::Node " << CNewNode->GetData() << ")" << std::endl;
		}
		
		break;
	}
	
}

/// <summary>
/// Inserts A Node At The End Of The List.
/// Takes In: int (Data You Want To Store)
/// </summary>
/// <param name="_data"></param>
void CSingleLinkList::InsertAtTheEnd(int _data)
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		m_iNodeCount++;
		CNode* CNewNode = new CNode;

		CNewNode->SetNextNode(m_firstNode);

		CNewNode->SetData(_data);

		m_firstNode = CNewNode;

		if (!m_bIsStack)
		{
			std::cout << "Inserted At Start (End::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	default:
		m_iNodeCount++;
		CNode* CNewNode = new CNode;

		CNewNode->SetData(_data);

		CNode* CTemp = m_firstNode;

		while (CTemp->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}

		CTemp->SetNextNode(CNewNode);

		CTemp = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Inserted At End (End::Node " << CNewNode->GetData() << ")" << std::endl;
		}
		
		break;
	}
}

/// <summary>
/// Deletes A Node At The Front Of The List.
/// </summary>
void CSingleLinkList::DeleteFromTheFront()
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		if (!m_bIsStack)
		{
			std::cout << "(Frt::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_firstNode->SetNextNode(nullptr);

		// Cleanup
		delete m_firstNode;
		m_firstNode = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Deleted First Node (Frt::Only One Node)" << std::endl;
		}
		
		m_iNodeCount--;

		break;
	}
	default:
		CNode* CTemp = m_firstNode;
		CNode* CSuperTemp = m_firstNode;

		CTemp = CTemp->GetNextNode();

		m_firstNode = CTemp;

		CSuperTemp->SetNextNode(nullptr);

		if (!m_bIsStack)
		{
			std::cout << "Deleted First Node (Frt::Node " << CSuperTemp->GetData() << ")" << std::endl;
		}
		
		// Cleanup
		delete CSuperTemp;
		CSuperTemp = nullptr;
		CTemp = nullptr;

		m_iNodeCount--;

		break;
	}
	
}

/// <summary>
/// Deletes A Node From The Middle Of The List.
/// Takes In: int (Data Of The Object You Want To Delete)
/// </summary>
void CSingleLinkList::DeleteFromTheMiddle(int _data)
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		if (!m_bIsStack)
		{
			std::cout << "(Mid::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_firstNode->SetNextNode(nullptr);

		// Cleanup
		delete m_firstNode;
		m_firstNode = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Deleted Node (" << _data << ") (Del::Only One Node)" << std::endl;
		}

		m_iNodeCount--;

		break;
	}
	case 2:
	{
		CNode* CTemp = m_firstNode;

		// Increment Temp
		while (CTemp->GetNextNode()->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}

		CNode* CBeforeDelete = CTemp;

		CTemp = CBeforeDelete->GetNextNode();

		// DELETE
		delete CTemp;

		CBeforeDelete->SetNextNode(nullptr);

		// Cleanup
		CBeforeDelete = nullptr;
		CTemp = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Deleted End Node (Mid::Only Two Nodes)" << std::endl;
		}
		
		m_iNodeCount--;

		break;
	}
	default:
		
		m_firstNode->SetNextNode(m_firstNode->GetNextNode()->GetNextNode());

		CNode* CTemp = m_firstNode;

		// Increment Temp
		for (int i = 0; i < (m_iNodeCount / 2) - 1; i++)
		{
			if (CTemp->GetNextNode() != nullptr)
			{
				CTemp = CTemp->GetNextNode();
			}
		}

		if (!m_bIsStack)
		{
			std::cout << "Deleted Middle Node (Mid::Node " << CTemp->GetData() << ")" << std::endl;
		}
		
		// Cleanup
		CTemp->SetNextNode(nullptr);
		delete CTemp;
		CTemp = nullptr;

		m_iNodeCount--;

		break;
	}
}

/// <summary>
/// Deletes A Node From The End Of The List.
/// </summary>
void CSingleLinkList::DeleteFromTheEnd()
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		if (!m_bIsStack)
		{
			std::cout << "(End::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_firstNode->SetNextNode(nullptr);

		// Cleanup
		delete m_firstNode;
		m_firstNode = nullptr;

		if (!m_bIsStack)
		{
			std::cout << "Deleted First Node (End::Only One Node)" << std::endl;
		}
		
		m_iNodeCount--;

		break;
	}
	default:
		CNode* CTemp = m_firstNode;

		// Increment Temp
		while (CTemp->GetNextNode()->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}

		CNode* CBeforeDelete = CTemp;

		CTemp = CBeforeDelete->GetNextNode();

		if (!m_bIsStack)
		{
			std::cout << "Deleted End Node (End::Node " << CTemp->GetData() << ")" << std::endl;
		}
		
		// DELETE
		delete CTemp;

		// Cleanup
		CBeforeDelete->SetNextNode(nullptr);
		CBeforeDelete = nullptr;
		CTemp = nullptr;
		
		m_iNodeCount--;

		break;
	}
	
}

/// <summary>
/// Deletes The Node From The List With The Specified Data.
/// Takes In: int (Data Of The Object You Want To Delete)
/// </summary>
void CSingleLinkList::Delete(int _data)
{
	if (Search(_data))
	{
		CNode* CTemp = m_firstNode;

		switch (m_iNodeCount)
		{
		case 1:
		{
			m_firstNode->SetNextNode(nullptr);

			// Cleanup
			delete m_firstNode;
			m_firstNode = nullptr;

			if (!m_bIsStack)
			{
				std::cout << "Deleted Node (" << _data << ") (Del::Only One Node)" << std::endl;
			}
			
			m_iNodeCount--;
			break;
		}
		default:
		{
			if (CTemp->GetData() == _data)
			{
				m_firstNode = CTemp->GetNextNode();

				// Cleanup
				CTemp->SetNextNode(nullptr);
				delete CTemp;
				CTemp = nullptr;

				if (!m_bIsStack)
				{
					std::cout << "Deleted Node (" << _data << ")" << std::endl;
				}
				
				m_iNodeCount--;
			}
			else
			{
				// Increment Temp
				while (CTemp->GetNextNode()->GetData() != _data && CTemp->GetNextNode() != nullptr)
				{
					CTemp = CTemp->GetNextNode();
				}

				CNode* CBeforeDelete = CTemp;

				CTemp = CTemp->GetNextNode()->GetNextNode();

				// Cleanup
				CBeforeDelete->GetNextNode()->SetNextNode(nullptr);
				delete CBeforeDelete->GetNextNode();

				CBeforeDelete->SetNextNode(CTemp);

				// Cleanup
				CBeforeDelete = nullptr;
				CTemp = nullptr;

				if (!m_bIsStack)
				{
					std::cout << "Deleted Node (" << _data << ")" << std::endl;
				}
				
				m_iNodeCount--;
			}
			break;
		}
		}
	}
}

/// <summary>
/// Searches Through The List And Returns Corresponding Bool If Specified Node Is Found
/// </summary>
/// <param name="_data"></param>
/// <returns></returns>
bool CSingleLinkList::Search(int _data)
{
	switch (m_iNodeCount)
	{
	case 0:
	{
		if (!m_bIsStack)
		{
			std::cout << "Search Failed (Sch::No Nodes Found)" << std::endl;
		}
		
		return (false);
		break;
	}
	default:
	{
		CNode* CTemp = m_firstNode;

		// Increment Temp
		while (CTemp->GetData() != _data && CTemp->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}

		if (CTemp->GetData() == _data)
		{
			if (!m_bIsStack)
			{
				std::cout << "Search Successful (Sch::Found Node " << _data << ")" << std::endl;
			}
			
			// Cleanup
			CTemp = nullptr;

			return(true);

		}
		else
		{
			if (!m_bIsStack)
			{
				std::cout << "Search Failed (No Node With Matching Data (" << CTemp->GetData() << "))" << std::endl;
			}
			
			// Cleanup
			CTemp = nullptr;

			return(false);
		}
		break;
	}
	}
}

/// <summary>
/// Prints The Link List To The Console Window
/// </summary>
void CSingleLinkList::Display()
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

		// Iterate Temp
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
