#include "Player.h"
#include <iostream>

Player::Player(float speed, int life)
    : Character(speed, life) {

        m_FrameWidth = 520;
        m_FrameHeight = 420;

    if (!m_Texture.loadFromFile("./assets/image/Wraith/Walking.png")) {
        std::cerr << "Erreur : Impossible de charger le sprite sheet !" << std::endl;
    }

    // Position et dimensions ajustées
    int newFrameWidth = m_FrameWidth - 300;
    int newFrameHeight = m_FrameHeight - 100;
    int x = 160, y = 60;

    // Initialisation du sprite
    this->getSprite()->setTexture(m_Texture);
    this->getSprite()->setTextureRect(sf::IntRect(x, y, newFrameWidth, newFrameHeight));
    this->getSprite()->setScale(0.5f, 0.5f);

    // Position initiale
    m_Position = {500, 800};
    this->getSprite()->setPosition(m_Position);
}

void Player::update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight) {
    if (m_RightPressed && m_Position.x + this->getSprite()->getGlobalBounds().width < windowWidth) {
        m_Position.x += m_Speed * elapsedTime;
    }
    if (m_LeftPressed && m_Position.x > 0) {
        m_Position.x -= m_Speed * elapsedTime;
    }
    if (m_TopPressed && m_Position.y > 0) {
        m_Position.y -= m_Speed * elapsedTime;
    }
    if (m_DownPressed && m_Position.y + this->getSprite()->getGlobalBounds().height < windowHeight) {
        m_Position.y += m_Speed * elapsedTime;
    }

    updateSprite();
    this->getSprite()->setPosition(m_Position);
}

void Player::updateSprite() {
    if (m_LeftPressed || m_RightPressed || m_TopPressed || m_DownPressed) {
        // Mise à jour de l'animation
        m_CurrentFrame = (m_CurrentFrame + 1) % 12;
        int column = m_CurrentFrame % 4;
        int row = m_CurrentFrame / 4;

        // Ajustement du rectangle de la texture
        int newFrameWidth = m_FrameWidth - 300;
        int newFrameHeight = m_FrameHeight - 100;
        int x = 160 + column * (m_FrameWidth + 20);
        int y = 60 + row * (m_FrameHeight + 20);
        this->getSprite()->setTextureRect(sf::IntRect(x, y, newFrameWidth, newFrameHeight));
    }

    // Inverser l'échelle si nécessaire
    if (m_RightPressed && !m_IsFacingRight) {
        m_IsFacingRight = true;
        this->getSprite()->setScale(0.5f, 0.5f);
        this->getSprite()->setOrigin(0, 0);
    } else if (m_LeftPressed && m_IsFacingRight) {
        m_IsFacingRight = false;
        this->getSprite()->setScale(-0.5f, 0.5f);
        this->getSprite()->setOrigin(m_FrameWidth - 300, 0);
    }
}
