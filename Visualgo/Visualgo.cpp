#include "SFML/Graphics.hpp" 
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "Button.h"
#include "Circle.h"
#include "Arrow.h"
#include "Menu.h"
#include "Buttons.h"
#include "MenuDLL.h"
#include "MenuStaticArray.h"
#include "MenuQueue.h"
#include "MenuStack.h"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Visualgo");
    sf::Event event;
    sf::Font font;


    font.loadFromFile("arial.ttf");


    Button QuitButton(600, 800, 200, 50, font, "Quit",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Buttons temp;
    doublyLinkedList doublyLL, stack, queue;
    TextBox textField(font, 600, 400, 500, 50, sf::Color::White, sf::Color::Black, 5);
    TextBox addField(font, 700, 500, 400, 50, sf::Color::White, sf::Color::Black, 5);

    bool Start = 1, MenuCur = 0, StaticArray = 0, LinkedList = 0, Queue = 0, Stack = 0;
    bool Init = 0, Add = 0;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
            if (LinkedList && Init) textField.handleEvent(event, font, temp, doublyLL);
            if (LinkedList && Add) addField.handleEvent(event, font, temp, doublyLL);

            if (Stack && Init) textField.handleEvent(event, font, temp, stack);
            if (Stack && Add) addField.handleEvent(event, font, temp, stack);

            if (Queue && Init) textField.handleEvent(event, font, temp, queue);
            if (Queue && Add) addField.handleEvent(event, font, temp, queue);
        }

        window.clear(sf::Color::White);

        if (Start) Menu(window, font, Start, MenuCur, QuitButton);

        if (MenuCur) MenuNext(window, font, Start, MenuCur,
            StaticArray, LinkedList, Stack, Queue);

        if (LinkedList) MenuDLL(window, font, MenuCur, LinkedList, textField, temp, addField, doublyLL, Init, Add);

        if (StaticArray) MenuStaticArray(window, font, MenuCur, StaticArray);

        if (Queue) MenuQueue(window, font, MenuCur, Queue, textField, temp, addField, queue, Init, Add);

        if (Stack) MenuStack(window, font, MenuCur, Stack, textField, temp, addField, stack, Init, Add);


        window.display();
    }

    return 0;
}