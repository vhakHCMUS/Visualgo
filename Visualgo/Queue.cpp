#include "Queue.h"

bool Queue::isEmpty()
{
	if (List.pHead == nullptr) return true;
	return false;
}

void Queue::push(int a)
{
	List.addTail(create(a));
}

void Queue::pop()
{
	List.deleteHead();
}

int Queue::get()
{
	return (List.pHead->data);
}