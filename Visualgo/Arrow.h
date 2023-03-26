#pragma once
#include <SFML/Graphics.hpp>

struct Arrow {
    sf::RectangleShape body;
    sf::ConvexShape head;
    sf::ConvexShape head2;
    sf::Text aboveText;
    sf::Text belowText;
    sf::Font font;

    Arrow(float x, float y, float length, float thickness, sf::Color color, sf::Font& font);
    void draw(sf::RenderWindow& window);
    void draw2(sf::RenderWindow& window);
    void drawUpsideDown(sf::RenderWindow& window);
    void drawRotated(sf::RenderWindow& window, float angle);
};
void drawArrow(sf::RenderWindow& window, float x, float y, float x1, float y1, sf::Color color, sf::Font& font);
