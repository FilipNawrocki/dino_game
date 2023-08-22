#include <iostream>
#include "game.h"
#include "enemy.h"
using namespace sf;

int main()
{
	Game game;
	//srand(static_cast<unsigned>(time(NULL)));

	while (game.getWindowIsOpen())
	{
	

		game.Update();


		game.Render();

	
	}


	return 0;
}