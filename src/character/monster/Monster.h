#ifndef MONSTER_H
#define MONSTER_H

#include "../Character.h"

class Monster : public Character {

public:

    Monster(float speed = 200, const Texture& texture = getDefaultTexture(), int l = 3);

    // Implémentation des méthodes de mouvement spécifiques au joueur
    void moveLeft() ;
    void moveRight() ;
    void stopLeft() ;
    void stopRight() ;
    void moveTop() ;
    void stopTop() ;
    void moveDown() ;
    void stopDown() ;
    void updateSprite() ;
 
    // Implémentation de la méthode update pour le joueur
    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight, int positionPlayerX, int positionPlayerY );
    void positionnerSurBord();
};

#endif
