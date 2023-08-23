#pragma once
#include <SFML/Graphics.hpp>

class enemy
{
private:
	int pos_X;
	int pos_Y;
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	enemy();
	~enemy();
	virtual void draw(sf::RenderWindow& render) = 0;
	virtual void move(sf::Vector2f vec) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual sf::FloatRect getGlobalBounds() = 0;
};

