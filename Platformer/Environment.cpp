#include "Environment.h"

Environment::Environment(sf::Texture &TextureSheet, sf::IntRect TextureRect, bool Danger):Danger(Danger){
    this->EnvironmentSprite.setTexture(TextureSheet);
    this->EnvironmentSprite.setTextureRect(TextureRect);
}

const sf::FloatRect Environment::GetGlobalBounds() {
    return this->EnvironmentSprite.getGlobalBounds();
}

void Environment::Update() {

}

void Environment::Render(sf::RenderTarget &Target) {
    Target.draw(this->EnvironmentSprite);
}
