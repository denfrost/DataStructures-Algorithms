#pragma once

// WHY WE DON'T SEPARATE THE INTERFACE FROM IMPLEMENTATION?





class MyNode
{
public:
	//	constructor
	explicit MyNode(int info)
		: data{ info }, nextPtr{ nullptr } {}

	int getData() const{ return data; }

private:
	int data;
	MyNode* nextPtr;
};

