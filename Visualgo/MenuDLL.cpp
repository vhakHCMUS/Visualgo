#include "MenuDLL.h"

void MenuDLL(sf::RenderWindow& window, sf::Font& font, bool &MenuCur, bool &LinkedList, TextBox &textField, Buttons& visual, TextBox& addField)
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

	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Search->update(window);
	Add_Tail->update(window);
	Delete_Tail->update(window);

	Init->render(window);
	Search->render(window);
	Add_Tail->render(window);
	Delete_Tail->render(window);

	static bool init = false;
	static bool add = false;
	if (Init->isClicked(window))
	{
		init = !(init);
	}
	if (Add_Tail->isClicked(window))
	{
		add = !(add);
	}

	if (init)
	{
		textField.draw(window);
	}
	if (add)
	{
		addField.draw(window);
	}

	if (Delete_Tail->isClicked(window))
	{
		visual.pop_tail();
	}
	visual.render(window);

	if (BackButton->isClicked(window))
	{
		LinkedList = 0;
		MenuCur = 1;
	}

	delete BackButton, Init, Search, Add_Tail, Delete_Tail;
}
