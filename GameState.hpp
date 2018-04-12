#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#pragma once

#include <SFML/Graphics.hpp>

class GameState : public sf::Drawable
{
public:
	GameState();
	~GameState();

	virtual void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

private:
};

#endif
