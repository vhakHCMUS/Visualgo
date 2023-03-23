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

    while (List.pHead != nullptr) List.deleteHead();

    if (str.size() == 0) return;

    while (str[str.size() - 1] == ' ') str.erase(str.size() - 1);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            temp = temp * 10 + (str[i] - '0');
        if (str[i] == ' ')
        {
            List.addTail(create(temp));
            temp = 0;
        }
        std::cout << i << " : " << temp << " | " << str[i] << "\n";
    }
    List.addTail(create(temp));
    std::cout << "update--------------------------------------\n";
    text.setString("");
}

void TextBox::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

void TextBox::transfer_head(Buttons& visual, doublyLinkedList& list, sf::Font& font)
{
    Node* cur = List.pTail;
    while (cur != nullptr)
    {
        list.addHead(create(cur->data));
        Node* tmp = cur;
        cur = cur->Prev;
        delete tmp;
    }
    while (visual.block.size()) visual.pop_tail();
    cur = list.pHead;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        visual.add(cur->data, font);
        cur = cur->Next;
    }
    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transfer_tail(Buttons& visual, doublyLinkedList& list, sf::Font& font)
{
    Node* cur = List.pHead;
    while (cur != nullptr)
    {
        list.addTail(create(cur->data));
        cur = cur->Next;
    }
    while (visual.block.size()) visual.pop_tail();
    cur = list.pHead;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        visual.add(cur->data, font);
        cur = cur->Next;
    }
    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transfer_index(Buttons& visual, doublyLinkedList& list, sf::Font& font)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    list.insertIndexK(index, value);
    while (visual.block.size()) visual.pop_tail();
    cur = list.pHead;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        visual.add(cur->data, font);
        cur = cur->Next;
    }
    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transfer_del_index(Buttons& visual, doublyLinkedList& list, sf::Font& font)
{
    Node* cur = List.pHead;
    int index = cur->data;

    list.deleteIndexK(index);
    while (visual.block.size()) visual.pop_tail();
    cur = list.pHead;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        visual.add(cur->data, font);
        cur = cur->Next;
    }
    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transfer_update(Buttons& visual, doublyLinkedList& list, sf::Font& font)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    list.updateIndexK(index, value);
    while (visual.block.size()) visual.pop_tail();
    cur = list.pHead;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        visual.add(cur->data, font);
        cur = cur->Next;
    }
    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transfer_search(int &search_data)
{
    search_data = List.pHead->data;
}

void TextBox::handleEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int type) {
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
            std::string str = text.getString();
            update();
            if (type == 0) transfer_head(visual, list, font);
            if (type == 1) transfer_tail(visual, list, font);
            if (type == 2) transfer_index(visual, list, font);
            if (type == 3) transfer_del_index(visual, list, font);
            if (type == 4) transfer_update(visual, list, font);
        }
    }
}

void TextBox::handleSearchEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int &search_data) {
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
            std::string str = text.getString();
            update();
            transfer_search(search_data);
        }
    }
}