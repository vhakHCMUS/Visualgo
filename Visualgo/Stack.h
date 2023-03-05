#pragma once
#include "DoublyLinkedList.h"

struct Stack
{
	doublyLinkedList List;
	
	bool isEmpty();

	void push(int data);

	void pop();

	int get();
};

