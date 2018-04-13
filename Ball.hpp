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

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif
