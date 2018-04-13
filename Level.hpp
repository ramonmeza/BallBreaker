/*

Class name: Level

Description: A GameState that represents the actual game. Includes the ball, bricks and player.

*/

#ifndef LEVEL_HPP
#define LEVEL_HPP
#pragma once

#include <vector>

#include "Ball.hpp"
#include "Brick.hpp"
#include "GameState.hpp"
#include "ResourceManager.hpp"

class Level : public GameState
{
public:
	Level();
	Level(sf::RenderTarget& target);
	~Level();

	void Load();

	virtual void Update(float dt);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Vector2u LevelSize;

	ResourceManager RM;
	std::vector<Brick*> bricks;
	Ball* ball;
};

#endif