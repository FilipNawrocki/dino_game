#pragma once

#include<iostream>
#include <memory>
#include<vector>
#include<ctime>
#include<sstream>

#include "Arrow.h"
#include "Creeper.h"
#include "player.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode vm;
	sf::Event ev;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text scoretext;
	std::vector<std::unique_ptr<enemy>> wrogowie;

	sf::RectangleShape ludzik;
	
	Arrow ar;
	Creeper cr;
	player pl;

	sf::Clock clock;
	sf::Time dttime;
	sf::Clock AnimationClock;

	float time;
	float gravity;
	float jumpStrength;
	float dinoYVelocity;
	float wrogacceleration;
	float wrogvelocity;
	float dt;

	float elapsed_time;
	bool skok;

	int points;

	float enemySpawnTimer;
	float enemySpawnTimerMax;
	float enemySpawnT;

	void zmienne();
	void okno();
	void RenderWrog();
	void Rendfloor();
	void pullevents();
	void SpawnWrog();
	void EndGame();
	void UpdateWrog();
	void UpdateLudz();
	void UpdatePoints();

public:
	Game();
	~Game();

	const bool getWindowIsOpen() const;

	void Update();
	int getPoints();
	void Render();
	void defludzik();

};


