#include "TextBox.h"
#include "Arrow.h"
#include <iostream>
#include <thread>
#include <future>

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

sf::Time sleepTime = sf::seconds(0.3f);

void sleep_thread(sf::Time sleepTime)
{
    std::async(std::launch::async, [=] {
        sf::sleep(sleepTime);
        }).wait();
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

void add_head_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, bool fast, sf::Color bg)
{
    if (fast)
    {
        for (int i = 0; i < visual.block.size(); i++)
        {
            visual.block[i].render(window);
        }

        //step 1
        window.display();
        sleep_thread(sleepTime);

        Button* Temp = new Button(visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
            sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
        Temp->render(window);

        window.display();
        sleep_thread(sleepTime);
        //step 2

        Temp->render(window);
        drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);
        window.display();
        sleep_thread(sleepTime);

        drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);

        //step 3
        Temp->shape.setFillColor(sf::Color::Cyan);
        Temp->render(window);

        visual.block[0].shape.setFillColor(sf::Color::Green);
        visual.block[0].render(window);

        window.display();
        sleep_thread(sleepTime);
        delete Temp;
    }
    else
    {
        int step = 1;
        int maxStep = 3;
        for (int i = 0; i < visual.block.size(); i++)
        {
            visual.block[i].render(window);
        }

        Button* Temp = new Button(visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
            sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        while (step <= maxStep)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Right)
                        step++;
                    if (event.key.code == sf::Keyboard::Left)
                        step--;
                }
            }

            switch (step)
            {
            case 1:
                window.clear(bg);
                for (int i = 0; i < visual.block.size(); i++)
                {
                    visual.block[i].render(window);
                }
                Temp->render(window);
                window.display();
                sleep_thread(sleepTime);
                break;
            case 2:
                window.clear(bg);
                for (int i = 0; i < visual.block.size(); i++)
                {
                    visual.block[i].render(window);
                }
                Temp->render(window);
                drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);
                window.display();
                break;
            case 3:
                window.clear(bg);
                for (int i = 0; i < visual.block.size(); i++)
                {
                    visual.block[i].render(window);
                }
                Temp->shape.setFillColor(sf::Color::Cyan);
                Temp->render(window);
                drawArrow(window, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y + 200, visual.block[0].shape.getPosition().x, visual.block[0].shape.getPosition().y, sf::Color::Black, font);
                visual.block[0].shape.setFillColor(sf::Color::Green);
                visual.block[0].render(window);
                window.display();
                break;
            default:
                break;
            }
        }

        delete Temp;
    }

}

void add_tail_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, bool fast, sf::Color bg)
{
    if (fast)
    {
        for (int i = 0; i < visual.block.size(); i++)
        {
            // Reset colors of all buttons
            for (int j = 0; j < visual.block.size(); j++) {
                visual.block[j].shape.setFillColor(visual.block[j].idleColor);
                visual.block[j].render(window);
            }
            for (int j = 1; j < visual.block.size(); j++)
            {
                Arrow* arrow = new Arrow(visual.block[j - 1].posX + visual.block[j - 1].shape.getSize().x, visual.block[j - 1].posY + visual.block[j - 1].shape.getSize().y / 2, 50, 7, sf::Color::Black, font);
                arrow->draw2(window);
                delete arrow;
            }
            // Set hover color of current button
            visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
            visual.block[i].render(window);

            window.display();
            sleep_thread(sleepTime);
        }
        Button* Temp = new Button(visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, 60, 60, font, std::to_string(temp),
            sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
        Temp->render(window);
        window.display();
        sleep_thread(sleepTime);
        drawArrow(window, Temp->shape.getPosition().x, Temp->shape.getPosition().y, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);
        Temp->render(window);
        window.display();
        sleep_thread(sleepTime);
    }
}

void add_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, int index, bool fast, sf::Color bg)
{
    if (fast)
    {
        Button* Temp = new Button(visual.block[index].shape.getPosition().x, visual.block[index].shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
            sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
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
                sleep_thread(sleepTime);
            }
            window.display();
            sleep_thread(sleepTime);
        }
        delete Temp;
    }
}

void update_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, int index, bool fast, sf::Color bg)
{
    if (fast)
    {
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
            sleep_thread(sleepTime);
            if (i == index) sleep_thread(sleepTime);
        }
    }
}


void delete_index_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int index, bool fast, sf::Color bg)
{
    if (fast)
    {
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
            sleep_thread(sleepTime);
        }

        for (int j = 0; j < visual.block.size(); j++) {
            if (j == index) continue;
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }
        Arrow* arrow = new Arrow(visual.block[index - 1].posX + visual.block[index - 1].shape.getSize().x, visual.block[index - 1].posY + visual.block[index - 1].shape.getSize().y / 2, 150, 10, sf::Color::Black, font);
        arrow->draw2(window);
        delete arrow;
        window.display();
        sleep_thread(sleepTime);
    }
}

void add_tail_queue(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp, bool fast, sf::Color bg)
{
    if (fast)
    {
        for (int i = 0; i < visual.block.size(); i++)
        {
            visual.block[i].render(window);
        }

        window.display();
        sleep_thread(sleepTime);

        drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);

        window.display();
        sleep_thread(sleepTime);

        Button* Temp = new Button(visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, 80, 80, font, std::to_string(temp),
            sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        Temp->render(window);
        drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);
        window.display();
        sleep_thread(sleepTime);

        drawArrow(window, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y + 200, visual.block.back().shape.getPosition().x, visual.block.back().shape.getPosition().y, sf::Color::Black, font);

        Temp->shape.setFillColor(sf::Color::Cyan);
        Temp->render(window);

        visual.block.back().shape.setFillColor(sf::Color::Green);
        visual.block.back().render(window);

        window.display();
        sleep_thread(sleepTime);
    }
}

void TextBox::transfer(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    Node* cur = List.pTail;
    int temp = cur->data;
    if (list.pHead != nullptr) add_head_step(visual, list, font, window, temp, fast, bg);
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

void TextBox::transfer_tail(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow &window, bool fast, sf::Color bg)
{
    Node* cur = List.pHead;
    int temp = cur->data;
    if (list.pHead != nullptr) add_tail_step(visual, list, font, window, temp, fast, bg);
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

void TextBox::transfer_tail_queue(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
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



void TextBox::transfer_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    add_index_step(visual, list, font, window, value, index, fast, bg);
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

void TextBox::transfer_del_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    Node* cur = List.pHead;
    int index = cur->data;

    if (list.pHead != nullptr && index != 0) delete_index_step(visual, list, font, window, index, fast, bg);
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

void TextBox::transfer_update(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    Node* cur = List.pHead;
    int index = cur->data;
    cur = cur->Next;
    int value = cur->data;
    update_index_step(visual, list, font, window, value, index, fast, bg);
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

void TextBox::transfer_search(int &search_data, Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
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

        // Create a thread to handle the sleep function
        std::thread sleepThread(sleep_thread, sleepTime);

        // Continue executing the loop
        // ...

        // Wait for the sleep thread to finish
        sleepThread.join();
    }
}

void TextBox::handleEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int type, sf::RenderWindow& window, bool fast, sf::Color bg) {
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
            if (type == 0) transfer(visual, list, font, window, fast, bg);
            if (type == 1) transfer_tail(visual, list, font, window, fast, bg);
            if (type == 2) transfer_index(visual, list, font, window, fast, bg);
            if (type == 3) transfer_del_index(visual, list, font, window, fast, bg);
            if (type == 4) transfer_update(visual, list, font, window, fast, bg);
        }
    }
}


void TextBox::handleQueueEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, sf::RenderWindow& window, bool fast, sf::Color bg) {
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
            add_tail_queue(visual, list, font, window, list.pHead->data, fast, bg);
            transfer_tail_queue(visual, list, font, window, fast, bg);
        }
    }
}
void TextBox::handleSearchEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int &search_data, sf::RenderWindow& window, bool fast, sf::Color bg) {
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
            transfer_search(search_data, visual, list, font, window, fast, bg);
        }
    }
}

void TextBox::transferArray(Buttons& visual,  int array[], int array_size, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    Node* cur = List.pHead;
    
    for (int i = 0; i < array_size; i++) array[i] = -1e3;
    int i = 0;

    while (cur != nullptr)
    {
        array[i] = cur->data;
        i++;
        cur = cur->Next;
    }

    while (visual.block.size()) visual.pop_tail();

    for (int i = 0 ; i < array_size ; i++)
        visual.add(array[i], font);

    std::cout << "transfer--------------------------------------\n";
}

void TextBox::transferIndexArray(Buttons& visual, int array[], int array_size, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    if (fast)
    {
        Node* cur = List.pHead;

        int index = cur->data;
        cur = cur->Next;

        for (int j = 0; j < visual.block.size(); j++) {
            visual.block[j].shape.setFillColor(visual.block[j].idleColor);
            visual.block[j].render(window);
        }

        visual.block[index].shape.setFillColor(visual.block[index].hoverColor);
        visual.block[index].render(window);

        window.display();
        sleep_thread(sleepTime);

        array[index] = cur->data;

        while (visual.block.size()) visual.pop_tail();

        for (int i = 0; i < array_size; i++)
            visual.add(array[i], font);

        std::cout << "transfer--------------------------------------\n";
    }
}
void TextBox::handleArrayEvent(sf::Event& event, sf::Font& font, Buttons& visual, int array[], int array_size, sf::RenderWindow& window, int type, bool fast, sf::Color bg) {
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
            if (type == 0) transferArray(visual, array, array_size, font, window, fast, bg);
            if (type == 1) transferIndexArray(visual, array, array_size, font, window, fast, bg);
        }
    }
}

void TextBox::transfer_search_array(int& search_data, Buttons& visual, int array[], int array_size, sf::Font& font, sf::RenderWindow& window, bool fast, sf::Color bg)
{
    if (fast)
    {
        search_data = List.pHead->data;
        for (int i = 0; i < visual.block.size(); i++)
        {
            // Reset colors of all buttons
            for (int j = 0; j < visual.block.size(); j++) {
                if (visual.block[j].value != search_data) visual.block[j].shape.setFillColor(visual.block[j].idleColor);
                if (j < i && visual.block[j].value == search_data) visual.block[j].shape.setFillColor(visual.block[j].hoverColor);
                visual.block[j].render(window);
            }

            // Set hover color of current button
            visual.block[i].shape.setFillColor(visual.block[i].hoverColor);
            visual.block[i].render(window);

            window.display();
            sleep_thread(sleepTime);
        }
    }
}

void TextBox::handleSearchArrayEvent(sf::Event& event, sf::Font& font, Buttons& visual, int array[], int array_size, int& search_data, sf::RenderWindow& window, bool fast, sf::Color bg) {
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
            transfer_search_array(search_data, visual, array, array_size, font, window, fast, bg);
        }
    }
}