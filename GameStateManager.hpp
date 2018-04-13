/*

Class name: GameStateManager

Description: Holds GameState objects and can swap between them.
			 Basically a glorified stack, whichever GameState object
			 is on the top of the stack is drawn.

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