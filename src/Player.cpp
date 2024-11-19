#include "Player.h"

Player::Player(float speed) : Character(speed) {
    m_Sprite.setTexture(m_Texture);
    m_Position.x = 500;
    m_Position.y = 800;
}

void Player::moveLeft() {
    m_LeftPressed = true;
}

void Player::moveRight() {
    m_RightPressed = true;
}

void Player::stopLeft() {
    m_LeftPressed = false;
}

void Player::stopRight() {
    m_RightPressed = false;
}

void Player::moveTop() {
    m_TopPressed = true;
}

void Player::stopTop() {
    m_TopPressed = false;
}

void Player::moveDown() {
    m_DownPressed = true;
}

void Player::stopDown() {
    m_DownPressed = false;
}

void Player::update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight) {
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_TopPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }

    // Limiter le joueur à l'intérieur de la fenêtre
    if (m_Position.x < 0) {
        m_Position.x = 0;
    }
    if (m_Position.x + m_Sprite.getGlobalBounds().width > windowWidth) {
        m_Position.x = windowWidth - m_Sprite.getGlobalBounds().width;
    }
    if (m_Position.y < 0) {
        m_Position.y = 0;
    }
    if (m_Position.y + m_Sprite.getGlobalBounds().height > windowHeight) {
        m_Position.y = windowHeight - m_Sprite.getGlobalBounds().height;
    }

    m_Sprite.setPosition(m_Position);
}
