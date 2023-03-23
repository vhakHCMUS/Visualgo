#include "Buttons.h"
#include "Arrow.h"

void Buttons::add(int a, sf::Font& font)
{
	float x, y;
	if (block.size())
	{
		x = block.back().posX + block.back().shape.getSize().x + 50;
		y = block.back().posY;
	}
	else
	{
		x = 400;
		y = 200;
	}

	Button newButton(x, y, 80, 50, font, std::to_string(a),
		sf::Color::Green, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Black);
	if (block.size() == 0) newButton.shape.setFillColor(newButton.activeColor);
	newButton.value = a;
	block.push_back(newButton);
}

void Buttons::pop_tail()
{
	if (!block.size()) return;
	block.pop_back();
}

void Buttons::pop_head()
{
	if (!block.size()) return;

	for (int i = 0; i < block.size() - 1; i++) block[i] = block[i + 1];
	block.pop_back();
	block[0].shape.setFillColor(block[0].activeColor);
}
void Buttons::render2arrow(sf::RenderTarget& target, bool& search, int& search_data)
{
	for (auto& button : block) {
		if (button.value == search_data && search) button.shape.setFillColor(button.hoverColor);
		else button.shape.setFillColor(button.idleColor);
	}
	if (block.size()) block[0].shape.setFillColor(block[0].activeColor);
	for (auto& button : block) {
		button.render(target);
	}
	for (int i = 1; i < block.size(); i++)
	{
		Arrow* arrow = new Arrow(block[i - 1].posX + block[i - 1].shape.getSize().x, block[i - 1].posY + block[i - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black);
		arrow->draw2(target);
		delete arrow;
	}
}
void Buttons::render(sf::RenderTarget& target)
{
	for (auto& button : block) {
		button.render(target);
	}
	for (int i = 1; i < block.size(); i++)
	{
		Arrow* arrow = new Arrow(block[i - 1].posX + block[i - 1].shape.getSize().x, block[i - 1].posY + block[i - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black);
		arrow->draw(target);
		delete arrow;
	}
}