#include "Game.hpp"

// Singleton
Game* Game::instance = nullptr;

Game::Game()
{
	LoadTextures();
}

Game::~Game()
{

}

void Game::LoadTextures()
{
	// Temporary storage for our textures
	sf::Texture* texture;

	// Load ball texture
	texture = new sf::Texture();
	texture->loadFromFile("images/ball.png");
	resources.AddTexture("ball", texture);
}

Game* Game::GetGame()
{
	if (instance == nullptr)
	{
		instance = new Game();
	}

	return instance;
}

sf::RenderWindow* Game::GetWindow()
{
	return &window;
}

ResourceManager* Game::GetResources()
{
	return &resources;
}