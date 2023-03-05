#include "Stack.h"

bool Stack::isEmpty()
{
	if (List.pHead == nullptr) return true; 
	return false;
}
void Stack::push(int data)
{
	List.addTail(create(data));
}

void Stack::pop()
{
	List.deleteTail();
}

int Stack::get()
{
	return List.pTail->data;
}

