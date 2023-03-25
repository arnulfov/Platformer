#include "PreCompiledHeaders.h"
#include "Player.h"

using std::cout;
using std::abs;

void Player::InitializeTexture() {
    //Loads texture(sprite) of player and prints out an error if texture can't be found.
    if (!this->TextureSheet.loadFromFile("Textures/egg2.png")){
        cout <<"Player could not load."<<"\n";
    }
}

void Player::InitializeSprite() {
    this->PlayerSprite.setTexture(this->TextureSheet);
}

void Player::InitializePhysics() {
    //Initializes physics variables
    this->MaxVelocity = 10.f;
    this->MinimumVelocity = 1.f;
    this->Acceleration = 3.f;
    this->Deceleration = 0.93f;
    this->Gravity = 4.f;
    this->MaxVelocityY = 15.f;
}

Player::Player() {
    this->InitializeTexture();
    this->InitializeSprite();
    this->InitializePhysics();

}

Player::~Player() {

}

void Player::Move(const float DirectionX, const float DirectionY) {
    //Acceleration in x direction
    this->Velocity.x +=DirectionX * this->Acceleration;

    //Limiting the Velocity
    if (abs(this->Velocity.x)> this->MaxVelocity){
        this->Velocity.x = this->MaxVelocity * ((this->Velocity.x < 0.f) ? -1.f : 1.f);
    }
}

void Player::UpdatePlayerPhysics() {
    //Gravity
    this->Velocity.y +=1.0 * this->Gravity;
    if (abs(this->Velocity.x)> this->MaxVelocityY){
        this->Velocity.y = this->MaxVelocityY * ((this->Velocity.x < 0.f) ? -1.f : 1.f);
    }
    //Deceleration
    this->Velocity *= this->Deceleration;

    //Limiting the deceleration
    if (abs(this->Velocity.x)<this->MinimumVelocity) {
        this->Velocity.x = 0.f;
    }
    if (abs(this->Velocity.y)<this->MinimumVelocity) {
        this->Velocity.y = 0.f;
    }
    this->PlayerSprite.move(this->Velocity);
}

void Player::Movement() {

    //Moves the player using WASD keys(jumping hasn't been implemented yet)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->Move(-1.f,0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->Move(1.f,0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->Move(0.f,-1.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->Move(0.f,1.f);
    }
}


void Player::Update() {
    this->Movement();
    this->UpdatePlayerPhysics();
}

void Player::Render(sf::RenderTarget & Target) {
    Target.draw(this->PlayerSprite);

}

const sf::FloatRect Player::GetGlobalBounds() {
    return this->PlayerSprite.getGlobalBounds();
}

void Player::SetPosition(const float X, const float Y) {
    this->PlayerSprite.setPosition(X,Y);
}

void Player::ResetVelocityY() {
    this->Velocity.y = 0.f;
}
