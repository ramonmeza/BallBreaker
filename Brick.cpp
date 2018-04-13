#include "Brick.hpp"

#include <iostream>

Brick::Brick()
{
	texture->loadFromFile("images/brick_embossed.png");
	sprite.setTexture(*texture);
}

Brick::Brick(sf::Texture* tex, sf::Color color)
{
	texture = tex;
	sprite.setTexture(*texture);
	sprite.setColor(color);
	sprite.setPosition(10, 10);
}

Brick::~Brick()
{

}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}