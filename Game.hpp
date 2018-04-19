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

#include "GameStateManager.hpp"

class Game
{
public:
	~Game();

	void Load();
	void Run();

	sf::RenderWindow* GetWindow();
	sf::Time* GetDeltaTime();
	float GetTimeStep();
	GameState* GetCurrentGameState();

private:
	// Game state manager
	GameStateManager StateManager;

	// Game functions
	void HandleInput();
	void Update();
	void Draw();

	// Window properties
	sf::RenderWindow window;
	sf::Time DeltaTime;
	float TimeStep;

/* Singleton */
public:
	static Game* GetGame();

private:
	Game();
	static Game* instance;
};

#endif