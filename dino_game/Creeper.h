#pragma once
#include "enemy.h"
class enemy;
class Creeper : public enemy
{
private:
	sf::RectangleShape self;
public:
	Creeper();
	~Creeper();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	void draw(sf::RenderWindow& render);
	void move(sf::Vector2f vec);
};

