#include "MenuQueue.h"
#include "Arrow.h"
void MenuQueue(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& LinkedList, TextBox& textField, Buttons& visual, TextBox& addField, doublyLinkedList& doublyLL, bool& init, bool& add_tail, sf::Color bg)
{
	Button* BackButton = new Button(50, 20, 200, 40, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 40, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


	Button* Add_Tail = new Button(100, 200, 200, 40, font, "Add Tail",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Head = new Button(100, 350, 200, 40, font, "Delete Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Random_Init = new Button(100, 500, 200, 40, font, "Random Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Reset = new Button(100, 600, 200, 40, font, "Reset",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Add_Tail->update(window);;
	Delete_Head->update(window);
	Random_Init->update(window);
	Reset->update(window);

	Init->render(window);
	Add_Tail->render(window);
	Delete_Head->render(window);
	Random_Init->render(window);
	Reset->render(window);


	if (Init->isClicked(window))
	{
		init = !(init);
	}
	if (Add_Tail->isClicked(window))
	{
		add_tail = !(add_tail);
	}
	if (init)
	{
		textField.draw(window);
	}
	if (add_tail)
	{
		addField.draw(window);
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

	if (add_tail)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(900, 550);
		aboveText->setString("Input value: [value] Current Add tail, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}


	if (Delete_Head->isClicked(window))
	{
		sf::Time sleepTime = sf::seconds(0.3f);
		if (visual.block.size() > 1)
		{
			for (int j = 0; j < visual.block.size(); j++) {
				visual.block[j].shape.setFillColor(visual.block[j].idleColor);
				visual.block[j].render(window);
			}
			// Set hover color of current button
			visual.block[1].shape.setFillColor(sf::Color::Cyan);
			visual.block[1].render(window);
			window.display();
			sf::sleep(sleepTime);
		}
		doublyLL.deleteHead();
		visual.pop_head();
	}

	bool search = 0;
	int search_data = 0;
	visual.renderQueue(window, search, search_data, font);

	if (BackButton->isClicked(window))
	{
		while (visual.block.size()) visual.block.pop_back();
		while (doublyLL.pHead != nullptr)
		{
			Node* cur = doublyLL.pHead;
			doublyLL.pHead = doublyLL.pHead->Next;
			delete cur;
		}
		add_tail = init = 0;
		LinkedList = 0;
		MenuCur = 1;
		while (visual.block.size()) visual.block.pop_back();
	}
	if (Reset->isClicked(window))
	{
		while (doublyLL.pHead != nullptr) doublyLL.deleteHead();
		while (visual.block.size()) visual.pop_tail();
	}
	delete BackButton, Init, Add_Tail, Delete_Head;
}