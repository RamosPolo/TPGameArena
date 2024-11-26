#include "Character.h"

Character::Character()
{
    m_LeftPressed = false;
    m_RightPressed = false;
    m_TopPressed = false; 
    m_DownPressed = false; 
    m_Position.x = 0;
    m_Position.y = 0;
    m_IsFacingRight = true;
}


Sprite* Character::getSprite() {
    return &m_Sprite;
}

float Character::getPositionX() {
    return m_Position.x;
}
float Character::getPositionY() {
    return m_Position.y;
}

void Character::setTexture(const Texture& texture) {
    m_Texture = texture;
    m_Sprite.setTexture(m_Texture);
}

const Texture& Character::getDefaultTexture() {
    static Texture defaultTexture;
    static bool isLoaded = false;
    if (!isLoaded) {
        if (!defaultTexture.loadFromFile("./assets/image/default.png")) {
            std::cerr << "Erreur : Impossible de charger la texture par défaut." << std::endl;
        }
        isLoaded = true;
    }
    return defaultTexture;
}