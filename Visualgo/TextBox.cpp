#include "TextBox.h"
#include <iostream>
TextBox::TextBox(sf::Font& font, float x, float y, float width, float height, sf::Color fillColor, sf::Color outlineColor, float outlineThickness) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(fillColor);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(outlineThickness);

    text.setFont(font);
    text.setCharacterSize(height * 0.8f);
    text.setPosition(x + outlineThickness, y + height * 0.1f);
    text.setFillColor(sf::Color::Black);
}

void TextBox::update()
{
    std::string str = text.getString();
    int temp = 0;
    if (str.size() == 0) return;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            temp = temp * 10 + (str[i] - '0');
        if (str[i] == ' ')
        {
            List.addTail(create(temp));
            temp = 0;
        }
    }
    List.addTail(create(temp));
    
    text.setString("");
}

void TextBox::draw(sf::RenderWindow & window) {
    window.draw(shape);
    window.draw(text);
}

void TextBox::transfer(Buttons &visual, sf::Font &font)
{
    Node* cur = List.pHead;
    while (cur != nullptr)
    {
        visual.add(cur->data, font);
        cur = cur->Next;
    }
}

void TextBox::handleEvent(sf::Event& event, sf::Font& font, Buttons& visual) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        if (shape.getGlobalBounds().contains(mousePos)) {
            isSelected = true;
        }
        else {
            isSelected = false;
        }
    }

    if (event.type == sf::Event::TextEntered && isSelected) {
        if (event.text.unicode == '\b') {
            if (!text.getString().isEmpty()) {
                text.setString(text.getString().substring(0, text.getString().getSize() - 1));
            }
        }
        else if (event.text.unicode < 128) {
            text.setString(text.getString() + static_cast<char>(event.text.unicode));
        }
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            update();
            transfer(visual, font);
        }
    }
}

