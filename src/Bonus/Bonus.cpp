//
// Created by PC on 25/11/2024.
//

#include "Bonus.h"

Bonus::Bonus() {
    this->type = "default";
}

void Bonus::setPosition(Vector2f v) {
    this->b_position = v;
}

/*
Sprite* Bonus::getSprite() {
    return &this->b_Sprite;
}
*/

void Bonus::setTextureBonus(const Texture &t) {
    this->getSprite()->setTexture(t);
}


std::string Bonus::getType() {
    return this->type;
}

FireBonus::FireBonus() {
    this->type = "fire";
    b_position = Vector2f(rand() % 800, rand() % 600); // Position aléatoire
}

SnowBonus::SnowBonus() {
    this->type = "snow";
    b_position = Vector2f(rand() % 800, rand() % 600); // Position aléatoire
}


