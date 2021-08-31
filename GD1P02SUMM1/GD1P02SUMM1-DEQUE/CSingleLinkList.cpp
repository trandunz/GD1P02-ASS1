#include "CSingleLinkList.h"

CSingleLinkList::CSingleLinkList()
{
	m_bIsStack = false;
	m_iNodeCount = 0;
	m_firstNode = nullptr;
}

CSingleLinkList::~CSingleLinkList()
{
	m_firstNode = nullptr;

	// If Link List Is Not A Stack/Que (They Have There Own Cleanup)
	if (!m_bIsStack)
	{
		// Delete EveryNode In The Link List
		std::cout << "Destructing LinkList" << std::endl;
		while (m_iNodeCount > 0)
		{
			deleteFromTheEnd();
		}
	}
}

void CSingleLinkList::insertAtTheFront(int _data)
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

void CSingleLinkList::insertInTheMiddle(int _data)
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

void CSingleLinkList::insertAtTheEnd(int _data)
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

void CSingleLinkList::deleteFromTheFront()
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
		
		delete CSuperTemp;
		CSuperTemp = nullptr;
		CTemp = nullptr;

		m_iNodeCount--;

		break;
	}
	
}

void CSingleLinkList::deleteFromTheMiddle(int _data)
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

		while (CTemp->GetNextNode()->GetNextNode() != nullptr)
		{
			CTemp = CTemp->GetNextNode();
		}
		CNode* CBeforeDelete = CTemp;
		CTemp = CBeforeDelete->GetNextNode();
		delete CTemp;

		CBeforeDelete->SetNextNode(nullptr);
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
		for (int i = 0; i < (m_iNodeCount / 2) - 1; i++)
		{
			if (CTemp->GetNextNode() != nullptr)
			{
				CTemp = CTemp->GetNextNode();
			}
		}
		CTemp->SetNextNode(nullptr);
		if (!m_bIsStack)
		{
			std::cout << "Deleted Middle Node (Mid::Node " << CTemp->GetData() << ")" << std::endl;
		}
		
		delete CTemp;
		CTemp = nullptr;

		m_iNodeCount--;

		break;
	}
}

void CSingleLinkList::deleteFromTheEnd()
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
		
		delete CTemp;

		CBeforeDelete->SetNextNode(nullptr);
		CBeforeDelete = nullptr;
		CTemp = nullptr;
		
		m_iNodeCount--;

		break;
	}
	
}

void CSingleLinkList::Delete(int _data)
{
	if (search(_data))
	{
		CNode* CTemp = m_firstNode;

		switch (m_iNodeCount)
		{
		case 1:
		{
			m_firstNode->SetNextNode(nullptr);
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
				while (CTemp->GetNextNode()->GetData() != _data && CTemp->GetNextNode() != nullptr)
				{
					CTemp = CTemp->GetNextNode();
				}
				CNode* CBeforeDelete = CTemp;

				CTemp = CTemp->GetNextNode()->GetNextNode();

				CBeforeDelete->GetNextNode()->SetNextNode(nullptr);
				delete CBeforeDelete->GetNextNode();

				CBeforeDelete->SetNextNode(CTemp);

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

bool CSingleLinkList::search(int _data)
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
			
			CTemp = nullptr;
			return(true);

		}
		else
		{
			if (!m_bIsStack)
			{
				std::cout << "Search Failed (No Node With Matching Data (" << CTemp->GetData() << "))" << std::endl;
			}
			
			CTemp = nullptr;
			return(false);
		}
		break;
	}
	}
}

void CSingleLinkList::display()
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
