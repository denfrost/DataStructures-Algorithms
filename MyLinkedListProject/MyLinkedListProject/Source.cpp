#include "MyList.h"
#include "MyNode.h"

int main()
{
	MyList example;

	example.insertAtFront(5);
	example.insertAtFront(15);
	example.insertAtFront(25);
	example.insertAtBack(7);

	example.print();

	example.removeFromBack();

	std::cout << "\nafter remove from the back" << std::endl;

	example.print();

	std::cout << "\nafter remove from front" << std::endl;

	example.removeFromFront();

	example.print();


}