// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) Media Design School
//
// File Name : CDeQue.h
// Description : The Header File For The CDeQue Class.
// Author : William Inman
// Mail : william.inman@mds.ac.nz
//


#pragma once
#ifndef _DEQUE_H__
#define _DEQUE_H__

// Local Includes
#include "CSingleLinkList.h"

class CDeQue :	protected CSingleLinkList
{
public:
	CDeQue();
	~CDeQue();

	void Enqueue(int _data);
	void Enqueue_Back(int _data);
	void Enqueue_Front(int _data);

	void Dequeue(int _data);
	void Dequeue();

	void Dequeue_Back(int _data);
	void Dequeue_Back();

	void Dequeue_Front(int _data);
	void Dequeue_Front();

	void Peek();
	void Peek_Front();
	void Peek_Back();

	void Display();

	bool IsEmpty();
};
#endif
