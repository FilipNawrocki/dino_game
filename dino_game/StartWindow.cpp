#include "StartWindow.h"

StartWindow::StartWindow()
{
	this->okno();
	this->startgame = false;
	this->Text();

}

void StartWindow::pullevents()
{

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (ev.key.code == sf::Keyboard::Enter)
				this->startgame = true;
		}

	}
}

void StartWindow::StartGame()
{
	if (startgame)
	{
		Game game;
		while (game.getWindowIsOpen())
		{

			points = game.getPoints();
			game.Update();

			game.Render();

		}

	}
	startgame = false;
}

void StartWindow::Text()
{

	font.loadFromFile("strikefighter.ttf");
	text.setFont(font);
	text.setPosition(100, 70);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setString("Press Enter to start the game");


	font.loadFromFile("strikefighter.ttf");
	text1.setFont(font);
	text1.setPosition(100, 350);
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::White);
	text1.setString("Score: 0");
}



void StartWindow::Update()
{
	this->pullevents();
	this->StartGame();
	this->PrintPoints();
}

void StartWindow::Render()
{
	this->window->clear(sf::Color::Black);
	this->window->draw(text);
	this->window->draw(text1);
	this->window->display();
}

void StartWindow::okno()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Start_window", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

const bool StartWindow::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void StartWindow::PrintPoints()
{
	text1.setString("Score: " + std::to_string(points));
}