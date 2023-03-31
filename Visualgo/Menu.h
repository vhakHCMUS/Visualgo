#pragma once
#include "Button.h"

void Menu(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& Menu, Button &QuitButton);

void MenuNext(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& Menu, 
	bool& StaticArray, bool& SLinkedList, bool& DLinkedList, bool& Stack, bool& Queue);

