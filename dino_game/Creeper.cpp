#include "Creeper.h"

Creeper::Creeper()
{
	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(330, 0, 27, 45));
	this->sprite.setScale(sf::Vector2f(1.4, 1.7));
	this->self.setPosition(sf::Vector2f(705.f, 497.f));

}

sf::Vector2f Creeper::getPosition()
{
	return self.getPosition();
}

sf::FloatRect Creeper::getGlobalBounds()
{
	return self.getGlobalBounds();
}

void Creeper::draw(sf::RenderWindow& render)
{
	sprite.setPosition(self.getPosition());
	render.draw(sprite);
}
