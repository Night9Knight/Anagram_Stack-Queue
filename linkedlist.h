// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
//*********************************************
// The ListNode class creates a type used to *
// store a node of the linked list. *
//*********************************************
template <class T>
class ListNode
{
public:
 T value; // Node value
 ListNode<T> *next; // Pointer to the next node
 // Constructor
 ListNode (T nodeValue)
 { value = nodeValue;
 next = nullptr;}
 ListNode(){next=nullptr;}
};
//*********************************************
// LinkedList class *
//*********************************************
template <class T>
class LinkedList
{
private:
 ListNode<T> *head; // List head pointer
 int count;

public:
 // Constructor
 LinkedList()
 { head = nullptr;count=0; }

 // Destructor
 ~LinkedList();
 int c(){ return count;}
 // Linked list operations
 void appendNode(T); //to add node
 void insertNode(T); //to insert node
 void deleteNode(T); //to delete node
 void displayList() const; //to display all nodes
 bool searchNode(T);//search
 string anagramList(int);	//To insert anagram into the list
};

//search
template <class T>
bool LinkedList<T>::searchNode(T searchValue)
{
 ListNode<T> *nodePtr; // To traverse the list
 ListNode<T> *previousNode; // To point to the previous node
 bool found = false;
 // If the list is empty, do nothing.
 	if (!head)
 	cout <<"List is Empty\n";

	//Determine if the first node is the one.
	if(head->value.getWord()==searchValue.getWord())
	{
//		cout<<"\nFound in the first node.\n";
//		head->value.displayPerson();
        found=true;
		//system("pause");
	}
	else
	{
		//initiallize node to the head of the list
		nodePtr = head;
		//skip value not equal to the num
		while (nodePtr != nullptr && nodePtr->value.getWord() != searchValue.getWord())
	 	{
		 previousNode = nodePtr;
		 nodePtr = nodePtr->next;
		}

		if(nodePtr)
		{
//			cout<<"\nFound\n";
//			nodePtr->value.displayPerson();
            found=true;
			//system("pause");
		}

		else
		{
			/*cout<<"\nNot Found.\n";
			system("pause");*/
		}
	}

    return found;
}

//**************************************************
// appendNode appends a node containing the value *
// pased into newValue, to the end of the list. *
//**************************************************
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
 ListNode<T> *newNode; // To point to a new node
 ListNode<T> *nodePtr; // To move through the list
 // Allocate a new node and store newValue there.
 newNode = new ListNode<T>(newValue);
 // If there are no nodes in the list
 // make newNode the first node.
 if (!head)
 head = newNode;
 else // Otherwise, insert newNode at end.
 {
 // Initialize nodePtr to head of list.
 nodePtr = head;
 // Find the last node in the list.
 while (nodePtr->next)
 nodePtr = nodePtr->next;
 // Insert newNode as the last node.
 nodePtr->next = newNode;
 }
 count++;
}
//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head. *
//**************************************************
template <class T>
void LinkedList<T>::displayList() const
{
 ListNode<T> *nodePtr; // To move through the list
 // Position nodePtr at the head of the list.
 nodePtr = head;
 // While nodePtr points to a node, traverse
 // the list.
 while (nodePtr)
 {
 // Display the value in this node.
 cout << nodePtr->value.getWord() << endl;
 // Move to the next node.
 nodePtr = nodePtr->next;
 }
}
//**************************************************
// The insertNode function inserts a node with *
// newValue copied to its value member. *
//**************************************************
/*template <class T>
void LinkedList<T>::insertNode(T newValue)
{
 ListNode<T> *newNode; // A new node
 ListNode<T> *nodePtr; // To traverse the list
 ListNode<T> *previousNode = nullptr; // The previous node
 // Allocate a new node and store newValue there.
 newNode = new ListNode<T>(newValue);

 // If there are no nodes in the list
 // make newNode the first node
 if (!head)
 {
 head = newNode;
 newNode->next = nullptr;
 }
 else // Otherwise, insert newNode
 {
 // Position nodePtr at the head of list.
 nodePtr = head;
 // Initialize previousNode to nullptr.
 previousNode = nullptr;
 // Skip all nodes whose value is less than newValue.
 while (nodePtr != nullptr && nodePtr->value.get < newValue)
 {
 previousNode = nodePtr;
 nodePtr = nodePtr->next;
 }
 // If the new node is to be the 1st in the list,
 // insert it before all other nodes.
 if (previousNode == nullptr)
 {
 head = newNode;
 newNode->next = nodePtr;
 }
 else // Otherwise insert after the previous node.
 {
 previousNode->next = newNode;
 newNode->next = nodePtr;
 }
 }
 count++;
}*/
//*****************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//*****************************************************
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
 ListNode<T> *nodePtr; // To traverse the list
 ListNode<T> *previousNode; // To point to the previous node
 // If the list is empty, do nothing.
 if (!head)
 cout <<"List is Empty\n";

 // Determine if the first node is the one.
 if (head->value == searchValue)
 {
 nodePtr=head;
 head=head->next;
 delete nodePtr;
 }
 else
 {
 // Initialize nodePtr to head of list
 nodePtr = head;
 // Skip all nodes whose value member is
 // not equal to num.
 while (nodePtr != nullptr && nodePtr->value != searchValue)
 {
 previousNode = nodePtr;
 nodePtr = nodePtr->next;
 }
 // If nodePtr is not at the end of the list,
 // link the previous node to the node after
 // nodePtr, then delete nodePtr.
 if (nodePtr)
 {
 previousNode->next = nodePtr->next;
 delete nodePtr;
 }
 }
 count--;
}
//**************************************************
// Destructor *
// This function deletes every node in the list. *
//**************************************************
template <class T>
LinkedList<T>::~LinkedList()
{
 ListNode<T> *nodePtr; // To traverse the list
 ListNode<T> *nextNode; // To point to the next node
 // Position nodePtr at the head of the list.
 nodePtr = head;
 // While nodePtr is not at the end of the list...
 while (nodePtr != nullptr)
 {
 // Save a pointer to the next node.
 nextNode = nodePtr->next;
 // Delete the current node.
 delete nodePtr;
 // Position nodePtr at the next node.
 nodePtr = nextNode;
 }
 count=0;
}

template <class T>
string LinkedList<T>::anagramList(int num)
{
 ListNode<T> *nodePtr; // To traverse the list
 ListNode<T> *nextNode; // To point to the next node
 // Position nodePtr at the head of the list.
 nodePtr = head;
 // While nodePtr is not at the end of the list...
for(int i=0; i<num; i++)
 {
 	nodePtr = nodePtr->next;
 }
 return nodePtr->value.getWord() ;
}

#endif
