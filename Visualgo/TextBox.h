#pragma once
#include <SFML/Graphics.hpp>

#include "DoublyLinkedList.h"
#include "Buttons.h"

struct TextBox {
    sf::RectangleShape shape;
    sf::Text text;
    doublyLinkedList List;

    bool isSelected = false;

    TextBox(sf::Font& font, float x, float y, float width, float height, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

    void update();

    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int type, sf::RenderWindow& window);

    void handleSearchEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, int& search_data, sf::RenderWindow& window);

    void transfer(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_tail(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_tail_queue(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_del_index(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_update(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void transfer_search(int& search_data, Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window);

    void handleQueueEvent(sf::Event& event, sf::Font& font, Buttons& visual, doublyLinkedList& list, sf::RenderWindow& window);

    void transferArray(Buttons& visual, int array[], int array_size, sf::Font& font, sf::RenderWindow& window);

    void transferIndexArray(Buttons& visual, int array[], int array_size, sf::Font& font, sf::RenderWindow& window);

    void handleArrayEvent(sf::Event& event, sf::Font& font, Buttons& visual, int array[], int array_size, sf::RenderWindow& window, int type);

    void handleSearchArrayEvent(sf::Event& event, sf::Font& font, Buttons& visual, int array[], int array_size, int& search_data, sf::RenderWindow& window);

    void transfer_search_array(int& search_data, Buttons& visual, int array[], int array_size, sf::Font& font, sf::RenderWindow& window);

    
};

void add_head_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp);

void add_tail_step(Buttons& visual, doublyLinkedList& list, sf::Font& font, sf::RenderWindow& window, int temp);