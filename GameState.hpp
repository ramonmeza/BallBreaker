/*
				GameState.hpp

	Description:
		GameState is an abstract class that represents a specific 
		screen in the game. It can be a menu screen or the actual game.
*/
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#pragma once

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "GameObject.hpp"
#include "GameObjectType.hpp"

class GameState : public sf::Drawable
{
public:
	GameState();
	~GameState();

	void Load();
	void Update();

	ResourceManager* GetResources();

protected:
	// Loading functions
	virtual void LoadTextures() = 0;
	virtual void LoadObjects() = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	// Holds all of the resources
	ResourceManager resources;

	// Stores all of the game objects we need
	std::vector<std::pair<GameObjectType, GameObject*>> GameObjectPool;

	void AddGameObjectToPool(GameObjectType type, GameObject* object);
};

#endif