#ifndef MONSTER_H
#define MONSTER_H

#include "../Character.h"
#include <SFML/Graphics.hpp>

class Monster : public Character {
public:
    Monster() = default;
    Monster(float speed, const sf::Texture& texture, int life);

    // Méthode d'update spécifique pour le monstre
    void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight, int positionPlayerX, int positionPlayerY);
    
    // Mise à jour du sprite du monstre
    void updateSprite() override;

private:
    void positionnerSurBord();
    float m_scaleFactor;
};

#endif

