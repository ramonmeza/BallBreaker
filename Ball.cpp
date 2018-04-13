#include "Ball.hpp"

Ball::Ball()
{
	texture->loadFromFile("images/brick_embossed.png");
	sprite.setTexture(*texture);
}

Ball::Ball(sf::Texture* tex, sf::Color color)
{
	texture = tex;
	sprite.setTexture(*texture);
	sprite.setColor(color);
	sprite.setPosition(100, 100);
}

Ball::~Ball()
{

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}