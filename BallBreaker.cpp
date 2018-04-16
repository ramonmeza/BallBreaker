#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Ball.hpp"

using namespace std;
using namespace sf;

int main(int argc, char* argv[])
{
	RenderWindow window(VideoMode(500, 500), "Brick Breaker");

	Game* game = Game::GetGame();

	Ball b;
	b.Load();
	
	Clock DeltaClock;
	Time deltaTime;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		b.Update(deltaTime.asSeconds());

		window.clear();
		window.draw(b);
		window.display();

		deltaTime = DeltaClock.restart();
	}

	return 0;
}