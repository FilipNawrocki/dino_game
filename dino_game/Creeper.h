#pragma once
#include "enemy.h"
class enemy;
class Creeper : public enemy
{
private:
	sf::RectangleShape self;

public:
	Creeper();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	void draw(sf::RenderWindow& render);

};

