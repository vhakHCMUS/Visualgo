#include "Menu.h"

void Menu(sf::RenderWindow& window, sf::Font& font, bool &Start, bool &Menu, Button &QuitButton)
{
    if (Start)
    {
        Button* StartButton = new Button(600, 300, 200, 50, font, "Start",
            sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        StartButton->update(window);
        StartButton->render(window);

        if (StartButton->isClicked(window))
        {
            Start = 0;
            Menu = 1;
        }
        QuitButton.update(window);
        QuitButton.render(window);

        delete StartButton;
    }
}

void MenuNext(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& MenuCur,
    bool& StaticArray, bool& LinkedList, bool& Stack, bool& Queue)
{

    Button *StaticArrayButton = new Button(100, 100, 200, 50, font, "StaticArray",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *LinkedListButton = new Button(100, 200, 200, 50, font, "LinkedList",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *QueueButton = new Button(100, 300, 200, 50, font, "Queue",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *StackButton = new Button(100, 400, 200, 50, font, "Stack",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *BackButton = new Button(50, 20, 200, 50, font, "Back",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    StaticArrayButton->update(window);
    StaticArrayButton->render(window);

    if (StaticArrayButton->isClicked(window))
        StaticArray = true;

    LinkedListButton->update(window);
    LinkedListButton->render(window);

    if (LinkedListButton->isClicked(window))
        LinkedList = true;

    QueueButton->update(window);
    QueueButton->render(window);

    if (QueueButton->isClicked(window))
        Queue = true;

    StackButton->update(window);
    StackButton->render(window);

    if (StackButton->isClicked(window))
        Stack = true;

    BackButton->update(window);
    BackButton->render(window);
     
    if (BackButton->isClicked(window)) MenuCur = 0, Start = 1; 

    delete StaticArrayButton, LinkedListButton, QueueButton, StackButton, BackButton;
}
