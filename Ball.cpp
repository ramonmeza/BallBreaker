#include "Ball.hpp"

Ball::Ball()
{
	texture->loadFromFile("images/brick_embossed.png");
	sprite.setTexture(*texture);

	Initialize();
}

Ball::Ball(sf::Texture* tex, sf::Color color)
{
	texture = tex;
	sprite.setTexture(*texture);
	sprite.setColor(color);

	Initialize();
}

void Ball::Initialize()
{
	sprite.setOrigin((float)texture->getSize().x / 2, (float)texture->getSize().y / 2);
	velocity = sf::Vector2f(1000.0f, 5000.0f);
}

void Ball::Update(float dt, sf::Vector2u bounds)
{
	// Get new positions
	float x = sprite.getPosition().x + (velocity.x * dt);
	float y = sprite.getPosition().y + (velocity.y * dt);

	// Set position
	sprite.setPosition(x, y);

	// Bounce
	if (sprite.getPosition().x - (sprite.getLocalBounds().width / 2) <= 0 || sprite.getPosition().x + (sprite.getLocalBounds().width / 2) >= bounds.x)
	{
		velocity.x = -velocity.x;
	}

	if (sprite.getPosition().y - (sprite.getLocalBounds().height / 2) <= 0 || sprite.getPosition().y + (sprite.getLocalBounds().height / 2) >= bounds.y)
	{
		velocity.y = -velocity.y;
	}
}

Ball::~Ball()
{

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}