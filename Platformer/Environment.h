#ifndef PLATFORMER_ENVIRONMENT_H
#define PLATFORMER_ENVIRONMENT_H

#include "PreCompiledHeaders.h"

class Environment {
private:

    sf::Sprite EnvironmentSprite;
    const bool Danger;

public:
    Environment(sf::Texture& TextureSheet, sf::IntRect TextureRect, bool Danger = false);

    const sf::FloatRect GetGlobalBounds();

    void Update();
    void Render(sf::RenderTarget& Target);
};


#endif //PLATFORMER_ENVIRONMENT_H
