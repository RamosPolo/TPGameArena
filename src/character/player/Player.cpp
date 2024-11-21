#include "Player.h"
#include <vector>
#include <iostream>
#include "Player.h"

Player::Player(float speed) : Character(speed) {
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
