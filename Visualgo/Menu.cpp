#include "Menu.h"

void Menu(sf::RenderWindow& window, sf::Font& font, bool &Start, bool &Menu, Button &QuitButton, Button &VisualSwitch, bool& fast, sf::Color bg, bool& darkMode)
{
    if (Start)
    {
        Button* StartButton = new Button(600, 300, 200, 50, font, "Start",
            sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        Button* DarkMode = new Button(1000, 300, 200, 50, font, "Dark mode : On",
            sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        StartButton->update(window);
        StartButton->render(window);

        if (!darkMode) DarkMode->text.setString("Dark mode : Off");
        DarkMode->update(window);
        DarkMode->render(window);

        if (DarkMode->isClicked(window))
        {
            darkMode = !darkMode;
        }

        if (StartButton->isClicked(window))
        {
            Start = 0;
            Menu = 1;
        }
        QuitButton.update(window);
        QuitButton.render(window);

        if (fast) VisualSwitch.text.setString("Visual : Fast"); else 
            VisualSwitch.text.setString("Visual : Step by step"); 

        VisualSwitch.update(window);
        VisualSwitch.render(window);

        if (VisualSwitch.isClicked(window)) fast = !fast;

        delete StartButton, DarkMode;
    }
}

void MenuNext(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& MenuCur,
    bool& StaticArray, bool& SLinkedList, bool& DLinkedList, bool& Stack, bool& Queue, sf::Color bg)
{

    Button *StaticArrayButton = new Button(100, 100, 200, 50, font, "StaticArray",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *DLinkedListButton = new Button(100, 200, 200, 50, font, "Doubly Linked List",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *QueueButton = new Button(100, 300, 200, 50, font, "Queue",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *StackButton = new Button(100, 400, 200, 50, font, "Stack",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* SLinkedListButton = new Button(100, 500, 200, 50, font, "Singly Linked List",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button *BackButton = new Button(50, 20, 200, 50, font, "Back",
        sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    StaticArrayButton->update(window);
    StaticArrayButton->render(window);

    if (StaticArrayButton->isClicked(window))
        StaticArray = true;

    SLinkedListButton->update(window);
    SLinkedListButton->render(window);

    if (SLinkedListButton->isClicked(window))
        SLinkedList = true;

    DLinkedListButton->update(window);
    DLinkedListButton->render(window);

    if (DLinkedListButton->isClicked(window))
        DLinkedList = true;

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

    delete StaticArrayButton, DLinkedListButton, QueueButton, StackButton, BackButton;
}
