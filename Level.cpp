#include "Level.hpp"

Level::Level()
{
	LevelSize = sf::Vector2u(100, 100);
	Load();
}

Level::Level(sf::RenderTarget& target)
{
	LevelSize = target.getSize();
	Load();
}

void Level::Load()
{
	// Create bricks
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile("images/brick_embossed.png");
	RM.AddTexture("brick_embossed", tex);
	bricks.push_back(new Brick(RM.GetTexture("brick_embossed"), sf::Color::Red));

	// Create ball
	tex = new sf::Texture();
	tex->loadFromFile("images/ball.png");
	RM.AddTexture("ball", tex);
	ball = new Ball(RM.GetTexture("ball"), sf::Color::White);
}

Level::~Level()
{
	bricks.clear();

	delete ball;
	ball = nullptr;
}

void Level::Update(float dt)
{
	// Update ball
	ball->Update(dt, LevelSize);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw bricks
	for (auto itr = bricks.begin(); itr != bricks.end(); itr++)
	{
		target.draw(*(*itr));
	}

	// Draw ball
	target.draw(*ball);
}