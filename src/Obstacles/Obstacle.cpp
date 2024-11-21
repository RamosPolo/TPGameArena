//
// Created by PC on 21/11/2024.
//

#include "Obstacle.h"

#include <stdexcept>

Obstacle::Obstacle() {
    if (!O_Texture.loadFromFile("../assets/image/WallTexture.png")) {
        throw std::runtime_error("Erreur : Impossible de charger la texture !");
    }
    O_sprite.setTextureRect(IntRect(10,10,64,64));
    O_sprite.setTexture(O_Texture);
    O_sprite.setScale(2,2);
}
void Obstacle::setPosition(const float x, const float y) {
    O_position.x = x;
    O_position.y = y;
    O_sprite.setPosition(O_position);
}

Sprite Obstacle::getSprite() {
    return O_sprite;
}
