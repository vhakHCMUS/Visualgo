#include "MenuStaticArray.h"

void MenuStaticArray(sf::RenderWindow& window, sf::Font& font, bool& MenuCur, bool& StaticArray, bool& init, bool& search, int search_data, bool& update, TextBox& textField, TextBox& addField, int& arraySize, int array[], Buttons &visual)
{
	Button* BackButton = new Button(50, 20, 200, 50, font, "Back",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Init = new Button(100, 100, 200, 50, font, "Init",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Search = new Button(100, 200, 200, 50, font, "Search",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	Button* Update = new Button(100, 300, 200, 50, font, "Update",
		sf::Color::Blue, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

	MenuCur = 0;

	BackButton->update(window);
	BackButton->render(window);

	Init->update(window);
	Search->update(window);
	Update->update(window);


	Init->render(window);
	Search->render(window);
	Update->render(window);

	if (Init->isClicked(window)) init = !(init);

	if (Search->isClicked(window)) search = !(search);

	if (Update->isClicked(window)) update = !(update);

	if (init)
	{
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(600, 10);
		aboveText->setString("Input value");
		window.draw(*aboveText);
		textField.draw(window);
		delete aboveText;
	}

	if (search)
	{
		addField.draw(window);

		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(900, 550);
		aboveText->setString("Input value: [value] Current search, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}

	if (update)
	{
		addField.draw(window);
		sf::Text* aboveText = new sf::Text();
		aboveText->setFont(font);
		aboveText->setString("Input value: ");
		aboveText->setCharacterSize(20);
		aboveText->setFillColor(sf::Color::Red);
		aboveText->setPosition(900, 550);
		aboveText->setString("Input value: [index] [space] [value] Current Update by Index, click again to quit");
		window.draw(*aboveText);
		delete aboveText;
	}
	if (BackButton->isClicked(window))
	{
		StaticArray = 0;
		MenuCur = 1;
		while (visual.block.size()) visual.block.pop_back();
	}

	visual.renderArray(window, search, search_data, font);
	delete BackButton, Init, Search, Update;
}
