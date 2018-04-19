/*
				Level.hpp

	Description:
		Level is a GameState that represents the actual game.
		Level holds a ball that bounces along with bricks.
*/
#ifndef LEVEL_HPP
#define LEVEL_HPP
#pragma once

#include "GameState.hpp"
#include "Ball.hpp"

class Level : public GameState
{
public:
	Level();
	~Level();

protected:
	virtual void LoadTextures();
	virtual void LoadObjects();
};

#endif