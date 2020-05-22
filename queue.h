#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <class T>
class queueNode
{
	public:
	 T value; // Node value
	 queueNode<T> *next; // Pointer to the next node
	 // Constructor
	 queueNode (T nodeValue)
	 { value = nodeValue;
	 next = nullptr;}
};

template <class T>
class queue {
	private:
	 queueNode<T> *qFront;
	 queueNode<T> *qRear;
	 int count;
	public:
	 void enQueue(T);
	 void deQueue();
	 T front(); //to return front value of a Queue
	 bool IsEmpty();
	 bool IsFull();
	 void destroyQueue();
	 queue();
	 ~queue();
};

template <class T>
void queue <T>::enQueue(T newValue){
	queueNode<T> *newNode;
	newNode = new queueNode<T>(newValue);
	if (qFront==NULL){
	qFront=newNode;
	qRear=newNode;
	 }
	 else {
	 qRear->next=newNode;
	 qRear=newNode;
	 }
	count++;
}

template <class T>
void queue <T>::deQueue(){
	queueNode<T> *nodePtr;
	if (qFront==NULL){
	cout << "Queue is Empty...\n"; 
	 }
	 else {
	 nodePtr=qFront;
	 qFront=qFront->next; //eqv to nodePtr->next
	 delete nodePtr;
	 count--;
	 }
}

template <class T>
T queue <T>::front() {
	 return qFront->value;
	}
	template <class T>
	bool queue<T>::IsEmpty() {
	if (qFront==NULL)
	 return true;
	else
	 return false;
}

template <class T>
void queue <T>::destroyQueue(){
	 queueNode<T> *nodePtr;
	 while (!IsEmpty()){ //while (qFront!=Null)
	 nodePtr=qFront;
	 qFront=qFront->next;
	 delete nodePtr;
}
count=0;
}

template <class T>
queue <T>::queue(){
	qFront=NULL;
	qRear=NULL;
	count=0;
}

template <class T>
	queue <T>::~queue(){
	destroyQueue();
}
#endif
