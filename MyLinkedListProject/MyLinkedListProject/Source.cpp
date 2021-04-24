#include "MyList.h"
#include "MyNode.h"

void testCopyConstructor(MyList listExample);

int main()
{
	std::cout << "initialising MyList example1..." << std::endl;
	MyList example1{};
	std::cout << "example1 address is " << &example1 << std::endl;

	// testing inserting both at front and back 
	example1.insertAtFront(5);
	example1.insertAtFront(15);
	example1.insertAtFront(25);
	example1.insertAtBack(7);

	std::cout << "\n" << "This is example1 after the insertingAtFront 5, 15, 25 and insertingAtBack 7" << std::endl;
	example1.print();

	// testing removing both at front and back 
	example1.removeFromBack();
	example1.removeFromFront();


	std::cout << "\n" << "This is example1 after using removeFromBack and RemoveFromFront" << std::endl;
	example1.print();

	// initiliase list object using copy-constructor
	std::cout << "\n\n" << "initialising example2 using copy constructor..." << std::endl;
	MyList example2{ example1 };
	std::cout << "example2 address is " << &example2 << std::endl;
	std::cout << "\n" << "example2 contains these elements: " << std::endl;
	example2.print();

	if (example2.getLastPtr() != nullptr)
	{
		std::cout << "the value of example2.lastPtr is " << example2.getLastPtr()->getData() << std::endl;
	}

	// test copy-constructor using a test function with pass-by-value
	testCopyConstructor(example2);

	std::cout << "\n";
}

void testCopyConstructor(MyList listExample)
{
	if (listExample.getFirstPtr() != nullptr)
	{
		std::cout << "\n";
		std::cout << "using testCopyConstructor(example2) function " << std::endl;
		std::cout << "The first value of the list passed by value is " << listExample.getFirstPtr()->getData();
	}
}
