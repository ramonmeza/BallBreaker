#include "Paddle.hpp"
#include "Game.hpp"

Paddle::Paddle()
{

}

Paddle::~Paddle()
{
}

void Paddle::Load()
{
	// Load texture
	sf::Texture* tex = Game::GetGame()->GetCurrentGameState()->GetResources()->GetTexture("paddle");
	sprite.setTexture(*tex);
	sprite.setOrigin((float)tex->getSize().x / 2.0f, (float)tex->getSize().y / 2.0f);
}

void Paddle::Update()
{
	// Follow mouse movement
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*Game::GetGame()->GetWindow());
	sprite.setPosition((float) mousePosition.x, 400.0f);
}