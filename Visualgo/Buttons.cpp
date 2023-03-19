#include "Buttons.h"

void Buttons::add(int a, sf::Font& font)
{
	float x, y;
	if (block.size())
	{
		x = block.back().posX + block.back().shape.getSize().x + 100;
		y = block.back().posY;
	}
	else
	{
		x = 400;
		y = 200;
	}
	
	Button newButton(x, y, 100, 50, font, std::to_string(a),
		sf::Color::Green, sf::Color::Yellow, sf::Color::Green, sf::Color::Black);

	block.push_back(newButton);
}

void Buttons::render(sf::RenderTarget& target)
{
	for (auto& button : block) {
		button.render(target);
	}
}
