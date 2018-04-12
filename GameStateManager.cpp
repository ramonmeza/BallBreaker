#include "GameStateManager.hpp"

GameStateManager::GameStateManager()
{
	// Add the default game state
	AddGameState(new GameState());
}

GameStateManager::~GameStateManager()
{

}

// State management
void GameStateManager::AddGameState(GameState* state)
{
	// Add given state to states
	states.push_back(state);
}

void GameStateManager::RemoveCurrentGameState()
{
	// If there is a current game state (not including the default game state)
	if (states.size() > 1)
	{
		// Remove the latest game state
		states.pop_back();
	}
}

// Accessors
GameState* GameStateManager::GetCurrentGameState()
{
	// Return the current game state
	return states.back();
}