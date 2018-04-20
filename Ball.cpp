#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball()
{
	velocity = sf::Vector2f(500.0f, 500.0f);
}

Ball::~Ball()
{
}

void Ball::Load()
{
	// Load texture
	sf::Texture* tex = Game::GetGame()->GetCurrentGameState()->GetResources()->GetTexture("ball");
	sprite.setTexture(*tex);
	sprite.setOrigin((float) tex->getSize().x / 2.0f, (float) tex->getSize().y / 2.0f);
}

void Ball::Update()
{
	sprite.setPosition(sprite.getPosition().x + (velocity.x * Game::GetGame()->GetDeltaTime()->asSeconds()), sprite.getPosition().y + (velocity.y * Game::GetGame()->GetDeltaTime()->asSeconds()));
	CheckForBounce();
}

void Ball::CheckForBounce()
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2f bounds = sf::Vector2f((float) Game::GetGame()->GetWindow()->getSize().x, (float) Game::GetGame()->GetWindow()->getSize().y);

	// Horizontal bounce
	if (position.x < 0.0f || position.x > bounds.x)
	{
		velocity.x *= -1.0f;
	}

	// Vertical bounce
	if (position.y < 0.0f)
	{
		velocity.y *= -1.0f;
	}

	// DEBUG bounce
	if (position.y > bounds.y)
	{
		velocity.y *= -1.0f;
	}
}

void Ball::SetPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Ball::SetPosition(float x, float y)
{
	SetPosition(sf::Vector2f(x, y));
}