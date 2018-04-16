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
	void Update(float dt);

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	sf::Sprite sprite;
	sf::Vector2f velocity;
};

#endif