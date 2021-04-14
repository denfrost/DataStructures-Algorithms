#pragma once
#include "MyNode.h"
#include <iostream>


class MyList 
{
public:

	bool isEmpty()
	{
		return firstPtr == nullptr;
	}

	void insertAtFront(const int& value)
	{

	}

private:
	MyNode* firstPtr{ nullptr };
	MyNode* lastPtr{ nullptr };
};