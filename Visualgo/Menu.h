#pragma once
#include "Button.h"

void Menu(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& Menu, Button &QuitButton, Button& VisualSwitch, bool& fast, sf::Color bg, bool& darkMode);

void MenuNext(sf::RenderWindow& window, sf::Font& font, bool& Start, bool& Menu, 
	bool& StaticArray, bool& SLinkedList, bool& DLinkedList, bool& Stack, bool& Queue, sf::Color bg);

