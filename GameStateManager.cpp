#include "GameStateManager.hpp"

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{
	states.clear();
}

void GameStateManager::AddGameState(GameState* state)
{
	states.push_back(state);
}

void GameStateManager::RemoveGameState()
{
	GameState* temp = states.back();
	states.pop_back();
	delete temp;
}

GameState* GameStateManager::GetCurrentGameState()
{
	return states.back();
}