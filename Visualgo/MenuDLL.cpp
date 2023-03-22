#include "MenuDLL.h"

void MenuDLL(sf::RenderWindow& window, sf::Font& font, bool &MenuCur, bool &LinkedList, TextBox &textField, Buttons& visual, TextBox& addField, doublyLinkedList& doublyLL, bool &init, bool &add_tail, bool &add_head)
{
	Button* BackButton = new Button(50, 20, 200, 50, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 50, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Search = new Button(100, 200, 200, 50, font, "Search",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Tail = new Button(100, 300, 200, 50, font, "Add Tail",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Tail = new Button(100, 400, 200, 50, font, "Delete Tail",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Head = new Button(100, 500, 200, 50, font, "Add Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Head = new Button(100, 600, 200, 50, font, "Delete Head",
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

	Init->render(window);
	Search->render(window);
	Add_Tail->render(window);
	Delete_Tail->render(window);
	Add_Head->render(window);
	Delete_Head->render(window);

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

	if (init)
	{
		textField.draw(window);
	}
	if (add_tail || add_head)
	{
		addField.draw(window);
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
	visual.render(window);

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

	delete BackButton, Init, Search, Add_Tail, Delete_Tail;
}
