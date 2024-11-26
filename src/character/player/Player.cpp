#include "Player.h"
#include <vector>
#include <iostream>
#include "Player.h"

Player::Player(){
    if (!m_Texture.loadFromFile("./assets/image/Wraith/Walking.png")) {
        // Gérer l'erreur si le fichier n'est pas trouvé
        std::cerr << "Erreur: Impossible de charger le sprite sheet !" << std::endl;
    }

    // Définir la taille d'une frame (selon ton sprite sheet)
    m_FrameWidth = 520;
    m_FrameHeight = 420;

    // Définir le sprite avec la première frame (décalée de 10px dans le sprite sheet)
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setTextureRect(sf::IntRect(10, 10, m_FrameWidth, m_FrameHeight));
    m_Sprite.setScale(0.5f, 0.5f); 

    // Positionner le sprite sur la scène
    m_Position.x = 500; // Position initiale en X
    m_Position.y = 800; // Position initiale en Y
    m_Sprite.setPosition(m_Position);
}

void Player::update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight) {
    if (m_RightPressed && m_Position.x + m_Sprite.getGlobalBounds().width < windowWidth) {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed && m_Position.x > 0) {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_TopPressed && m_Position.y > 0) {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed && m_Position.y + m_Sprite.getGlobalBounds().height < windowHeight) {
        m_Position.y += m_Speed * elapsedTime;
    }

    updateSprite();
    m_Sprite.setPosition(m_Position);
}


void Player::moveLeft() {
    m_LeftPressed = true;
    updateSprite();  
}

void Player::moveRight() {
    m_RightPressed = true;
    updateSprite();  
}



void Player::stopLeft() {
    m_LeftPressed = false;
    updateSprite();  
}

void Player::stopRight() {
    m_RightPressed = false;
    updateSprite();  
}

void Player::moveTop() {
    m_TopPressed = true;
    updateSprite();
}

void Player::stopTop() {
    m_TopPressed = false;
    updateSprite();  
}

void Player::moveDown() {
    m_DownPressed = true;
    updateSprite();  
}

void Player::stopDown() {
    m_DownPressed = false;
    updateSprite();  
}


void Player::updateSprite() {
    if (m_RightPressed || m_LeftPressed || m_TopPressed || m_DownPressed) {
        m_CurrentFrame = (m_CurrentFrame + 1) % 12; // 12 frames au total (3 lignes x 4 colonnes)

        // Calculer la position de la frame dans le sprite sheet
        int column = m_CurrentFrame % 4; // 4 colonnes
        int row = m_CurrentFrame / 4;   // 3 lignes

        // Définir la région de la frame à afficher
        int x = 10 + column * 540; // 10px de décalage + 520px de largeur + 20px d'espace
        int y = 10 + row * 440;    // 10px de décalage + 420px de hauteur + 20px d'espace
        m_Sprite.setTextureRect(sf::IntRect(x, y, 520, 420));
    }

    // Gérer l'orientation du sprite
    if (m_RightPressed && !m_IsFacingRight) {
        m_IsFacingRight = true;
        m_Sprite.setScale(0.5f, 0.5f);
        m_Sprite.setOrigin(0, 0);
    } else if (m_LeftPressed && m_IsFacingRight) {
        m_IsFacingRight = false;
        m_Sprite.setScale(-0.5f, 0.5f);
        m_Sprite.setOrigin(520, 0); // Ajustement pour l'inversion horizontale
    }
}
