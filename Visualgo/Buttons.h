#pragma once
#include "Button.h"
#include "DoublyLinkedList.h"
#include <vector>

struct Buttons
{
	doublyLinkedList List;

	std::vector<Button> block;

	void add(int a, sf::Font& font);

	void pop_tail();

	void pop_head();

	void render(sf::RenderWindow& target, bool& search, int& search_data, sf::Font& font);

	void renderArray(sf::RenderWindow& target, bool& search, int& search_data, sf::Font& font);

	void render2arrow(sf::RenderWindow& target, bool& search, int& search_data, sf::Font& font);

	void renderQueue(sf::RenderWindow& target, bool& search, int& search_data, sf::Font& font);
};

