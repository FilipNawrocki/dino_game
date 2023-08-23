#pragma once
#include "game.h"

class StartWindow
{
private:

	sf::RenderWindow* window;
	sf::VideoMode vm;
	sf::Event ev;

	sf::Font font;
	sf::Text text;
	sf::Text text1;

	int points;
	bool startgame;

	void okno();
	void pullevents();
	void StartGame();
	void Text();
	void PrintPoints();

public:

	StartWindow();

	const bool getWindowIsOpen() const;

	void Update();

	void Render();




};

