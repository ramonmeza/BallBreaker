#ifndef LEVEL_HPP
#define LEVEL_HPP
#pragma once

#include <vector>
#include "GameState.hpp"
#include "Brick.hpp"

class Level : public GameState
{
public:
	Level();
	~Level();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Brick*> bricks;
};

#endif