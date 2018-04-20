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

	void AddGameState(GameState* state);
	void RemoveGameState();

	// Accessors
	sf::RenderWindow* GetWindow();
	sf::Time* GetDeltaTime();
	float GetTimeStep();
	GameState* GetCurrentGameState();

private:
	bool IsPaused;

	// Game state manager
	GameStateManager StateManager;

	// Game functions
	void HandleInput(sf::Keyboard::Key key);
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