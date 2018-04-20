#ifndef PADDLE_HPP
#define PADDLE_HPP
#pragma once

#include "GameObject.hpp"

class Paddle : public GameObject
{
public:
	Paddle();
	~Paddle();

	// Load the resources needed for this object
	void Load();

	// Update the ball (position)
	void Update();
};

#endif