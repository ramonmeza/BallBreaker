#include "Level.hpp"
#include <iostream>
Level::Level()
{
	std::cout << "Loading level..." << std::endl;
}

Level::~Level()
{
}

void Level::LoadTextures()
{
	// Temporary storage for our textures
	sf::Texture* texture;

	// Load ball texture
	texture = new sf::Texture();
	texture->loadFromFile("images/ball.png");
	resources.AddTexture("ball", texture);
}

void Level::LoadObjects()
{
	std::cout << "Loading ball..." << std::endl;
	Ball* ball = new Ball();
	ball->Load();
	ball->SetPosition(250.0f, 200.f);
	AddGameObjectToPool(GameObjectType::BALL, ball);
}