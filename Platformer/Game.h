
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "PreCompiledHeaders.h"
#include "Player.h"

class Game{
private:
    sf::RenderWindow Window;
    sf::Event Event;
    Player* Player;
    void InitializePlayer();
    void InitializeWindow();



public:
    Game();
    ~Game();

    //Functions
    void UpdatePlayer();
    void UpdateCollision();
    void Update();
    void RenderPlayer();
    void Render();
    const sf::RenderWindow& GetWindow();
};

#endif //PLATFORMER_GAME_H
