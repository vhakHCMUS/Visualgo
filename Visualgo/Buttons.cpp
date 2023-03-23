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

	Button newButton(x, y, 50, 50, font, std::to_string(a),
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
	if (block.size() == 1)
	{
		pop_tail();
		return;
	}
	for (int i = 0; i < block.size() - 1; i++) block[i] = block[i + 1];
	block.pop_back();
	block[0].shape.setFillColor(block[0].activeColor);
}
void Buttons::render2arrow(sf::RenderTarget& target, bool& search, int& search_data, sf::Font& font)
{
	for (auto& button : block) {
		if (button.value == search_data && search) button.shape.setFillColor(button.hoverColor);
		else button.shape.setFillColor(button.idleColor);
	}
	if (block.size())
	{
		block[0].shape.setFillColor(block[0].activeColor);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(block[0].posX, block[0].posY - 50);
		aboveText->setString("pHead");
		target.draw(*aboveText);
		delete aboveText;
	}
	for (auto& button : block) {
		button.render(target);
	}

	for (int i = 1; i < block.size(); i++)
	{
		Arrow* arrow = new Arrow(block[i - 1].posX + block[i - 1].shape.getSize().x, block[i - 1].posY + block[i - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black, font);
		arrow->draw2(target);
		delete arrow;
	}
}
void Buttons::render(sf::RenderTarget& target, sf::Font& font)
{
	if (block.size())
	{
		block[0].shape.setFillColor(block[0].activeColor);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(block[0].posX, block[0].posY - 50);
		aboveText->setString("pHead");
		target.draw(*aboveText);
		delete aboveText;
	}
	for (auto& button : block) {
		button.render(target);
	}
	for (int i = 1; i < block.size(); i++)
	{
		Arrow* arrow = new Arrow(block[i - 1].posX + block[i - 1].shape.getSize().x, block[i - 1].posY + block[i - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black, font);
		arrow->draw(target);
		delete arrow;
	}
}