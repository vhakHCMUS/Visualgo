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

	void render(sf::RenderTarget& target);
};

