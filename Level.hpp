#ifndef LEVEL_HPP
#define LEVEL_HPP
#pragma once

#include <vector>

#include "Brick.hpp"
#include "GameState.hpp"
#include "ResourceManager.hpp"

class Level : public GameState
{
public:
	Level();
	~Level();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	ResourceManager RM;
	std::vector<Brick*> bricks;
};

#endif