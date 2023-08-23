#include "Creeper.h"

Creeper::Creeper()
{
	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(330, 0, 27, 45));
	this->sprite.setScale(sf::Vector2f(1.3, 1.6));
	this->self.setPosition(sf::Vector2f(805.f, 500.f));
	this->self.setSize(sf::Vector2f(27,43));
	this->self.setScale(sf::Vector2f(1.3, 1.6));

}

Creeper::~Creeper()
{
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

void Creeper::move(sf::Vector2f vec)
{
	this->self.move(vec);
}
