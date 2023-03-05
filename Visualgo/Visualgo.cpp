#include  "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include <iostream>

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    while (!stack.isEmpty())
    {
        std::cout << stack.get() << " ";
        stack.pop();
    }
    return 0;
}