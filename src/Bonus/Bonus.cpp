//
// Created by PC on 25/11/2024.
//

#include "Bonus.h"

Bonus::Bonus() {
    this->bonustype = "default";
}

void Bonus::setPosition(Vector2f v) {
    this->b_position = v;
}

void Bonus::setTextureBonus(const Texture &t) {
    this->getSprite()->setTexture(t);
}


String Bonus::getTypeBonus() {
    return this->bonustype;
}

FireBonus::FireBonus() {
    this->bonustype = "fire";
    b_position = Vector2f(rand() % 800, rand() % 600); // Position aléatoire
}

SnowBonus::SnowBonus() {
    this->bonustype = "snow";
    b_position = Vector2f(rand() % 800, rand() % 600); // Position aléatoire
}


