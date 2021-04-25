#include "MyList.h"
#include "MyNode.h"
#include <string>

void testCopyConstructor(MyList<int> listExample);

int main()
{
	std::cout << "initialising MyList listObject1..." << std::endl;
	MyList<int> listObject1{};
	std::cout << "listObject1 address is " << &listObject1 << std::endl;

	// testing inserting both at front and back 
	listObject1.insertAtFront(5);
	listObject1.insertAtFront(15);
	listObject1.insertAtFront(25);
	listObject1.insertAtBack(7);

	std::cout << "\n" << "This is listObject1 after the insertingAtFront 5, 15, 25 and insertingAtBack 7" << std::endl;
	listObject1.print();

	// testing removing both at front and back 
	listObject1.removeFromBack();
	listObject1.removeFromFront();


	std::cout << "\n" << "This is listObject1 after using removeFromBack and RemoveFromFront" << std::endl;
	listObject1.print();

	// initiliase list object using copy-constructor
	std::cout << "\n\n" << "initialising listObject2 using copy constructor..." << std::endl;
	MyList<int> listObject2{ listObject1 };
	std::cout << "listObject2 address is " << &listObject2 << std::endl;
	std::cout << "\n" << "listObject2 contains these elements: " << std::endl;
	listObject2.print();

	if (listObject2.getLastPtr() != nullptr)
	{
		std::cout << "the value of listObject2.lastPtr is " << listObject2.getLastPtr()->getData() << std::endl;
	}

	// test copy-constructor using a test function with pass-by-value
	testCopyConstructor(listObject2);


	// initialise a new list holding strings
	MyList<std::string> listObject3{};

	std::cout << "\n\n\n" << "testing the linked list with string objects" << std::endl;

	// add two strings to the list
	listObject3.insertAtFront("not");
	listObject3.removeFromFront();
	listObject3.insertAtFront("are");
	listObject3.insertAtFront("data structures");
	listObject3.insertAtBack("great");

	listObject3.print();

	std::cout << "\n";
}

void testCopyConstructor(MyList<int> listExample)
{
	if (listExample.getFirstPtr() != nullptr)
	{
		std::cout << "\n";
		std::cout << "using testCopyConstructor(listObject2) function " << std::endl;
		std::cout << "The first value of the list passed by value is " << listExample.getFirstPtr()->getData();
	}
}
