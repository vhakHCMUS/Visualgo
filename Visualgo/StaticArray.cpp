#include "StaticArray.h"

StaticArray::StaticArray(int num)
{
	this->numValues = num;
	values = new int[num];
}

void StaticArray::input()
{
	for (int i = 0; i < numValues; i++) std::cin >>*(values + i);
}

void StaticArray::output()
{
	for (int i = 0; i < numValues; i++) std::cout <<*(values + i);
}

