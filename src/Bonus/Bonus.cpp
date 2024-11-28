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

void Bonus::positionnerBonus(int WinWidth, int WinHeight) {
    int margin = 60;

    // Générer une position aléatoire avec un décalage depuis les bords
    float posX = static_cast<float>(std::rand() % (WinWidth - 2 * margin) + margin);
    float posY = static_cast<float>(std::rand() % (WinHeight - 2 * margin) + margin);

    // Mettre à jour la position dans la classe
    setPos(posX, posY);

    // Appliquer la position au sprite
    this->getSprite()->setPosition(this->b_position);
}

void Bonus::setPos(float x, float y) {
    this->b_position.x = x;
    this->b_position.y = y;
}



