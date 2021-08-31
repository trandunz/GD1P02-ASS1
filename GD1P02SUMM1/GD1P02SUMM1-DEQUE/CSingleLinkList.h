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

	void insertAtTheFront(int _data);
	void insertInTheMiddle(int _data);
	void insertAtTheEnd(int _data);

	void deleteFromTheFront();
	void deleteFromTheMiddle(int _data);
	void deleteFromTheEnd();

	void Delete(int _data);

	bool search(int _data);

	virtual void display();

protected:
	bool m_bIsStack;

	CNode* m_firstNode;

	int m_iNodeCount;
};

#endif