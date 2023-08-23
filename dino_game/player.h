#pragma once


class player
{
private:
	sf::RectangleShape self;
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::IntRect> VecRec;
	float elapsed_time;
	int aktualna_klatka;
	float time_per_frame;
	float dinoYVelocity;
	float gravity;

	void Animation( );

public:
	player();
	void Update(float elapsed_time1,bool skok1);
	void draw(sf::RenderWindow& render);
	sf::FloatRect getGlobalBounds();
	void jump(bool skok);


};

