// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CSingleLinkList.h
// Description : The Header File For The CSingleLinkList Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//

#pragma once
#ifndef _SINGLE_LINKEDLIST_H__
#define _SINGLE_LINKEDLIST_H__

// Local Includes
#include "CNode.h"

class CSingleLinkList
{
public:
	CSingleLinkList();
	virtual ~CSingleLinkList();

	void InsertAtTheFront(int _data);
	void InsertInTheMiddle(int _data);
	void InsertAtTheEnd(int _data);

	void DeleteFromTheFront();
	void DeleteFromTheMiddle(int _data);
	void DeleteFromTheEnd();

	void Delete(int _data);

	bool Search(int _data);

	virtual void Display();

protected:
	bool m_bIsStack;

	CNode* m_firstNode;

	int m_iNodeCount;
};

#endif