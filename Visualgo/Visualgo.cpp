#include "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "Button.h"
#include "Circle.h"
#include "Arrow.h"
#include "TextBox.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Not Tetris");

    sf::Event event;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    TextBox textbox(font, 100, 100, 200, 30, sf::Color::White, sf::Color::Black, 5);

    while (window.isOpen()) {
        window.clear(sf::Color::White);
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
            textbox.handleEvent(event);
        }
        textbox.draw(window);
        window.display();
    }

    textbox.List.loadList();
    return 0;
}