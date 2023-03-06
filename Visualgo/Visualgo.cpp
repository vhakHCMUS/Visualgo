#include "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "Button.h"
#include "Circle.h"
#include "Arrow.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Not Tetris");

    sf::Event event;
    sf::Font font;
    font.loadFromFile("arial.ttf");

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

    }

    return 0;
}