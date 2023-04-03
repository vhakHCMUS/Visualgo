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
#include "MenuSLL.h"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Visualgo");
    sf::Event event;
    sf::Font font;


    font.loadFromFile("arial.ttf");


    Button QuitButton(600, 800, 200, 50, font, "Quit",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button VisualSwitch(1000, 100, 200, 50, font, "Visual : Fast",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Buttons temp;
    doublyLinkedList doublyLL, stack, queue, singlyLL;
    TextBox textField(font, 600, 50, 500, 50, sf::Color::White, sf::Color::Black, 5);
    TextBox addField(font, 900, 600, 200, 50, sf::Color::White, sf::Color::Black, 5);

    bool Start = 1, MenuCur = 0, StaticArray = 0, SLinkedList = 0, DLinkedList = 0, Queue = 0, Stack = 0;
    bool Init = 0, Add_Tail = 0, Add_Head = 0, Add_Index = 0, Delete_Index = 0, Search = 0, Update = 0;

    bool entered = 0, fast = 1;

    bool darkMode = 0;
    int search_data = 0;

    int arraySize = 8;
    int array[8];
    sf::Color gray(200, 200, 200);
    sf::Color lightPink(255, 182, 193);

    sf::Color bg = lightPink;
    window.setFramerateLimit(30);
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || QuitButton.isClicked(window)) {

                window.close();
            }
            if (DLinkedList && Init) textField.handleEvent(event, font, temp, doublyLL, 1, window, fast, bg);
            if (DLinkedList && Add_Tail) addField.handleEvent(event, font, temp, doublyLL, 1, window, fast, bg);
            if (DLinkedList && Add_Head) addField.handleEvent(event, font, temp, doublyLL, 0, window, fast, bg);
            if (DLinkedList && Add_Index) addField.handleEvent(event, font, temp, doublyLL, 2, window, fast, bg);
            if (DLinkedList && Delete_Index) addField.handleEvent(event, font, temp, doublyLL, 3, window, fast, bg);
            if (DLinkedList && Search) addField.handleSearchEvent(event, font, temp, doublyLL, search_data, window, fast, bg);
            if (DLinkedList && Update) addField.handleEvent(event, font, temp, doublyLL, 4, window, fast, bg);

            if (SLinkedList && Init) textField.handleEvent(event, font, temp, singlyLL, 1, window, fast, bg);
            if (SLinkedList && Add_Tail) addField.handleEvent(event, font, temp, singlyLL, 1, window, fast, bg);
            if (SLinkedList && Add_Head) addField.handleEvent(event, font, temp, singlyLL, 0, window, fast, bg);
            if (SLinkedList && Add_Index) addField.handleEvent(event, font, temp, singlyLL, 2, window, fast, bg);
            if (SLinkedList && Delete_Index) addField.handleEvent(event, font, temp, singlyLL, 3, window, fast, bg);
            if (SLinkedList && Search) addField.handleSearchEvent(event, font, temp, singlyLL, search_data, window, fast, bg);
            if (SLinkedList && Update) addField.handleEvent(event, font, temp, singlyLL, 4, window, fast, bg);

            if (Stack && Init) textField.handleEvent(event, font, temp, stack, 1, window, fast, bg);
            if (Stack && Add_Head) addField.handleEvent(event, font, temp, stack, 0, window, fast, bg);

            if (Queue && Init) textField.handleEvent(event, font, temp, queue, 1, window, fast, bg);
            if (Queue && Add_Tail) addField.handleQueueEvent(event, font, temp, queue, window, fast, bg);
            
            if (StaticArray && Init) textField.handleArrayEvent(event, font, temp, array, arraySize, window, 0, fast, bg);
            if (StaticArray && Update) addField.handleArrayEvent(event, font, temp, array, arraySize, window, 1, fast, bg);
            if (StaticArray && Search) addField.handleSearchArrayEvent(event, font, temp, array, arraySize, search_data, window, fast, bg);
        }
        
        if (darkMode) bg = gray; else bg = lightPink;
        window.clear(bg);

        if (Start) Menu(window, font, Start, MenuCur, QuitButton, VisualSwitch, fast, bg, darkMode);

        if (MenuCur) MenuNext(window, font, Start, MenuCur,
            StaticArray, SLinkedList, DLinkedList, Stack, Queue, bg);

        if (DLinkedList) MenuDLL(window, font, MenuCur, DLinkedList, textField, temp, addField, doublyLL, Init, Add_Tail, Add_Head, Add_Index, Delete_Index, Search, search_data, Update, bg);

        if (StaticArray) MenuStaticArray(window, font, MenuCur, StaticArray, Init, Search, search_data, Update, textField, addField, arraySize, array, temp, bg);

        if (Stack) MenuStack(window, font, MenuCur, Stack, textField, temp, addField, stack, Init, Add_Tail, Add_Head, Add_Index, Delete_Index, Search, search_data, Update, bg);

        if (Queue) MenuQueue(window, font, MenuCur, Queue, textField, temp, addField, queue, Init, Add_Tail, bg);

        if (SLinkedList) MenuSLL(window, font, MenuCur, SLinkedList, textField, temp, addField, singlyLL, Init, Add_Tail, Add_Head, Add_Index, Delete_Index, Search, search_data, Update, bg);
        window.display();
    }

    return 0;
}