#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::AddGameObjectToPool(GameObjectType type, GameObject* object)
{
	GameObjectPool.emplace_back(type, object);
}

ResourceManager* GameState::GetResources()
{
	return &resources;
}

void GameState::Load()
{
	// Loading
	LoadTextures();
	LoadObjects();
}

void GameState::Update()
{
	for (auto itr = GameObjectPool.begin(); itr != GameObjectPool.end(); itr++)
	{
		itr->second->Update();
	}
}

void GameState::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto itr = GameObjectPool.begin(); itr != GameObjectPool.end(); itr++)
	{
		target.draw(*(itr->second));
	}
}