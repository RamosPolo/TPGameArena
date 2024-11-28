//
// Created by PC on 28/11/2024.
//

#include "GameOver.h"

#include <iostream>


void GameOver::setGameOver(int WsizeX, int WsizeY) {
    // Dimensions du fond du menu
    this->getSpriteBackgroundGO()->scale(sf::Vector2f(1.f, 1.f));
    FloatRect backgroundBounds = this->getSpriteBackgroundGO()->getGlobalBounds();

    // Calcul de la position pour centrer le fond dans la fenêtre
    float centeredXB = (WsizeX - backgroundBounds.width) / 2;
    float centeredYB = (WsizeY - backgroundBounds.height) / 2;

    // Application de la position centrée
    this->getSpriteBackgroundGO()->setPosition(centeredXB, centeredYB);

    // Charger une police
    if (!menu_font.loadFromFile("../assets/font/arial.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return;
    }
    setTitle(WsizeX, WsizeY);
    setContent(WsizeX, WsizeY);
}

void GameOver::setTitle(int WsizeX, int WsizeY) {
    // Configurer le texte
    Title_text.setFont(menu_font);
    Title_text.setString("Game Over");
    Title_text.setCharacterSize(50); // Taille des caractères
    Title_text.setFillColor(Color::White); // Couleur du texte
    Title_text.setStyle(Text::Bold); // Style optionnel (gras ici)

    // Centrer le texte sur l'écran
    FloatRect textBounds = Title_text.getLocalBounds();
    Title_text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    Title_text.setPosition(WsizeX / 2.0f, WsizeY / 2.5f);
}

void GameOver::setContent(int WsizeX, int WsizeY) {
    // Configurer le texte
    result_text.setFont(menu_font);
    result_text.setCharacterSize(40); // Taille des caractères
    result_text.setFillColor(Color::White); // Couleur du texte
    result_text.setStyle(Text::Bold); // Style optionnel (gras ici)

    // Centrer le texte sur l'écran
    FloatRect textBounds = Title_text.getLocalBounds();
    result_text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    result_text.setPosition(WsizeX / 2.1f, WsizeY / 2.3f);
}

void GameOver::setTexte(String txt) {
    result_text.setString(txt);
}

Sprite *GameOver::getSpriteBackgroundGO() {
    return &this->GO_BackgroundSprite;
}

void GameOver::setTextureBGGO(const Texture &t) {
    this->GO_BackgroundSprite.setTexture(t);
}

Text GameOver::getTitle() {
    return this->Title_text;
}

Text GameOver::getContent() {
    return this->result_text;
}