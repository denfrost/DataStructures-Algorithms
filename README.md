# DataStructures-Algorithms
A collection of custom Data Structures and Algorithms written in C++


![](Documentation/Images/Image01.png)

# Linked List

This is a basic singly linked list.
The interface was not separated from the implementation in order to allow the compiler to generate a copy of the class template in which all the occurrences of the type parameter are replaced with the specified type.

The linked list has the following functions:

#### Destructor
The destructor attempts to destroy the nodes only if the list is not empty.

It iterates through the list until all the nodes have been deleted.


![](Documentation/Images/LinkedList/LinkedList_Destructor.png)

#### Copy-constructor
![](Documentation/Images/LinkedList/LinkedList_copyConstructor.png)

#### Insert At Front
![](Documentation/Images/LinkedList/LinkedList_InsertAtFront_6.png)

#### Insert At Back
![](Documentation/Images/LinkedList/LinkedList_InsertAtBack_4.png)

#### Remove From Front
![](Documentation/Images/LinkedList/LinkedList_removeFromFront.png)

#### Remove From Back
![](Documentation/Images/LinkedList/LinkedList_removeFromBack.png)

#### Is Empty?

#### Print
