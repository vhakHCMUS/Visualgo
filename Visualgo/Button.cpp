#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::Font &font, std::string text,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color outlineColor)
{
    this->posX = x;
    this->posY = y;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;
    this->outlineColor = outlineColor;

    this->shape.setOutlineColor(this->outlineColor);
    this->shape.setFillColor(this->idleColor);
    this->shape.setOutlineThickness(2.f);

    this->text.setFont(font);
    this->text.setString(text); // set the text for the button
    this->text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f)
    );
}


bool Button::isMouseOver(sf::RenderWindow& window)
{
    sf::IntRect buttonRect(this->shape.getPosition().x, this->shape.getPosition().y, this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().height);
    if (buttonRect.contains(sf::Mouse::getPosition(window)))
    {
        return true;
    }
    return false;
}

void Button::update(sf::RenderWindow& window)
{
    sf::Vector2f originalPos = this->shape.getPosition();
    float move_x = this->posX - 5;
    float move_y = this->posY - 5;
    if (this->isMouseOver(window))
    {
        this->shape.setFillColor(this->hoverColor);
        this->shape.setPosition(move_x, move_y);
    }
    else
    {
        this->shape.setFillColor(this->idleColor);
        this->shape.setPosition(this->posX, this->posY);
    }

    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f)
    );
}


bool Button::isClicked(sf::RenderWindow& window)
{
    if (this->isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Time sleepTime = sf::seconds(0.1f);
        sf::sleep(sleepTime);
        return true;
    }
    return false;
}

void Button::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
    target.draw(this->text);
}