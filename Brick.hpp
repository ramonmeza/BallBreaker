/*

Class name: Brick

Description: Represents a brick in the game.

*/

#ifndef BRICK_HPP
#define BRICK_HPP
#pragma once

#include <SFML/Graphics.hpp>

class Brick : public sf::Drawable
{
public:
	Brick();
	Brick(sf::Texture* tex, sf::Color color = sf::Color::White);
	~Brick();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif
