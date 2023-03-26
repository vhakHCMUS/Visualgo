#pragma once
#include <SFML/Graphics.hpp>

struct Button {
	float posX, posY, width, height;
	int value;
	sf::Text text;
	sf::RectangleShape shape;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	sf::Color outlineColor;

	Button(float x, float y, float width, float height, sf::Font &font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color outlineColor);

	bool isMouseOver(sf::RenderWindow& window);

	void update(sf::RenderWindow& window);

	bool isClicked(sf::RenderWindow& window);

	void render(sf::RenderWindow& target);

};

