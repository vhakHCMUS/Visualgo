#include "MenuStaticArray.h"

void MenuStaticArray(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& StaticArray)
{
	Button* BackButton = new Button(50, 20, 200, 50, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 50, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Search = new Button(100, 200, 200, 50, font, "Search",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Add_Head = new Button(100, 300, 200, 50, font, "Add Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Delete_Head = new Button(100, 400, 200, 50, font, "Delete Head",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Search->update(window);
	Add_Head->update(window);
	Delete_Head->update(window);

	Init->render(window);
	Search->render(window);
	Add_Head->render(window);
	Delete_Head->render(window);

	if (BackButton->isClicked(window))
	{
		StaticArray = 0;
		MenuCur = 1;
	}

	delete BackButton, Init, Search, Add_Head, Delete_Head;
}
