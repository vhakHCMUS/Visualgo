#include "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "Button.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris");

    sf::Event event;
    sf::Font font;
    font.loadFromFile("arial.ttf");

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        window.clear(sf::Color::White);

        Button button(50, 50, 100, 50, font, "Button", sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Black);
        button.update(window);
        button.render(window);

        window.display();
    }

    return 0;
}