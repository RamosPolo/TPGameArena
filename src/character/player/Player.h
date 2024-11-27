#ifndef PLAYER_H
#define PLAYER_H

#include "../Character.h"
#include <SFML/Graphics.hpp>

class Player : public Character {
public:
    Player() = default;
    Player(float speed, int life);

    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight);
    void updateSprite() override;

private:
    sf::Texture m_Texture;      
};

#endif
