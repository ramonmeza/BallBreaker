#include <iostream>

#include "Level.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

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
	std::cout << "Loading ball texture..." << std::endl;
	texture = new sf::Texture();
	texture->loadFromFile("images/ball.png");
	resources.AddTexture("ball", texture);

	// Load paddle texture
	std::cout << "Loading paddle texture..." << std::endl;
	texture = new sf::Texture();
	texture->loadFromFile("images/paddle.png");
	resources.AddTexture("paddle", texture);
}

void Level::LoadObjects()
{
	// Load ball object
	std::cout << "Loading ball object..." << std::endl;
	Ball* ball = new Ball();
	ball->Load();
	ball->SetPosition(250.0f, 200.f);
	AddGameObjectToPool(GameObjectType::BALL, ball);

	// Load paddle object
	std::cout << "Loading paddle object..." << std::endl;
	Paddle* paddle = new Paddle();
	paddle->Load();
	AddGameObjectToPool(GameObjectType::PADDLE, paddle);
}