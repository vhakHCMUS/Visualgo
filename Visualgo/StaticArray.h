#pragma once
#include "DoublyLinkedList.h"
#include <iostream>

struct StaticArray
{
	int numValues = 0;

	int *values;

	StaticArray(int num);

	void input();

	void output();
};

