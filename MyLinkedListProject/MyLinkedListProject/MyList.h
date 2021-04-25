#pragma once
#include "MyNode.h"
#include <iostream>

/*
**	Future improvements:
**	overloading operator (=, ==)
**	split function, reverse function
*/ 


template<typename NODETYPE>
class MyList 
{
public:

	// default-constructor 
	MyList() {}

	// destructor
	~MyList()
	{
		// attempt to destroy the nodes only if the list is not empty
		if (!isEmpty())
		{
			MyNode<NODETYPE>* tempPtr{ nullptr };
			MyNode<NODETYPE>* currentPtr{ firstPtr };

			while (currentPtr != nullptr)
			{ 
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}
	}

	// copy-constructor
	// @param listToCopy : list to copy from
	MyList(const MyList<NODETYPE>& listToCopy)
	{
		if (!listToCopy.isEmpty())
		{
			MyNode<NODETYPE>* CurrentPtr{ listToCopy.firstPtr };
			MyNode<NODETYPE>* newPtr{ nullptr };

			while (CurrentPtr != nullptr)
			{
				MyNode<NODETYPE>* tempPtr{ newPtr };
				newPtr = new MyNode<NODETYPE>{ CurrentPtr->getData() };

				if (firstPtr == nullptr)
				{
					firstPtr = newPtr;
				}
				else
				{
					tempPtr->nextPtr = newPtr;
				}
				CurrentPtr = CurrentPtr->nextPtr;
			}
			lastPtr = newPtr;
		}
	} 


	// insert an element at the front of the list
	// @param value : element to be inserted
	void insertAtFront(const NODETYPE& value)
	{
		// allocate the memory for a new node initialised with value
		MyNode<NODETYPE>* newPtr = new MyNode<NODETYPE>{ value };

		// if the list is empty both the firstPtr and the lastPtr will aim at the new created node
		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			// assign the nextPtr to the firstPtr of the list
			newPtr->nextPtr = firstPtr;
			// now the firstPtr is aiming toward the new node
			firstPtr = newPtr;
		}
	}

	// insert an element at the back of the list
	// @param value : element to be inserted
	void insertAtBack(const NODETYPE& value)
	{
		// allocate the memory for a new node initialised with value
		MyNode<NODETYPE>* newPtr = new MyNode<NODETYPE>{value};

		// if the list is empty both the firstPtr and the lastPtr will aim at the new created node
		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else 
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	// remove an element from the back of the list
	void removeFromBack()
	{
		// if the list is empty the attempt to remove the element from the back fails
		if (isEmpty())
		{
			std::cout << "\n" << "The element cannot be removed because the list is empty" << std::endl;
			return;
		}
		else 
		{
			// initialise a pointer aiming toward the lastPtr
			MyNode<NODETYPE>* tempPtr{ lastPtr };

			// if the list has only one element we dethread the node, leaving the list empty
			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}

			else 
			{
				// iterate through the nodes to find the second-last node
				MyNode<NODETYPE>* currentPtr{ firstPtr };

				while (currentPtr->nextPtr != lastPtr)
				{
					currentPtr = currentPtr->nextPtr;
				}

				// once the second-last node was found it, the connection is "cut"
				currentPtr->nextPtr = nullptr;
				// now the lastPtr is aiming toward the second-last node
				lastPtr = currentPtr;
			}
			// delete will call the destructor and then de-allocate the memory of the last node
			delete tempPtr;
		}
	}

	// remove an element from the front of the list
	void removeFromFront()
	{
		// if the list is empty the attempt to remove the element from the front fails
		if (isEmpty())
		{
			std::cout << "\n" << "The element cannot be removed because the list is empty" << std::endl;
			return;
		}
		else
		{
			// initialise a pointer aiming toward the firstPtr
			MyNode<NODETYPE>* tempPtr{ firstPtr };

			// if the list has only one element we dethread the node, leaving the list empty
			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}
			else
			{
				// now the firstPtr is aiming toward the second node
				firstPtr = firstPtr->nextPtr;
			}
			// delete will call the destructor and then de-allocate the memory of the first node
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
			std::cout << "\n" << "The list is empty" << std::endl;
			return;
		}

		MyNode<NODETYPE>* currentPtr{ firstPtr };

		while (currentPtr != nullptr)
		{
			if (currentPtr->nextPtr == nullptr)
			{
				std::cout << "[" << currentPtr->getData() << "]";
			}
			else
			{
				std::cout << "[" << currentPtr->getData() << "]->";
			}
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n";
	}

	// get the firstPtr
	const MyNode<NODETYPE>* getFirstPtr() const
	{
		return firstPtr;
	}

	// get the lastPtr
	const MyNode<NODETYPE>* getLastPtr() const
	{
		return lastPtr;
	}

private:
	// ptr to the first element on the list
	MyNode<NODETYPE>* firstPtr{ nullptr };

	// ptr to the last element on the list
	MyNode<NODETYPE>* lastPtr{ nullptr };
};