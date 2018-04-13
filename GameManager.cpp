#include "GameManager.hpp"

GameManager::GameManager() :
	window(sf::VideoMode(500, 500), "Ball Breaker")
{
	// Add level to game state
	CurrentLevel = new Level(window);
	GSM.AddGameState(CurrentLevel);
}

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
}

void GameManager::Run(float timestep)
{
	// Set up delta clock and elapsed time
	sf::Clock DeltaClock;
	float timeElapsed = 0.0f;

	while (window.isOpen())
	{
		// Handle input
		HandleInput();

		// Update at a given time step
		if (timeElapsed >= timestep)
		{
			Update();
			timeElapsed = 0.0f;
		}

		// Draw
		Draw();

		// Set the delta time
		DeltaTime = DeltaClock.restart();
		timeElapsed += DeltaTime.asSeconds();
	}
}

void GameManager::HandleInput()
{
	// Handle input
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void GameManager::Update()
{
	// Update the current state
	GSM.GetCurrentGameState()->Update(DeltaTime.asSeconds());
}

void GameManager::Draw()
{
	window.clear();

	// Draw the current game state
	window.draw(*GSM.GetCurrentGameState());
	window.display();
}