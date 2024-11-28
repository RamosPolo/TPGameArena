#include <vector>
#include <iostream>
#include "Monster.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Monster::Monster(float speed, const sf::Texture& texture, int life, float scaleFactor)
    : Character(speed, life, scaleFactor) {

    // Définir la taille initiale des frames (doit correspondre à celles utilisées dans updateSprite)
    m_FrameWidth = 430;  // Largeur de chaque frame
    m_FrameHeight = 600; // Hauteur de chaque frame

    m_Texture = texture; // Associer la texture
    m_scaleFactor = scaleFactor; // Facteur de mise à l'échelle du sprite

    // Configurer le sprite avec la texture
    this->getSprite()->setTexture(texture);

    // Définir la première frame affichée (offset initial)
    int initialX = 300; 
    int initialY = 200; 
    this->getSprite()->setTextureRect(sf::IntRect(initialX, initialY, m_FrameWidth, m_FrameHeight));
    this->getSprite()->setOrigin(0, 0);

    // Appliquer l'échelle
    this->getSprite()->setScale(m_scaleFactor, m_scaleFactor);


    // Définir d'autres propriétés
    this->setType("monster");
    positionnerSurBord(); // Positionner le monstre sur le bord
    this->getSprite()->setPosition(m_Position); // Appliquer la position
}


// Fonction pour positionner le monstre sur un bord de la fenêtre de jeu
void Monster::positionnerSurBord() {
    int windowWidth = 1920, windowHeight = 1080;
    int bord = std::rand() % 4;  // Positionner aléatoirement sur un bord

    if (bord == 0) m_Position = {0, static_cast<float>(std::rand() % windowHeight)};
    else if (bord == 1) m_Position = {static_cast<float>(windowWidth), static_cast<float>(std::rand() % windowHeight)};
    else if (bord == 2) m_Position = {static_cast<float>(std::rand() % windowWidth), 0};
    else m_Position = {static_cast<float>(std::rand() % windowWidth), static_cast<float>(windowHeight)};
}

void Monster::update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight, int positionPlayerX, int positionPlayerY) {
    float deltaX = positionPlayerX - m_Position.x;
    float deltaY = positionPlayerY - m_Position.y;

    // Calcul de la distance
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    // Initialiser les états des directions
    m_RightPressed = false;
    m_LeftPressed = false;

    // Normalisation de la direction (éviter une division par zéro)
    if (distance > 0) {
        deltaX /= distance;
        deltaY /= distance;

        // Déterminer la direction horizontale uniquement
        if (deltaX > 0) {
            m_RightPressed = true; // Déplacement vers la droite
        } else {
            m_LeftPressed = true;  // Déplacement vers la gauche
        }

        // Mise à jour de la position
        Move(deltaX * m_Speed * elapsedTime, deltaY * m_Speed * elapsedTime);

    }

    // Vérification des limites de la fenêtre
    if (m_Position.x < 0) m_Position.x = 0;
    if (m_Position.x + this->getSprite()->getGlobalBounds().width > windowWidth)
        m_Position.x = windowWidth - this->getSprite()->getGlobalBounds().width;
    if (m_Position.y < 0) m_Position.y = 0;
    if (m_Position.y + this->getSprite()->getGlobalBounds().height > windowHeight)
        m_Position.y = windowHeight - this->getSprite()->getGlobalBounds().height;

    // Met à jour la position et le sprite
    updateSprite();
    this->getSprite()->setPosition(m_Position);
}

void Monster::updateSprite() {
    // Réduction de la taille du sprite (divisé par 3)

    // Définir la frame à afficher (ici, testons la frame avec l'indice 3)
    m_CurrentFrame = (m_CurrentFrame + 1) % 23; // On boucle entre 23 frames valides

    // Calcul des coordonnées dans le sprite sheet (5 colonnes et 5 lignes)
    int column = m_CurrentFrame % 5; 
    int row = m_CurrentFrame / 5;  

    // Calculer la position exacte de la frame dans le sprite sheet
  

    int x = 300 + column * (m_FrameWidth + 480); 
    int y = 200 + row * (m_FrameHeight + 300);  

    // Définir la région de la frame dans le sprite sheet
    this->getSprite()->setTextureRect(sf::IntRect(x, y, m_FrameWidth, m_FrameHeight)); // Sélectionner la portion correcte de la texture

    // Gérer l'orientation du sprite
    if (m_RightPressed) {
        this->getSprite()->setScale(m_scaleFactor, m_scaleFactor);
        this->getSprite()->setOrigin(0, 0);
    } else if (m_LeftPressed) {
        this->getSprite()->setScale(-m_scaleFactor, m_scaleFactor);
        this->getSprite()->setOrigin(m_FrameWidth, 0);
    }
}

void Monster::Move(float x, float y){
         m_Position.x += x;
         m_Position.y += y;
}