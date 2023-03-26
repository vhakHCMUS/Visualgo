#include "Arrow.h"
#define M_PI 3.14159265358979323846

Arrow::Arrow(float x, float y, float length, float thickness, sf::Color color, sf::Font& font) {
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

    aboveText.setFont(font);
    aboveText.setString("pNext");
    aboveText.setCharacterSize(15);
    aboveText.setFillColor(sf::Color::Black);
    aboveText.setPosition(x + 10, y - 30);

    belowText.setFont(font);
    belowText.setString("pPrev");
    belowText.setCharacterSize(15);
    belowText.setFillColor(sf::Color::Black);
    belowText.setPosition(x + 10, y + 30);
}

void Arrow::draw(sf::RenderWindow& window) {
    window.draw(body);
    window.draw(head);
}

void Arrow::draw2(sf::RenderWindow& window) {
    window.draw(body);
    window.draw(head);
    window.draw(head2);

}

void Arrow::drawUpsideDown(sf::RenderWindow& window) {
    // Flip the arrow body vertically
    sf::RectangleShape flippedBody = body;
    flippedBody.setScale(1.0f, -1.0f);
    flippedBody.setPosition(body.getPosition().x, body.getPosition().y - body.getSize().y);

    // Flip the arrow head1 vertically
    sf::ConvexShape flippedHead1 = head;
    flippedHead1.setScale(1.0f, -1.0f);
    flippedHead1.setPosition(head.getPosition().x, head.getPosition().y - head.getPoint(0).y * 2);

    // Flip the arrow head2 vertically
    sf::ConvexShape flippedHead2 = head2;
    flippedHead2.setScale(1.0f, -1.0f);
    flippedHead2.setPosition(head2.getPosition().x, head2.getPosition().y - head2.getPoint(0).y * 2);

    // Draw the flipped arrow
    window.draw(flippedBody);
    window.draw(flippedHead1);
    window.draw(flippedHead2);
}

void Arrow::drawRotated(sf::RenderWindow& window, float deg) {
    // Set the rotation angle
    float angle = deg;

    // Rotate the arrow body
    sf::RectangleShape rotatedBody = body;
    rotatedBody.setRotation(angle);
    rotatedBody.setOrigin(0.0f, body.getSize().y / 2.0f);
    rotatedBody.setPosition(body.getPosition().x, body.getPosition().y);

    // Draw the rotated arrow
    window.draw(rotatedBody);
    //window.draw(rotatedHead1);
    //window.draw(rotatedHead2);
}

void drawArrow(sf::RenderWindow& window, float x, float y, float x1, float y1, sf::Color color, sf::Font& font)
{
    // Calculate arrow length and angle
    float dx = x1 - x;
    float dy = y1 - y;
    float length = std::sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx) * 180 / M_PI;

    // Create arrow
    Arrow arrow(x, y, length + 10, 10, color, font);

    // Rotate arrow
    arrow.drawRotated(window, angle);

}
