#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

using namespace std;
using namespace sf;

int main(int argc, char* argv[])
{
	Game::GetGame()->Run();

	return 0;
}