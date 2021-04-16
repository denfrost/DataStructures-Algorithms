#pragma once
#include "MyNode.h"
#include <iostream>

/*
**	Future improvements:
**	move constructor, memberwise assignment and copy constructor (chapter 10)
**	split function, reverse function, sort function (?), search function (?)
**	make both list and node a template
**	doubly-linked list
*/ 



class MyList 
{
public:

	// destructor
	~MyList()
	{
		// attempt to destroy the nodes only if the list is not empty
		if (!isEmpty())
		{
			MyNode* tempPtr{ nullptr };
			MyNode* currentPtr{ firstPtr };

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}
	}


	// insert an element at the front of the list
	// @param value : element to be inserted
	void insertAtFront(const int& value)
	{
		MyNode* newPtr = new MyNode{ value };

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else // list is not empty
		{
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	// insert an element at the back of the list
	// @param value : element to be inserted
	void insertAtBack(const int& value)
	{
		MyNode* newPtr = new MyNode{value};

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else // list is not empty
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	void removeFromBack()
	{
		// if the list is empty the attempt to remove the element from the back fails
		if (isEmpty())
		{
			std::cout << "\nThe element cannot be removed because the list is empty" << std::endl;
			return;
		}
		else 
		{
			MyNode* tempPtr{ lastPtr };

			// if the list has only one element we dethread the node, leaving the list empty
			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}

			else 
			{
				MyNode* currentPtr{ firstPtr };

				while (currentPtr->nextPtr != lastPtr)
				{
					currentPtr = currentPtr->nextPtr;
				}

				currentPtr->nextPtr = nullptr;
				lastPtr = currentPtr;
			}
		
			delete tempPtr;
		}
	}

	void removeFromFront()
	{
		if (isEmpty())
		{
			std::cout << "\nThe element cannot be removed because the list is empty" << std::endl;
			return;
		}
		else
		{
			MyNode* tempPtr{ firstPtr };

			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}
			else
			{
				firstPtr = firstPtr->nextPtr;
			}

			delete tempPtr;
		}

	}

	// check if the list is empty
	bool isEmpty() const
	{
		return firstPtr == nullptr;
	}

	// print the elements of the list
	void print() const
	{
		if (isEmpty())
		{
			std::cout << "\nThe list is empty" << std::endl;
			return;
		}

		MyNode* currentPtr{ firstPtr };

		while (currentPtr != nullptr)
		{
			std::cout << "[" << currentPtr->getData() << "]->\t";
			currentPtr = currentPtr->nextPtr;
		}
	}

private:
	// ptr to the first element on the list
	MyNode* firstPtr{ nullptr };

	// ptr to the last element on the list
	MyNode* lastPtr{ nullptr };
};