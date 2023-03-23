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

	void render(sf::RenderTarget& target);

	void render2arrow(sf::RenderTarget& target, bool& search, int& search_data);
};

