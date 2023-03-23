#include "Arrow.h"

Arrow::Arrow(float x, float y, float length, float thickness, sf::Color color) {
    // Create the body of the arrow
    body.setSize(sf::Vector2f(length * 0.7, thickness));
    body.setPosition(x + 10, y);
    body.setFillColor(color);

    // Create the head of the arrow
    head.setPointCount(3);
    head.setPoint(0, sf::Vector2f(0, 0));
    head.setPoint(1, sf::Vector2f(-thickness * 2, thickness));
    head.setPoint(2, sf::Vector2f(-thickness * 2, -thickness));
    head.setFillColor(color);
    head.setPosition(x + length, y + thickness / 2);

    head2.setPointCount(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(thickness * 2, thickness));
    head2.setPoint(2, sf::Vector2f(thickness * 2, -thickness));
    head2.setFillColor(color);
    head2.setPosition(x, y + thickness / 2);
}

void Arrow::draw(sf::RenderTarget& window) {
    window.draw(body);
    window.draw(head);
}

void Arrow::draw2(sf::RenderTarget& window) {
    window.draw(body);
    window.draw(head);
    window.draw(head2);

}