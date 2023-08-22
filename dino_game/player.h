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

	void Animation( );

public:
	player();
	void Update(float elapsed_time1);
	void draw(sf::RenderWindow& render);
	void jump();


};

