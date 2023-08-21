#pragma once


#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

class AnimatedSprite : public Sprite
{

private:
    int fps;
    int i;
    sf::Time time;
    std::vector<IntRect> klatki;
public:
    AnimatedSprite(int animationFps);
    
    void dodaj_klatke(IntRect frameRect);
    
    void step(Time deltaTime);
    

};

