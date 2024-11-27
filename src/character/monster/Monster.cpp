#include "Monster.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Monster::Monster(float speed, const sf::Texture& texture, int life)
    : Character(speed, life) {
    m_FrameWidth = 900;
    m_FrameHeight = 900;
    m_Texture = texture;
    m_Sprite.setTexture(texture);
    m_Sprite.setTextureRect(sf::IntRect(0, 0, m_FrameWidth, m_FrameHeight));
    positionnerSurBord();
    m_Sprite.setPosition(m_Position);
}

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
        m_Position.x += deltaX * m_Speed * elapsedTime;
        m_Position.y += deltaY * m_Speed * elapsedTime;
    }

    // Vérification des limites de la fenêtre
    if (m_Position.x < 0) m_Position.x = 0;
    if (m_Position.x + m_Sprite.getGlobalBounds().width > windowWidth) 
        m_Position.x = windowWidth - m_Sprite.getGlobalBounds().width;
    if (m_Position.y < 0) m_Position.y = 0;
    if (m_Position.y + m_Sprite.getGlobalBounds().height > windowHeight) 
        m_Position.y = windowHeight - m_Sprite.getGlobalBounds().height;

    // Met à jour la position et le sprite
    updateSprite();
    m_Sprite.setPosition(m_Position);
}

void Monster::updateSprite() {
    // Réduction de la taille du sprite (divisé par 3)
    float scaleFactor = 0.3f;

    // Définir la frame à afficher (ici, testons la frame avec l'indice 3)
    m_CurrentFrame = (m_CurrentFrame + 1) % 23; // On boucle entre 23 frames valides

    // Calcul des coordonnées dans le sprite sheet (5 colonnes et 5 lignes)
    int column = m_CurrentFrame % 5; 
    int row = m_CurrentFrame / 5;  

    // Calculer la position exacte de la frame dans le sprite sheet
    int x = column * 930; 
    int y = row * 930;    

    // Définir la région de la frame dans le sprite sheet
    m_Sprite.setTextureRect(sf::IntRect(x, y, 930, 930)); // Sélectionner la portion correcte de la texture


    // Gérer l'orientation du sprite
    if (m_RightPressed) {
        m_Sprite.setScale(scaleFactor, scaleFactor);
        m_Sprite.setOrigin(0, 0);
    } else if (m_LeftPressed) {
        m_Sprite.setScale(-scaleFactor, scaleFactor);
        m_Sprite.setOrigin(900, 0);
    }
}
