#include "MenuStack.h"

void MenuStack(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& Stack, TextBox& textField, Buttons& visual, TextBox& addField, doublyLinkedList& doublyLL, bool& init, bool& add_tail, bool& add_head, bool& add_index, bool& delete_index, bool& search, int search_data, bool& update)
{
	Button* BackButton = new Button(50, 20, 200, 40, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 40, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Head = new Button(100, 300, 200, 40, font, "Push ",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Head = new Button(100, 350, 200, 40, font, "Pop",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Random_Init = new Button(100, 500, 200, 40, font, "Random Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Reset = new Button(100, 600, 200, 40, font, "Reset",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Add_Head->update(window);
	Delete_Head->update(window);
	Random_Init->update(window);
	Reset->update(window);

	Init->render(window);
	Add_Head->render(window);
	Delete_Head->render(window);
	Random_Init->render(window);
	Reset->render(window);

	if (Init->isClicked(window))
	{
		init = !(init);
	}
	if (Add_Head->isClicked(window))
	{
		add_head = !(add_head);
	}
	if (init)
	{
		textField.draw(window);
	}
	if (add_head)
	{
		addField.draw(window);
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(900, 550);
		aboveText->setString("Input value: [value] Current Add, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}

	if (Delete_Head->isClicked(window))
	{
		doublyLL.deleteHead();
		visual.pop_head();
	}

	if (Random_Init->isClicked(window))
	{
		int number = rand() % 10 + 1;
		while (doublyLL.pHead != nullptr) doublyLL.deleteHead();
		for (int i = 0; i < number; i++)
		{
			doublyLL.addTail(create(rand() % 100));
		}
		while (visual.block.size()) visual.pop_tail();
		Node* cur = doublyLL.pHead;
		while (cur != nullptr)
		{
			visual.add(cur->data, font);
			cur = cur->Next;
		}
	}

	if (Reset->isClicked(window))
	{
		while (doublyLL.pHead != nullptr) doublyLL.deleteHead();
		while (visual.block.size()) visual.pop_tail();
	}

	visual.render(window, search, search_data, font);

	if (BackButton->isClicked(window))
	{
		while (visual.block.size()) visual.block.pop_back();
		while (doublyLL.pHead != nullptr)
		{
			Node* cur = doublyLL.pHead;
			doublyLL.pHead = doublyLL.pHead->Next;
			delete cur;
		}
		add_tail = add_head = init = 0;
		Stack = 0;
		MenuCur = 1;
	}

	delete BackButton, Init, Add_Head, Delete_Head, Random_Init;
}