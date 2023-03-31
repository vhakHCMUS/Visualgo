#include "TextBox.h"
#include "Arrow.h"
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

void add_head_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp)
{
    sf::Time sleepTime = sf::seconds(0.7f);
    window.clear(sf::Color::White);
    for (int i = 0; i < visual.block.size(); i++)
    {
        visual.block[i].render(window);
    }

    window.display();
    sf::sleep(sleepTime);

    drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);

    window.display();
    sf::sleep(sleepTime);

    Button* Temp = new Button(visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
        sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Temp->render(window);
    drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);
    window.display();
    sf::sleep(sleepTime);

    drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);

    Temp->shape.setFillColor(sf::Color::Cyan);
    Temp->render(window);

    visual.block[0].shape.setFillColor(sf::Color::Green);
    visual.block[0].render(window);

    window.display();
    sf::sleep(sleepTime);
}

void add_tail_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp)
{
    sf::Time sleepTime = sf::seconds(0.3f);
    window.clear(sf::Color::White);
    for (int i = 0; i < visual.block.size(); i++)
    {
        // Reset colors of all buttons
        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }
        for (int i = 1; i < visual.block.size(); i++)
        {
            Arrow* arrow = new Arrow(visual.block[i - 1].posX + visual.block[i - 1].shape.getSize().x, visual.block[i - 1].posY + visual.block[i - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black, font);
            arrow->draw2(window);
            delete arrow;
        }
        // Set hover color of current button
        visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
        visual.block[i].render(window);

        window.display();
        sf::sleep(sleepTime);
    }
    Button* Temp = new Button(visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, 60, 60, font, std::to_string(temp),
        sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Temp->render(window);
    window.display();
    sf::sleep(sleepTime);
    drawArrow(window, Temp->shape.getPosition().x, Temp->shape.getPosition().y, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);
    Temp->render(window);
    window.display();
    sf::sleep(sleepTime);
}


void TextBox::transfer(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    Node* cur = List.pTail;
    int temp = cur->data;
    if (list.pHead != nullptr) add_head_step(visual, list, font, window, temp);
    while (cur != nullptr)
    {
        list.addHead(create(cur->data));
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

void TextBox::transfer_tail(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow &window)
{
    Node* cur = List.pHead;
    int temp = cur->data;
    if (list.pHead != nullptr) add_tail_step(visual, list, font, window, temp);
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

void TextBox::transfer_tail_queue(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    Node* cur = List.pHead;
    int temp = cur->data;
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

void add_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, int index)
{
    sf::Time sleepTime = sf::seconds(0.5f);

    Button* Temp = new Button(visual.block[index].shape.getPosition().x, visual.block[index].shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
        sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    window.clear(sf::Color::White);
    for (int i = 0; i < index; i++)
    {
        // Reset colors of all buttons
        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }

        // Set hover color of current button
        visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
        visual.block[i].render(window);
        Temp->render(window);
        if (i == index - 1) {
            drawArrow(window, Temp->shape.getPosition().x, Temp->shape.getPosition().y, visual.block[index - 1].shape.getPosition().x, visual.block[index - 1].shape.getPosition().y, sf::Color::Black, font);
            drawArrow(window, Temp->shape.getPosition().x, Temp->shape.getPosition().y, visual.block[index].shape.getPosition().x, visual.block[index].shape.getPosition().y, sf::Color::Black, font);
            sf::sleep(sleepTime);
        }
        window.display();
        sf::sleep(sleepTime);
    }
    delete Temp;
}
void update_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, int index)
{
    sf::Time sleepTime = sf::seconds(0.3f);
    for (int i = 0; i < visual.block.size(); i++)
    {
        // Reset colors of all buttons
        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }

        // Set hover color of current button
        if (i <= index) visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
        visual.block[i].render(window);

        window.display();
        sf::sleep(sleepTime);
        if (i == index) sf::sleep(sleepTime);
    }
}
void TextBox::transfer_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    add_index_step(visual, list, font, window, value, index);
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

void delete_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int index)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    for (int i = 0; i < index; i++)
    {
        // Reset colors of all buttons
        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }

        // Set hover color of current button
        visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
        visual.block[i].render(window);

        window.display();
        sf::sleep(sleepTime);
    }

    window.clear(sf::Color::White);
    for (int j = 0; j < visual.block.size(); j++) {
        if (j == index) continue;
        visual.block[j].shape.setFillColor(visual.block[j].idleColor);
        visual.block[j].render(window);
    }
    Arrow* arrow = new Arrow(visual.block[index - 1].posX + visual.block[index - 1].shape.getSize().x, visual.block[index - 1].posY + visual.block[index - 1].shape.getSize().y / 2, 150, 10, sf::Color::Black, font);
    arrow->draw2(window);
    delete arrow;
    window.display();
    sf::sleep(sleepTime);

}
void TextBox::transfer_del_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    Node* cur = List.pHead;
    int index = cur->data;

    if (list.pHead != nullptr && index != 0) delete_index_step(visual, list, font, window, index);
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

void TextBox::transfer_update(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    update_index_step(visual, list, font, window, value, index);
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

void TextBox::transfer_search(int &search_data, Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    search_data = List.pHead->data;
    for (int i = 0; i < visual.block.size(); i++)
    {
        // Reset colors of all buttons
        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }

        // Set hover color of current button
        visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
        visual.block[i].render(window);

        window.display();
        sf::sleep(sleepTime);
    }
}

void TextBox::handleEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int type, sf::RenderWindow& window) {
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
            if (type == 0) transfer(visual, list, font, window);
            if (type == 1) transfer_tail(visual, list, font, window);
            if (type == 2) transfer_index(visual, list, font, window);
            if (type == 3) transfer_del_index(visual, list, font, window);
            if (type == 4) transfer_update(visual, list, font, window);
        }
    }
}

void add_tail_queue(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp)
{
    sf::Time sleepTime = sf::seconds(0.7f);
    window.clear(sf::Color::White);
    for (int i = 0; i < visual.block.size(); i++)
    {
        visual.block[i].render(window);
    }

    window.display();
    sf::sleep(sleepTime);

    drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);

    window.display();
    sf::sleep(sleepTime);

    Button* Temp = new Button(visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
        sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Temp->render(window);
    drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);
    window.display();
    sf::sleep(sleepTime);

    drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);

    Temp->shape.setFillColor(sf::Color::Cyan);
    Temp->render(window);

    visual.block.back().shape.setFillColor(sf::Color::Green);
    visual.block.back().render(window);

    window.display();
    sf::sleep(sleepTime);
}
void TextBox::handleQueueEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, sf::RenderWindow& window) {
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
            add_tail_queue(visual, list, font, window, list.pHead->data);
            transfer_tail_queue(visual, list, font, window);
        }
    }
}
void TextBox::handleSearchEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int &search_data, sf::RenderWindow& window) {
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
            transfer_search(search_data, visual, list, font, window);
        }
    }
}