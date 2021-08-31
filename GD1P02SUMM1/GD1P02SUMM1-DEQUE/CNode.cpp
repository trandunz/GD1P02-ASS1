// Local Includes
#include "CNode.h"

CNode::CNode()
{
	m_PrevNode = nullptr;
	m_NextNode = nullptr;
	m_iData = -1;
}

CNode::~CNode()
{
	m_PrevNode = nullptr;
	m_NextNode = nullptr;
	std::cout << "Destructing Node (" << m_iData << ")" << std::endl;
	m_iData = -1;
	delete m_NextNode;
	delete m_PrevNode;
}

void CNode::SetData(int iData)
{
	m_iData = iData;
}

int CNode::GetData()
{
	return (m_iData);
}

void CNode::SetNextNode(CNode* _nextNode)
{
	m_NextNode = _nextNode;
}

void CNode::SetPrevNode(CNode* _prevNode)
{
	m_PrevNode = _prevNode;
}

CNode* CNode::GetNextNode()
{
	return (m_NextNode);
}
