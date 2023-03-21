#include "MenuQueue.h"

void MenuQueue(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& Queue, TextBox& textField, Buttons& visual, TextBox& addField, doublyLinkedList& queue, bool& init, bool& add)
{
	Button* BackButton = new Button(50, 20, 200, 50, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 50, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


	Button* Add = new Button(100, 300, 200, 50, font, "Add",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Pop = new Button(100, 400, 200, 50, font, "Pop",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Add->update(window);
	Pop->update(window);

	Init->render(window);
	Add->render(window);
	Pop->render(window);

	if (Init->isClicked(window))
	{
		init = !(init);
	}
	if (Add->isClicked(window))
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
	if (Pop->isClicked(window))
	{
		queue.deleteHead();
		visual.pop_head();
	}
	visual.render(window);

	if (BackButton->isClicked(window))
	{
		while (visual.block.size()) visual.block.pop_back();
		add = init = 0;
		Queue = 0;
		MenuCur = 1;
	}

	delete BackButton, Init, Add, Pop;
}
