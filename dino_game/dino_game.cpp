#include <iostream>
#include "game.h"
#include "StartWindow.h"
using namespace sf;

int main()
{
	//Game game;
	StartWindow startwindow;
	//srand(static_cast<unsigned>(time(NULL)));

	while (startwindow.getWindowIsOpen())
	{
	

		startwindow.Update();


		startwindow.Render();

	
	}


	return 0;
}