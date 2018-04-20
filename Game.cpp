#include "Game.hpp"
#include "Level.hpp"
#include "Menu.hpp"

// Singleton
Game* Game::instance = nullptr;

Game::Game() :
	window(sf::VideoMode(500, 500), "Brick Breaker")
{
	TimeStep = 1.0f / 60.0f;
	IsPaused = false;
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
	float elapsed = 0.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::KeyReleased)
				HandleInput(event.key.code);
		}

		if (elapsed >= TimeStep)
		{
			Update();
			elapsed = 0.0f;
		}

		window.clear();

		Draw();

		window.display();

		// Update delta time
		DeltaTime = DeltaClock.restart();
		elapsed += DeltaTime.asSeconds();
	}
}

void Game::HandleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Escape:
		// Switch paused bool
		IsPaused = !IsPaused;

		if (IsPaused)
		{
			std::cout << "Game paused..." << std::endl;
			Menu* pause = new Menu();
			pause->AddText("Hi", sf::Vector2f(100.0f, 100.0f));
			AddGameState(pause);
		}
		else
		{
			std::cout << "Game unpaused..." << std::endl;
			RemoveGameState();
		}
		break;
	default:
		break;
	}
}

void Game::Update()
{
	StateManager.GetCurrentGameState()->Update();
}

void Game::Draw()
{
	window.draw(*StateManager.GetCurrentGameState());
}

void Game::AddGameState(GameState* state)
{
	StateManager.AddGameState(state);
}

void Game::RemoveGameState()
{
	StateManager.RemoveGameState();
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

float Game::GetTimeStep()
{
	return TimeStep;
}

GameState* Game::GetCurrentGameState()
{
	return StateManager.GetCurrentGameState();
}