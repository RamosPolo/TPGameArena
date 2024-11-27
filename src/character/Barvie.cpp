#include "Barvie.h"
#include <iostream>
#include <string>

Barvie::Barvie(const Character& c) {
    // Création du rectangle (carré)
    float textWidth = 50.f;  // Largeur fixe pour le carré (ajustez cette valeur selon vos besoins)
    float textHeight = 50.f; // Hauteur fixe pour le carré (ajustez cette valeur selon vos besoins)
    
    // Initialisation du rectangle
    b_rec.setSize(sf::Vector2f(textWidth, textHeight));
    b_rec.setPosition(c.getPositionX(), c.getPositionY());
    b_rec.setFillColor(sf::Color::Green);
}

void Barvie::update(const Character& c) {
    b_rec.setPosition(c.getPositionX() + 80, c.getPositionY() - 20);
    b_rec.setSize(sf::Vector2f(20*c.getLife(), 20));
    if(c.getLife() <= 3 && c.getLife() > 1){
        b_rec.setFillColor(sf::Color::Yellow);
    }else if (c.getLife() == 1)
    {
        b_rec.setFillColor(sf::Color::Red);
    }
}

sf::RectangleShape Barvie::getRectangle() {
    return b_rec;
}
