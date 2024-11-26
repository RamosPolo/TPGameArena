#ifndef PLAYER_H
#define PLAYER_H

#include "../Character.h"

class Player : public Character {
public:
    Player(float speed, int life);

    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight);
    void updateSprite() override;
};

#endif
