/*
	Class name: GameStateManager

	Description: Keeps track of which state is the current state.
*/

#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP
#pragma once

#include <vector>
#include "GameState.hpp"

class GameStateManager {
public:
	// Constructors
	GameStateManager();
	~GameStateManager();

	// State management
	void AddGameState(GameState* state);
	void RemoveCurrentGameState();

	// Accessors
	GameState* GetCurrentGameState();

private:
	std::vector<GameState*> states;
	GameState* CurrentStates;
};

#endif