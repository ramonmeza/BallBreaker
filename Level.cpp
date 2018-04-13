#include "Level.hpp"

Level::Level()
{
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile("images/brick_embossed.png");
	RM.AddTexture("brick_embossed", tex);

	bricks.push_back(new Brick(RM.GetTexture("brick_embossed"), sf::Color::Red));
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