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
    TextBox textField(font, 600, 50, 500, 50, sf::Color::White, sf::Color::Black, 5);
    TextBox addField(font, 700, 500, 400, 50, sf::Color::White, sf::Color::Black, 5);

    bool Start = 1, MenuCur = 0, StaticArray = 0, LinkedList = 0, Queue = 0, Stack = 0;
    bool Init = 0, Add_Tail = 0, Add_Head = 0, Add_Index = 0, Delete_Index = 0, Search = 0, Update = 0;
    int search_data = 0;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
            if (LinkedList && Init) textField.handleEvent(event, font, temp, doublyLL, 1);
            if (LinkedList && Add_Tail) addField.handleEvent(event, font, temp, doublyLL, 1);
            if (LinkedList && Add_Head) addField.handleEvent(event, font, temp, doublyLL, 0);
            if (LinkedList && Add_Index) addField.handleEvent(event, font, temp, doublyLL, 2);
            if (LinkedList && Delete_Index) addField.handleEvent(event, font, temp, doublyLL, 3);
            if (LinkedList && Search) addField.handleSearchEvent(event, font, temp, doublyLL, search_data);
            if (LinkedList && Update) addField.handleEvent(event, font, temp, doublyLL, 4);

            if (Stack && Init) textField.handleEvent(event, font, temp, stack, 1);
            if (Stack && Add_Head) addField.handleEvent(event, font, temp, stack, 0);

            if (Queue && Init) textField.handleEvent(event, font, temp, queue, 0);
            if (Queue && Add_Tail) addField.handleEvent(event, font, temp, queue, 1);
        }

        window.clear(sf::Color::White);

        if (Start) Menu(window, font, Start, MenuCur, QuitButton);

        if (MenuCur) MenuNext(window, font, Start, MenuCur,
            StaticArray, LinkedList, Stack, Queue);

        if (LinkedList) MenuDLL(window, font, MenuCur, LinkedList, textField, temp, addField, doublyLL, Init, Add_Tail, Add_Head, Add_Index, Delete_Index, Search, search_data, Update);

        if (StaticArray) MenuStaticArray(window, font, MenuCur, StaticArray);

        if (Queue) MenuQueue(window, font, MenuCur, Queue, textField, temp, addField, queue, Init, Add_Tail);

        if (Stack) MenuStack(window, font, MenuCur, Stack, textField, temp, addField, stack, Init, Add_Tail, Add_Head, Add_Index, Delete_Index, Search, search_data, Update);


        window.display();
    }

    return 0;
}