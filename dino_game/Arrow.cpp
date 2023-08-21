#include "Arrow.h"

Arrow::Arrow()
{
	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(133,0,47,15));
	this->sprite.setScale(sf::Vector2f(1.2, 1.2));
	self.setPosition(sf::Vector2f(500.f, 450.f));
}

sf::Vector2f Arrow::getPosition()
{
	return self.getPosition();
}

sf::FloatRect Arrow::getGlobalBounds()
{
	return self.getGlobalBounds();
}

void Arrow::draw(sf::RenderWindow& render)
{
	sprite.setPosition(self.getPosition());
	render.draw(sprite);
}