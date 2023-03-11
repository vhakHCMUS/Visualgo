#pragma once
#include "Button.h"
#include <vector>

struct Buttons
{
	std::vector<Button> block;

	void add(int a, sf::Font& font);

	void render(sf::RenderTarget& target);
};

