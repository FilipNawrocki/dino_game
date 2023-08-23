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
	RenderWindow *window;
	VideoMode vm;
	Event ev;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text scoretext;
	std::vector<std::unique_ptr<enemy>> wrogowie;

	RectangleShape ludzik;
	
	Arrow ar;
	Creeper cr;
	player pl;

	Clock clock;
	Time dttime;
	sf::Clock AnimationClock;

	float time;
	float gravity;
	float jumpStrength;
	float dinoYVelocity;
	float wrogacceleration;
	float wrogvelocity;
	float dt;

	float elapsed_time;

	void zmienne();
	void okno();
	bool skok;

	int points;


	float enemySpawnTimer;
	float enemySpawnTimerMax;
	float enemySpawnT;


public:
	Game();
	~Game();

	const bool getWindowIsOpen() const;

	void pullevents();
	void SpawnWrog();

	void EndGame();

	void UpdateWrog();
	void UpdateLudz();
	void UpdatePoints();
	void Update();

	void RenderWrog();
	void Rendfloor();
	void Render();

	void defludzik();

};


