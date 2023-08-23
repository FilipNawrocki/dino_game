#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include <iostream>

void player::Animation()
{
	if (this->elapsed_time >= time_per_frame) {
		this->elapsed_time = 0;

		aktualna_klatka = (aktualna_klatka + 1) % VecRec.size();
		sprite.setTextureRect(VecRec[aktualna_klatka]);
	}
}

player::player()
{
	this->self.setPosition(sf::Vector2f(100.f,506.f));
	self.setSize(sf::Vector2f(47,40));
	self.setScale(1.1,1.6);

	this->texture.loadFromFile("y27zIvC.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(843, 0, 47, 40));
	this->time_per_frame = 0.15f;

	VecRec.push_back(sf::IntRect(843, 0, 47, 40));
	//VecRec.push_back(sf::IntRect(894, 0, 47, 40));
	VecRec.push_back(sf::IntRect(933, 0, 47, 40));
	VecRec.push_back(sf::IntRect(979, 0, 47, 40));

	this->aktualna_klatka = 0;
	this->dinoYVelocity =-8.0f;
	this->gravity = 0.2f;

	//this->sprite.setTextureRect();
}

void player::Update(float elapsed_time1, bool skok1)
{
	this->elapsed_time = elapsed_time + elapsed_time1;
	if (!skok1)
	{
		this->Animation();
	}
	this->jump(skok1);
}

void player::draw(sf::RenderWindow& render)
{
	sprite.setScale(1.1,1.6);
	sprite.setPosition(self.getPosition());
	render.draw(sprite);
}

sf::FloatRect player::getGlobalBounds()
{
	return self.getGlobalBounds();
}

void player::jump(bool skok)
{
	if (skok) {
		//std::cout << "skok! " << std::endl;
		dinoYVelocity += gravity;
		self.move(0, dinoYVelocity);

		if (self.getPosition().y >= 506) {
			self.setPosition(self.getPosition().x,506);
			//std::cout << "stop \n";
			skok = false;
			dinoYVelocity = -8.0f;
		}
	}

	if (!skok)
	{
		this->self.setPosition(sf::Vector2f(100.f, 506.f));
	}

}


