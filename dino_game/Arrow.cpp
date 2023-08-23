#include "Arrow.h"
#include <time.h>


Arrow::Arrow()
{
	//drawing position
	srand(time(NULL));
	int x = rand() % 2;
	switch (x)
	{
	case 1:
		self.setPosition(sf::Vector2f(805.f, 450.f));
		break;
	default:
		self.setPosition(sf::Vector2f(805.f, 530.f));
		break;
	}

	this->self.setSize(sf::Vector2f(47, 15));
	this->self.setScale(sf::Vector2f(1.2, 1.2));

	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(133,0,47,15));
	this->sprite.setScale(sf::Vector2f(1.2, 1.2));

}

Arrow::~Arrow()
{
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

void Arrow::move(sf::Vector2f vec)
{
	this->self.move(vec);
}
