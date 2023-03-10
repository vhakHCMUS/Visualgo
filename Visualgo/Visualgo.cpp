#include "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "Button.h"
#include "Circle.h"
#include "Arrow.h"
#include "TextBox.h"
#include "Menu.h"
#include <iostream>

void doublyLinkedList_render(sf::Font &font, sf::RenderWindow& window, Button& BackButton)
{
    BackButton.render(window);
    BackButton.update(window);

    Button* Init = new Button(100, 100, 200, 50, font, "Init",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Add = new Button(100, 200, 200, 50, font, "Add",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    
    Init->update(window);
    Init->render(window);
    
    Add->update(window);
    Add->render(window);
    
    delete Init;
    delete Add;
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

    doublyLinkedList LinkedList;
    font.loadFromFile("arial.ttf");

    TextBox initBox(font, 100, 100, 200, 50, sf::Color::White, sf::Color::Black, 5);
    
    bool Menu = false, DS = false;
    bool SA = false, DLL = false, Q = false, S = false;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
            initBox.handleEvent(event);
        }

        window.clear(sf::Color::White);

        controlMenu(font, window, Menu, DS, StartButton, QuitButton, BackButton,
            StaticArrayButton, LinkedListButton, QueueButton, StackButton);
        
        if (Menu && DS)
        {
            if (LinkedListButton.isClicked(window)) DLL = true;
            if (DLL == true) doublyLinkedList_render(font, window, BackButton);
        }

        window.display();
    }

    return 0;
}