//
// Created by PC on 21/11/2024.
//

#include "Obstacle.h"

Obstacle::Obstacle(float x, float y) {
    O_Texture.loadFromFile("../assets/image/Obstacle.png");
    O_sprite.setTextureRect(sf::IntRect(0,0,64,64));
    O_sprite.setPosition(x,y);
    O_sprite.setScale(2,2);
}
