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

void RenderMainMenu(sf::Font& font, sf::RenderWindow &window, Button &StartButton, Button &QuitButton)
{
    
    StartButton.update(window);
    StartButton.render(window);

    QuitButton.update(window);
    QuitButton.render(window);
}

void RenderDataStructureMenu(sf::Font& font, sf::RenderWindow& window,
    Button& StaticArrayButton, Button& LinkedListButton, Button& QueueButton, Button& StackButton, Button& BackButton)
{
    StaticArrayButton.update(window);
    StaticArrayButton.render(window);

    LinkedListButton.update(window);
    LinkedListButton.render(window);

    QueueButton.update(window);
    QueueButton.render(window);

    StackButton.update(window);
    StackButton.render(window);

    BackButton.update(window);
    BackButton.render(window);
}

void handleBackButton(bool& renderDS, Button& back, sf::RenderWindow &window)
{
    if (back.isClicked(window))
    {
        if (renderDS == 1) renderDS = 0;
    }
    return;
}
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Not Tetris");
    sf::Event event;
    sf::Font font;
    Button StartButton(600, 300, 200, 50, font, "Start", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button QuitButton(600, 400, 200, 50, font, "Quit", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button StaticArrayButton(100, 100, 200, 50, font, "StaticArray", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button LinkedListButton(100, 200, 200, 50, font, "LinkedList", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button QueueButton(100, 300, 200, 50, font, "Queue", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button StackButton(100, 400, 200, 50, font, "Stack", 
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button BackButton(50, 30, 200, 50, font, "Back",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    font.loadFromFile("arial.ttf");
    
    bool RenderDS = false;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
        }

        window.clear(sf::Color::White);

        if (!RenderDS) RenderMainMenu(font, window, StartButton, QuitButton);
        if (StartButton.isClicked(window)) RenderDS = 1;
        if (RenderDS) RenderDataStructureMenu(font, window, StaticArrayButton, LinkedListButton, QueueButton, StackButton, BackButton);
        handleBackButton(RenderDS, BackButton, window);
        window.display();
    }

    return 0;
}