#pragma once
#include "DoublyLinkedList.h"

struct Queue {
	doublyLinkedList List;
	bool isEmpty();
	void push(int a);
	void pop();
	int get();
};
