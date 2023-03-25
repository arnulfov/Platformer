#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

class Player{
private:
    sf::Sprite PlayerSprite;
    sf::Texture TextureSheet;

    //Player physics(variables)
    sf::Vector2f Velocity;
    float MaxVelocity;
    float MinimumVelocity;
    float Acceleration;
    float Deceleration;
    float Gravity;
    float MaxVelocityY;


    void InitializeTexture();
    void InitializeSprite();
    void InitializePhysics();

public:
    Player();
    ~Player();

    const sf::FloatRect GetGlobalBounds();

    void SetPosition(const float X, const float Y);
    void ResetVelocityY();

    //Functions
    void Move(const float DirectionX, const float DirectionY);
    void UpdatePlayerPhysics();
    void Movement();
    void Update();
    void Render(sf::RenderTarget& Target);
};


#endif //PLATFORMER_PLAYER_H
