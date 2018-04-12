#include "Level.hpp"

Level::Level()
{
	bricks.push_back(new Brick(sf::Color::Red));
}

Level::~Level()
{

}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto itr = bricks.begin(); itr != bricks.end(); itr++)
	{
		target.draw(*(*itr));
	}
}