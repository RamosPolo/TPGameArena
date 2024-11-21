//
// Created by PC on 19/11/2024.
//

#include "Bullet.h"

Bullet::Bullet() {

    b_Texture.loadFromFile("./assets/image/fire-bullet.png");
    b_Sprite.setTexture(b_Texture);
}

Sprite Bullet::getSprite() {
    return b_Sprite;
}

void Bullet::setPosition(float x, float y) {
    b_position.x = x;
    b_position.y = y;
}

void Bullet::move(float elapsedTime) {
    setPosition(b_position.x + elapsedTime, b_position.y);
}


