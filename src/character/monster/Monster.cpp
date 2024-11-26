#include <vector>
#include <iostream>
#include "Monster.h"
#include <cmath>
#include <cstdlib> 
#include <ctime> 

Monster::Monster(float speed) : Character(speed) {
        // Gérer l'erreur si le fichier n'est pas trouvé
        std::cerr << "Erreur: Impossible de charger le sprite sheet !" << std::endl;
    }

    m_Speed = 100;

    m_FrameWidth = 900;
    m_FrameHeight = 900;

    float scaleFactor = 1.0f / 3.0f;

    // Définir le sprite avec la première frame (décalée de 10px dans le sprite sheet)
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setTextureRect(sf::IntRect(10, 10, m_FrameWidth, m_FrameHeight));
    m_Sprite.setScale(scaleFactor, scaleFactor); // Orientation normale


    // Initialiser le générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(0)) + std::rand());  // Modification pour garantir des valeurs différentes

    // Positionner le monstre aléatoirement sur un des bords
    positionnerSurBord();
    m_Sprite.setPosition(m_Position);
}

// Fonction pour positionner le monstre sur un bord de la fenêtre de jeu
void Monster::positionnerSurBord() {
    int windowWidth = 1920; 
    int windowHeight = 1080;

    int bord = std::rand() % 4; 

    if (bord == 0) {  // Bord gauche
        m_Position.x = 0;  
        m_Position.y = std::rand() % windowHeight;
    }
    else if (bord == 1) {  // Bord droit
        m_Position.x = windowWidth;  
        m_Position.y = std::rand() % windowHeight;  
    }
    else if (bord == 2) {  // Bord haut
        m_Position.x = std::rand() % windowWidth;  
        m_Position.y = 0; 
    }
    else {  // Bord bas
        m_Position.x = std::rand() % windowWidth;  
        m_Position.y = windowHeight;
    }
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

void Monster::moveLeft() {
    m_LeftPressed = true;
    updateSprite();  
}

void Monster::moveRight() {
    m_RightPressed = true;
    updateSprite();  
}

void Monster::stopLeft() {
    m_LeftPressed = false;
    updateSprite();  
}

void Monster::stopRight() {
    m_RightPressed = false;
    updateSprite();  
}

void Monster::moveTop() {
    m_TopPressed = true;
    updateSprite();
}

void Monster::stopTop() {
    m_TopPressed = false;
    updateSprite();  
}

void Monster::moveDown() {
    m_DownPressed = true;
    updateSprite();  
}

void Monster::stopDown() {
    m_DownPressed = false;
    updateSprite();  
}


void Monster::updateSprite() {
    // Réduction de la taille du sprite (divisé par 3)
    float scaleFactor = 1.0f / 3.0f;

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
    if (m_RightPressed && !m_IsFacingRight) {
        m_IsFacingRight = true;
        m_Sprite.setScale(scaleFactor, scaleFactor); // Orientation normale
        m_Sprite.setOrigin(0, 0);
    } else if (m_LeftPressed && m_IsFacingRight) {
        m_IsFacingRight = false;
        m_Sprite.setScale(-scaleFactor, scaleFactor); // Miroir horizontal
        m_Sprite.setOrigin(900, 0); // Ajustement pour l'inversion horizontale
    }
}


