#pragma once
#include <SFML/Graphics.hpp>

struct Arrow {
    sf::RectangleShape body;
    sf::ConvexShape head;
    sf::ConvexShape head2;

    Arrow(float x, float y, float length, float thickness, sf::Color color);
    void draw(sf::RenderTarget& window);
    void draw2(sf::RenderTarget& window);
};

