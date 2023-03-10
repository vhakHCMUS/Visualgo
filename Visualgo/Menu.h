#pragma once
#include "Button.h"

void RenderMainMenu(sf::Font& font, sf::RenderWindow& window, Button& StartButton, Button& QuitButton);

void RenderDataStructureMenu(sf::Font& font, sf::RenderWindow& window,
    Button& StaticArrayButton, Button& LinkedListButton, Button& QueueButton, Button& StackButton, Button& BackButton);

void handleBackButton(bool& renderDS, Button& back, sf::RenderWindow& window);

void controlMenu(sf::Font& font, sf::RenderWindow& window, bool& Menu, bool& DS, Button& StartButton, Button& QuitButton, Button& BackButton,
    Button& StaticArrayButton, Button& LinkedListButton, Button& QueueButton, Button& StackButton);

