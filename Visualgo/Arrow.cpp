#include "Arrow.h"

Arrow::Arrow(float x, float y, float length, float thickness, sf::Color color) {
    // Create the body of the arrow
    body.setSize(sf::Vector2f(length*0.8, thickness));
    body.setPosition(x, y);
    body.setFillColor(color);

    // Create the head of the arrow
    head.setPointCount(3);
    head.setPoint(0, sf::Vector2f(0, 0));
    head.setPoint(1, sf::Vector2f(-thickness * 2, thickness));
    head.setPoint(2, sf::Vector2f(-thickness * 2, -thickness));
    head.setFillColor(color);
    head.setPosition(x + length, y + thickness / 2);
}

void Arrow::draw(sf::RenderTarget& window) {
    window.draw(body);
    window.draw(head);
}
