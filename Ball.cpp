#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball()
{
	velocity = sf::Vector2f(100.0f, 500.0f);
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
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}