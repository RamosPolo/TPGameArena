//
// Created by PC on 25/11/2024.
//

#include "Bonus.h"

Bonus::Bonus(){
    this->bonustype = "default";
}

void Bonus::setTextureBonus(const Texture &t) {
    this->getSprite()->setTexture(t);
}

String Bonus::getTypeBonus() {
    return this->bonustype;
}

FireBonus::FireBonus() {
    this->bonustype = "fire";
}

SnowBonus::SnowBonus() {
    this->bonustype = "snow";
}

DefaultBonus::DefaultBonus() {
    this->bonustype = "default";
}

void Bonus::positionnerBonus() {
    int windowWidth = 1920, windowHeight = 1080;
    int bord = std::rand() % 4;  // Positionner aléatoirement sur un bord

    if (bord == 0) this->b_position = {50, static_cast<float>(std::rand() % windowHeight)};
    else if (bord == 1) this->b_position = {static_cast<float>(windowWidth) + 50, static_cast<float>(std::rand() % windowHeight)};
    else if (bord == 2) this->b_position = {static_cast<float>(std::rand() % windowWidth), 50};
    else this->b_position = {static_cast<float>(std::rand() % windowWidth), static_cast<float>(windowHeight)+50};

    this->getSprite()->setPosition(this->b_position);
}


