#ifndef MENU_HPP
#define MENU_HPP
#pragma once

#include <string>

#include "GameState.hpp"

class Menu : public GameState
{
public:
	Menu();
	~Menu();

	void AddText(std::string text, sf::Vector2f position);

protected:
	virtual void LoadTextures();
	virtual void LoadObjects();

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	sf::Font font;
	std::vector<sf::Text*> options;
};

#endif