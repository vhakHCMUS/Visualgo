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
#include <iostream>

void doublyLinkedList_render(sf::Font& font, sf::RenderWindow& window, 
    sf::Event& event, Button& BackButton, TextBox& initBox, Buttons &visual)
{
    static bool initClicked = false; 

    BackButton.render(window);
    BackButton.update(window);

    Button* Init = new Button(100, 100, 200, 50, font, "Init",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Add = new Button(100, 200, 200, 50, font, "Add",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Init->update(window);
    Init->render(window);

    if (Init->isClicked(window))
    {
        initClicked = true;
    }

    if (initClicked)
    {
        initBox.draw(window);
        visual.render(window);
    }

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

        window.display();
    }
    
    return 0;
}