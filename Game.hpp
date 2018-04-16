/*
				Game.hpp

	Description:
		Game is the director of the game. It implements
		the singleton pattern.
*/
#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

class Game
{

public:
	~Game();

	sf::RenderWindow* GetWindow();
	ResourceManager* GetResources();

private:
	void LoadTextures();

	// Holds all of the resources
	ResourceManager resources;

	// Window properties
	sf::RenderWindow window;

/* Singleton */
public:
	// Static access method
	static Game* GetGame();

private:
	// Singleton
	Game();
	static Game* instance;
};

#endif
