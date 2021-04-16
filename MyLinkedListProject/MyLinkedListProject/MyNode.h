#pragma once


// forward declaration
class MyList;

class MyNode
{
	friend class MyList;

public:
	//	constructor
	explicit MyNode(int info)
		: data{ info }, nextPtr{ nullptr } {}

	int getData() const{ return data; }

private:

	// data contained by the node
	int data;

	// ptr to the next node on the list
	MyNode* nextPtr;
};

