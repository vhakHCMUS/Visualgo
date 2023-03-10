#include "Menu.h"

void RenderMainMenu(sf::Font& font, sf::RenderWindow& window, Button& StartButton, Button& QuitButton)
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

void handleBackButton(bool& renderDS, Button& back, sf::RenderWindow& window)
{
    if (back.isClicked(window))
    {
        if (renderDS == 1) renderDS = 0;
    }
    return;
}

void controlMenu(sf::Font& font, sf::RenderWindow& window, bool& Menu, bool& DS, Button& StartButton, Button& QuitButton, Button& BackButton,
    Button& StaticArrayButton, Button& LinkedListButton, Button& QueueButton, Button& StackButton)
{
    if (!Menu && !DS) RenderMainMenu(font, window, StartButton, QuitButton);

    if (StartButton.isClicked(window)) Menu = 1;

    if (Menu && !DS) RenderDataStructureMenu(font, window, StaticArrayButton, LinkedListButton, QueueButton, StackButton, BackButton);

    if (StaticArrayButton.isClicked(window) || LinkedListButton.isClicked(window) || QueueButton.isClicked(window) || StackButton.isClicked(window))
        DS = 1;
    handleBackButton(Menu, BackButton, window);
}
