#include "Game.h"

void Game::InitializeWindow() {
    //Creates the window
    this->Window.create(sf::VideoMode(800,600), "Platformer", sf::Style::Close | sf::Style::Titlebar);
    this->Window.setFramerateLimit(60);
}


Game::Game(){
    this->InitializePlayer();
    this->InitializeWindow();

}

void Game::InitializePlayer() {
    this->Player = new class Player();
}

Game::~Game(){
    delete this->Player;
}

void Game::UpdatePlayer() {
    this->Player->Update();
}

void Game::Update() {
//Window Events
    while(this->Window.pollEvent(this->Event))
    {
        if (this->Event.type == sf::Event::Closed)
            this->Window.close();
        else if(this->Event.type == sf::Event::KeyPressed && this->Event.key.code == sf::Keyboard::Escape) //Pressing ESC key will exit the Window
            this->Window.close();
    }

    this->UpdatePlayer();

    this->UpdateCollision();
}

void Game::RenderPlayer() {
    this->Player->Render(this->Window);
}

void Game::Render() {
    this->Window.clear();
    //Game render
    this->RenderPlayer();
    this->Window.display();
}


const sf::RenderWindow & Game::GetWindow(){
    return this->Window;
}

void Game::UpdateCollision() {
    //Collision with the bottom of the screen.
    if (this->Player->GetGlobalBounds().top + this->Player->GetGlobalBounds().height > this->Window.getSize().y){
        this->Player->ResetVelocityY();
        this->Player->SetPosition(this->Player->GetGlobalBounds().left, this->Window.getSize().y - this->Player->GetGlobalBounds().height);
    }
}
