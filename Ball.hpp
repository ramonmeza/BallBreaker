/*
				Ball.hpp

	Description:
		Ball is the GameObject in game that bounces off
		of the walls, bricks, and player.
*/
#ifndef BALL_HPP 
#define BALL_HPP
#pragma once

#include "GameObject.hpp"

class Ball : public GameObject
{
public:
	Ball();
	~Ball();
	
	// Load the resources needed for this object
	void Load();

	// Update the ball (position)
	void Update();

	// Set position
	void SetPosition(sf::Vector2f pos);
	void SetPosition(float x, float y);

private:
	sf::Vector2f velocity;

	void CheckForBounce();
};

#endif