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
    int margin = 60; // Décalage des bords
    int bord = std::rand() % 4; // Positionner aléatoirement sur un bord

    if (bord == 0) { // Bord gauche
        this->b_position = {static_cast<float>(margin), static_cast<float>(std::rand() % (windowHeight - 2 * margin) + margin)};
    } else if (bord == 1) { // Bord droit
        this->b_position = {static_cast<float>(windowWidth - margin), static_cast<float>(std::rand() % (windowHeight - 2 * margin) + margin)};
    } else if (bord == 2) { // Bord haut
        this->b_position = {static_cast<float>(std::rand() % (windowWidth - 2 * margin) + margin), static_cast<float>(margin)};
    } else { // Bord bas
        this->b_position = {static_cast<float>(std::rand() % (windowWidth - 2 * margin) + margin), static_cast<float>(windowHeight - margin)};
    }

    // Appliquer la position à l'objet
    this->getSprite()->setPosition(this->b_position);
}


