#pragma once
#include "enemy.h"
#include<SFML/Graphics.hpp>

class enemy;

class Arrow : public enemy
{
private:
	sf::RectangleShape self;

public:
	Arrow();
	~Arrow();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	void draw(sf::RenderWindow& render);
	void move(sf::Vector2f vec);
};

