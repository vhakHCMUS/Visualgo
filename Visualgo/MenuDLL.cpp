#include "MenuDLL.h"

void MenuDLL(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& LinkedList, TextBox& textField, Buttons& visual, TextBox& addField, doublyLinkedList& doublyLL, bool& init, bool& add_tail, bool& add_head, bool& add_index, bool& delete_index, bool& search, int search_data, bool& update)
{
	Button* BackButton = new Button(50, 20, 200, 40, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 40, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Search = new Button(100, 150, 200, 40, font, "Search",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Tail = new Button(100, 200, 200, 40, font, "Add Tail",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Tail = new Button(100, 250, 200, 40, font, "Delete Tail",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Head = new Button(100, 300, 200, 40, font, "Add Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Head = new Button(100, 350, 200, 40, font, "Delete Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Index = new Button(100, 400, 200, 40, font, "Add Index",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Index = new Button(100, 450, 200, 40, font, "Delete Index",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Random_Init = new Button(100, 500, 200, 40, font, "Random Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Update = new Button(100, 550, 200, 40, font, "Update Index",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Reset = new Button(100, 600, 200, 40, font, "Reset",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Search->update(window);
	Add_Tail->update(window);
	Delete_Tail->update(window);
	Add_Head->update(window);
	Delete_Head->update(window);
	Add_Index->update(window);
	Delete_Index->update(window);
	Random_Init->update(window);
	Reset->update(window);
	Update->update(window);

	Init->render(window);
	Search->render(window);
	Add_Tail->render(window);
	Delete_Tail->render(window);
	Add_Head->render(window);
	Delete_Head->render(window);
	Add_Index->render(window);
	Delete_Index->render(window);
	Random_Init->render(window);
	Reset->render(window);
	Update->render(window);

	if (Init->isClicked(window))
	{
		init = !(init);
	}
	if (Add_Tail->isClicked(window))
	{
		add_tail = !(add_tail);
	}
	if (Add_Head->isClicked(window))
	{
		add_head = !(add_head);
	}
	if (Add_Index->isClicked(window))
	{
		add_index = !(add_index);
	}
	if (Delete_Index->isClicked(window))
	{
		delete_index = !(delete_index);
	}
	if (Update->isClicked(window))
	{
		update = !(update);
	}
	if (init)
	{
		textField.draw(window);
	}
	if (add_tail || add_head || add_index || delete_index || search || update)
	{
		addField.draw(window);
	}

	if (add_index)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(700, 450);
		aboveText->setString("Input value: [index] [space] [value] Current Add by Index, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}

	if (delete_index)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(700, 450);
		aboveText->setString("Input value: [index] Current Delete by Index, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}

	if (search)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(700, 450);
		aboveText->setString("Input value: [value] Current search, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}

	if (update)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(700, 450);
		aboveText->setString("Input value: [index] [space] [value] Current Update by Index, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}
	if (Delete_Tail->isClicked(window))
	{
		doublyLL.deleteTail();
		visual.pop_tail();
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

	if (Search->isClicked(window))
	{
		search = !(search);
	}

	visual.render2arrow(window, search, search_data);

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
		LinkedList = 0;
		MenuCur = 1;
	}

	delete BackButton, Init, Search, Add_Tail, Delete_Tail, Add_Head, Delete_Head, Add_Index, Delete_Index, Random_Init;
}