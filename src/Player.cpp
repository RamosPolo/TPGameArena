#include "Player.h"

Player::Player(float speed) : Character(speed) {
    m_Texture.loadFromFile("./assets/image/Character.png");
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

void Player::update(float elapsedTime) {
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

    m_Sprite.setPosition(m_Position);
}
