#ifndef PLAYER_H
#define PLAYER_H

#include "../Character.h"

class Player : public Character {

public:
    // Constructeur qui passe la vitesse au constructeur de Character
    Player(float s, int l);

    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight);

    void updateSprite();

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void moveTop();

    void stopTop();

    void moveDown();

    void stopDown();
};

#endif
