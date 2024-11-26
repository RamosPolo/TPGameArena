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
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > 0) {
        deltaX /= distance;
        deltaY /= distance;
        m_Position.x += deltaX * m_Speed * elapsedTime;
        m_Position.y += deltaY * m_Speed * elapsedTime;
    }

    updateSprite();
    m_Sprite.setPosition(m_Position);
}

void Monster::updateSprite() {
    m_CurrentFrame = (m_CurrentFrame + 1) % 23;
    int column = m_CurrentFrame % 5;
    int row = m_CurrentFrame / 5;
    m_Sprite.setTextureRect(sf::IntRect(column * 930, row * 930, 930, 930));

    // Modifier la direction du monstre en fonction de sa position
    m_Sprite.setScale(m_RightPressed ? 0.3f : -0.3f, 0.3f);
}
