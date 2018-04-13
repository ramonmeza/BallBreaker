/*

Class name: Ball

Description: Represents a ball in the game.

*/

#ifndef BALL_HPP
#define BALL_HPP
#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
public:
	Ball();
	Ball(sf::Texture* tex, sf::Color color = sf::Color::White);
	~Ball();

	void Initialize();
	void Update(float dt, sf::Vector2u bounds);

	// Accessor
	sf::Vector2f GetVelocity() { return velocity; }

	// Mutators
	void SetVelocity(sf::Vector2f vel) { velocity = vel; };

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture* texture;
	sf::Sprite sprite;

	sf::Vector2f velocity;
};

#endif
