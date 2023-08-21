#include "Animacja.h"

AnimatedSprite::AnimatedSprite(int animationFps)
{
    i = 0;
    fps = animationFps;
    time = Time::Zero;
}

void AnimatedSprite::dodaj_klatke(IntRect frameRect)
{
    klatki.push_back(frameRect);
}

void AnimatedSprite::step(Time deltaTime)
{
    time += deltaTime;
    sf::Time x = sf::seconds(1.f / float(fps));
    if (time >= x)
    {
        time -= x;
        i++;
        if (i >= klatki.size())
        {
            i = 0;
        }
        setTextureRect(klatki[i]);
    }
}


