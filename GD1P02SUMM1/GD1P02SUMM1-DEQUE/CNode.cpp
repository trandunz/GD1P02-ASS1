// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CNode.cpp
// Description : The Implementation File For The CNode Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

// Local Includes
#include "CNode.h"

/// <summary>
/// Defualt Constructor For CNode Instances
/// </summary>
CNode::CNode()
{
	// Init
	m_PrevNode = nullptr;
	m_NextNode = nullptr;
	m_iData = -1;
}

/// <summary>
/// Destructor For CNode Instances
/// </summary>
CNode::~CNode()
{
	// Cleanup
	m_PrevNode = nullptr;
	m_NextNode = nullptr;
	m_iData = -1;

	// Debug
	std::cout << "Destructing Node (" << m_iData << ")" << std::endl;
}

/// <summary>
/// Sets The Data Of The Node To Specified Parameter.
/// Takes In: int (Desired Value).
/// </summary>
/// <param name="iData"></param>
void CNode::SetData(int iData)
{
	m_iData = iData;
}

/// <summary>
/// Returns The Data Of The Node.
/// </summary>
/// <returns></returns>
int CNode::GetData()
{
	return (m_iData);
}

/// <summary>
/// Sets The NextNode Pointer For The Node.
/// Takes In: CNode* (Next Node)
/// </summary>
/// <param name="_nextNode"></param>
void CNode::SetNextNode(CNode* _nextNode)
{
	m_NextNode = _nextNode;
}

/// <summary>
/// Sets The PreviousNode Pointer For The Node.
/// Takes In: CNode* (Previous Node)
/// </summary>
/// <param name="_prevNode"></param>
void CNode::SetPrevNode(CNode* _prevNode)
{
	m_PrevNode = _prevNode;
}

/// <summary>
/// Returns A Pointer The This Nodes NextNode.
/// </summary>
/// <returns></returns>
CNode* CNode::GetNextNode()
{
	return (m_NextNode);
}
