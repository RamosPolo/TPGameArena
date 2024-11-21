#include "Character.h"

Character::Character(float speed) : 
    m_Position(), 
    m_Sprite(), 
    m_Texture(), 
    m_LeftPressed(false), 
    m_RightPressed(false),
    m_TopPressed(false), 
    m_DownPressed(false), 
    m_Speed(speed),
    m_IsFacingRight(true)
{
    m_Position.x = 0;
    m_Position.y = 0;
}


Sprite Character::getSprite() {
    return m_Sprite;
}

float Character::getPositionX() {
    return m_Position.x;
}
float Character::getPositionY() {
    return m_Position.y;
}

void Character::updateSprite() {
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
