#ifndef BRICK_HPP
#define BRICK_HPP
#pragma once

#include <SFML/Graphics.hpp>

class Brick : public sf::Drawable
{
public:
	Brick();
	Brick(sf::Color color);
	~Brick();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif
