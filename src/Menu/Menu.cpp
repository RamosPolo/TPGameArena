//
// Created by PC on 28/11/2024.
//

#include "Menu.h"


Menu::Menu() = default;

void Menu::setMenu(int WsizeX, int WsizeY) {
    // Dimensions du fond du menu
    this->getSpriteBackground()->scale(sf::Vector2f(1.f, 1.f));
    FloatRect backgroundBounds = this->getSpriteBackground()->getGlobalBounds();

    // Calcul de la position pour centrer le fond dans la fenêtre
    float centeredXB = (WsizeX - backgroundBounds.width) / 2;
    float centeredYB = (WsizeY - backgroundBounds.height) / 2;

    // Application de la position centrée
    this->getSpriteBackground()->setPosition(centeredXB, centeredYB);

    // Redimensionnement du bouton
    this->getSpriteButton()->scale(sf::Vector2f(0.5f, 0.5f));

    // Récupération des dimensions du bouton après l'échelle
    FloatRect buttonBounds = this->getSpriteButton()->getGlobalBounds();

    // Récupération des dimensions et position du rectangle
    FloatRect menuBounds = this->getSpriteBackground()->getGlobalBounds();

    // Calcul de la position centrée
    float centeredX = menuBounds.left + (menuBounds.width - buttonBounds.width) / 2;
    float centeredY = menuBounds.top + (menuBounds.height - buttonBounds.height) / 2;

    // Positionnement du bouton
    this->getSpriteButton()->setPosition(centeredX, centeredY);
}

void Menu::setTextureButton(const Texture &t) {
    this->menu_ButtonSprite.setTexture(t);
}

void Menu::setTextureBackground(const Texture &t) {
    this->menu_BackgroundSprite.setTexture(t);
}

Sprite *Menu::getSpriteButton() {
    return &this->menu_ButtonSprite;
}

Sprite *Menu::getSpriteBackground() {
    return &this->menu_BackgroundSprite;
}

bool Menu::isButtonClicked(float posXMouse, float posYMouse) {
    // Récupérer les limites globales du bouton
    FloatRect buttonBounds = this->getSpriteButton()->getGlobalBounds();

    // Vérifier si la position de la souris est dans les limites
    return buttonBounds.contains(posXMouse, posYMouse);
}