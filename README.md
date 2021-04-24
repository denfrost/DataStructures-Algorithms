# DataStructures-Algorithms
A collection of custom Data Structures and Algorithms written in C++


![](Documentation/Images/Image01.png)

# Linked List

This is a basic singly linked list.
The interface was not separated from the implementation in order to allow the compiler to generate a copy of the class template in which all the occurrences of the type parameter are replaced with the specified type.

The linked list has the following functions:

#### Destructor
The destructor attempts to destroy the nodes only if the list is not empty.

It iterates through the list with a currentPtr initialised with the firstPtr of the list. 
A tempPtr is also initialised.
Every iteration the memory address hold by currentPtr is assigned to tempPtr, then the currentPtr iterates to the next pointer, and the object aimed at by the newPtr is destroyed (the destructor is called and the memory is released).
```
tempPtr = currentPtr;
currentPtr = currentPtr->nextPtr;
delete tempPtr;
```

![](Documentation/Images/LinkedList/LinkedList_Destructor.png)

#### Copy-constructor
The copy-constructor takes a const reference to the list to copy as a parameter.
The copy-constructor attempts to copy the nodes only if the list is not empty.

It iterates through the list with a currentPtr initialised with the firstPtr of the listToCopy. 
A pointer called newPtr is intialised.

```
MyNode<NODETYPE>* CurrentPtr{ listToCopy.firstPtr };
MyNode<NODETYPE>* newPtr{ nullptr };
``` 

During every iteration a pointer called tempPtr is initialised with the memory address hold by newPtr (the first iteration it will be nullPtr).

The new operator allocates the memory, call the constructor and return a pointer to the newly created object with the value of the currentPtr. This pointer is assigned to newPtr.

```
newPtr = new MyNode<NODETYPE>{ CurrentPtr->getData() }; 
```

If the list was empty the value of newPtr is assigned to firstPtr.

Otherwise the memory address hold by newPtr is assigned to the tempPtr's nextPtr.
```
tempPtr->nextPtr = newPtr;
```

When the loop is finished, newPtr (aiming at the last created node) is assigned to the lastPtr.

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
