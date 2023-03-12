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
#include "Buttons.h"
#include "MenuDLL.h"
#include "MenuStaticArray.h"
#include "MenuQueue.h"
#include "MenuStack.h"
#include <iostream>


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Not Tetris");
    sf::Event event;
    sf::Font font;

    Buttons visual;

    font.loadFromFile("arial.ttf");

    
    Button QuitButton(600, 400, 200, 50, font, "Quit",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    
    bool Start = 1, MenuCur = 0, StaticArray = 0, LinkedList = 0, Queue = 0, Stack = 0;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
        }

        window.clear(sf::Color::White);

        if (Start) Menu(window, font, Start, MenuCur, QuitButton);

        if (MenuCur) MenuNext(window, font, Start, MenuCur,
            StaticArray, LinkedList, Stack, Queue);

        if (LinkedList) MenuDLL(window, font, MenuCur, LinkedList);

        if (StaticArray) MenuStaticArray(window, font, MenuCur, StaticArray);

        if (Queue) MenuQueue(window, font, MenuCur, Queue);

        if (Stack) MenuStack(window, font, MenuCur, Stack);

        
        window.display();
    }
    
    return 0;
}