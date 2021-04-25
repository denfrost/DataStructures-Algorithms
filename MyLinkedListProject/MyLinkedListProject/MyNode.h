#pragma once


// forward declaration
template <typename NODETYPE> class MyList;

template<typename NODETYPE>
class MyNode
{
	friend class MyList<NODETYPE>;

public:
	//	constructor
	explicit MyNode(const NODETYPE& info)
		: data{ info }, nextPtr{ nullptr } {}

	NODETYPE getData() const{ return data; }

private:

	// data contained by the node
	NODETYPE data;

	// ptr to the next node on the list
	MyNode<NODETYPE>* nextPtr;
};

