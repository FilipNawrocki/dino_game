#pragma once

#include<iostream>
#include <memory>
#include<vector>
#include<ctime>
#include<sstream>
#include "Arrow.h"
#include "Creeper.h"

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

	RectangleShape wrog;
	std::vector<RectangleShape> wrogow;
	sf::Texture texture;
	sf::Sprite sprite;
	std::vector<std::unique_ptr<enemy>> wrogowie1;

	RectangleShape ludzik;
	
	Arrow ar;
	Creeper cr;

	Clock clock;
	Time dttime;

	float time=0.f;
	float gravity = 0.2f;
	float jumpStrength = -10.0f;
	float dinoYVelocity = 0.0f;
	float wrogacceleration = 0.2;
	float wrogvelocity = 3;
	float dt;

	void zmienne();
	void okno();
	bool skok;
	bool gora;
	int points;
	int pixels;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	float enemySpawnT;


public:
	Game();
	~Game();

	const bool getWindowIsOpen() const;

	void choicewrog();
	void pullevents();
	void SpawnWrog();
	void UpdateWrog();
	void UpdateLudz();
	void Update();
	void RenderWrog();
	void Rendfloor();
	void Render();
	void wrogowie();
	void defludzik();

};


