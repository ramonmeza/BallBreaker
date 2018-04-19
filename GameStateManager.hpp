/*
				GameStateManager.hpp

	Description:
		GameStateManager allows us a way to keep track of
		GameStates.
*/
#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP
#pragma once

#include <vector>
#include "GameState.hpp"

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void AddGameState(GameState* state);
	void RemoveGameState();

	GameState* GetCurrentGameState();

private:
	std::vector<GameState*> states;
};

#endif