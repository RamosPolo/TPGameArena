#include "Player.h"
#include <vector>
#include <iostream>
#include "Player.h"

Player::Player(float speed, int life)
    : Character(speed, life) {
    if (!m_Texture.loadFromFile("./assets/image/Wraith/Walking.png")) {
        std::cerr << "Erreur : Impossible de charger le sprite sheet !" << std::endl;
    }

    m_FrameWidth = 520;
    m_FrameHeight = 420;
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setTextureRect(IntRect(10, 10, m_FrameWidth, m_FrameHeight));
    m_Sprite.setScale(0.5f, 0.5f);
    m_Position = {500, 800};
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

void Player::updateSprite() {
    if (m_LeftPressed || m_RightPressed || m_TopPressed || m_DownPressed) {
        m_CurrentFrame = (m_CurrentFrame + 1) % 12;
        int column = m_CurrentFrame % 4;
        int row = m_CurrentFrame / 4;
        int x = 10 + column * 540;
        int y = 10 + row * 440;
        m_Sprite.setTextureRect(IntRect(x, y, 520, 420));
    }

    if (m_RightPressed && !m_IsFacingRight) {
        m_IsFacingRight = true;
        m_Sprite.setScale(0.5f, 0.5f);
        m_Sprite.setOrigin(0, 0);
    } else if (m_LeftPressed && m_IsFacingRight) {
        m_IsFacingRight = false;
        m_Sprite.setScale(-0.5f, 0.5f);
        m_Sprite.setOrigin(520, 0);
    }
}

