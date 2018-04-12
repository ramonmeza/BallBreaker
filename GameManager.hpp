#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameState.hpp"
#include "GameStateManager.hpp"

class GameManager
{
public:
	// Constructors
	GameManager();
	~GameManager();

	// 
	void Initialize();
	void Run(float timestep = 1.0f / 60.0f);

	// Accessors
	sf::Time GetDeltaTime() { return DeltaTime; }
	float GetTimestep() { return Timestep; }

	// Mutator
	void SetTimestep(float timestep) { Timestep = timestep; }

private:
	// Critical events
	void HandleInput();
	void Update();
	void Draw();

	// Window properties
	sf::RenderWindow window;
	sf::Time DeltaTime;
	float Timestep;

	// Managers
	GameStateManager GSM;
};

#endif