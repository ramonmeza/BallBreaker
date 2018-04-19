#include "Game.hpp"
#include "Level.hpp"

// Singleton
Game* Game::instance = nullptr;

Game::Game() :
	window(sf::VideoMode(500, 500), "Brick Breaker")
{
}

Game::~Game()
{

}

void Game::Load()
{
	std::cout << "Loading game..." << std::endl;
	StateManager.AddGameState(new Level());
	StateManager.GetCurrentGameState()->Load();
}

void Game::Run()
{
	Load();

	sf::Clock DeltaClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::KeyPressed)
				HandleInput();
		}

		Update();
		
		window.clear();

		Draw();

		window.display();

		// Update delta time
		DeltaTime = DeltaClock.restart();
	}
}

void Game::HandleInput()
{
}

void Game::Update()
{
	StateManager.GetCurrentGameState()->Update();
}

void Game::Draw()
{
	window.draw(*StateManager.GetCurrentGameState());
}

Game* Game::GetGame()
{
	if (instance == nullptr)
	{
		instance = new Game();
	}

	return instance;
}

sf::RenderWindow* Game::GetWindow()
{
	return &window;
}

sf::Time* Game::GetDeltaTime()
{
	return &DeltaTime;
}

GameState* Game::GetCurrentGameState()
{
	return StateManager.GetCurrentGameState();
}