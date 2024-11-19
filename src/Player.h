#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    // Constructeur qui passe la vitesse au constructeur de Character
    Player(float speed = 400);

    // Implémentation des méthodes de mouvement spécifiques au joueur
    void moveLeft() override;
    void moveRight() override;
    void stopLeft() override;
    void stopRight() override;
    void moveTop() override;
    void stopTop() override;
    void moveDown() override;
    void stopDown() override;

    // Implémentation de la méthode update pour le joueur
    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight) override;
};

#endif
