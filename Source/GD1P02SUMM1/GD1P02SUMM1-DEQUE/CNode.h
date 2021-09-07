// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CNode.h
// Description : The Header File For The CNode Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma warning( disable : 26812) // "Prefer Enum Class" :P

#pragma once
#ifndef _NODE_H__
#define _NODE_H__

// Non-Local Includes
#include <iostream>

class CNode
{
public:
	CNode();
	~CNode();

	void SetData(int _data);
	int GetData();

	void SetNextNode(CNode* _nextNode);
	CNode* GetNextNode();

	void SetPrevNode(CNode* _prevNode);

protected:
	int m_iData;
	CNode* m_NextNode;
	CNode* m_PrevNode;
};
#endif