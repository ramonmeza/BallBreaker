#include "Menu.hpp"

Menu::Menu()
{
	font.loadFromFile("fonts/Roboto-Regular.ttf");
}

Menu::~Menu()
{
	options.clear();
}

void Menu::LoadTextures()
{

}

void Menu::LoadObjects()
{

}

void Menu::AddText(std::string text, sf::Vector2f position)
{
	sf::Text* temp = new sf::Text(text, font);
	temp->setPosition(position);
	temp->setFillColor(sf::Color::White);
	temp->setCharacterSize(30);
	options.push_back(temp);
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto itr = GameObjectPool.begin(); itr != GameObjectPool.end(); itr++)
	{
		target.draw(*(itr->second));
	}

	for (auto itr = options.begin(); itr != options.end(); itr++)
	{
		target.draw(*(*itr));
	}
}