#include "Character.h"

Character::Character(float speed, int life)
    : m_Speed(speed), m_life(life), m_Position(0, 0), m_IsFacingRight(true) {
    this->getSprite()->setTexture(getDefaultTexture());
}

float Character::getPositionX() const {
    return m_Position.x;
}

float Character::getPositionY() const {
    return m_Position.y;
}

int Character::getLife() const {
    return m_life;
}

void Character::setTexture(const Texture& texture) {
    m_Texture = texture;
    this->getSprite()->setTexture(m_Texture);
}

const Texture& Character::getDefaultTexture() {
    static Texture defaultTexture;
    static bool isLoaded = false;
    if (!isLoaded) {
        if (!defaultTexture.loadFromFile("../assets/image/Wraith.png")) {
            std::cerr << "Erreur : Impossible de charger la texture par défaut." << std::endl;
        }
        isLoaded = true;
    }
    return defaultTexture;
}

void Character::setLife(int nb) {
    this->m_life = nb;
}

void Character::getDemage(int nb) {
    this->setLife(this->getLife() - nb);
}

Sprite* Character::getSpriteC()  {
    return this->getSprite();
}

int Character::getSpriteHeight() const  {
    return m_Sprite->getGlobalBounds().height;
}

int Character::getSpriteWidth() const{
    return m_Sprite->getGlobalBounds().width;
}

void Character::moveLeft() { m_LeftPressed = true; }
void Character::moveRight() { m_RightPressed = true; }
void Character::stopLeft() { m_LeftPressed = false; }
void Character::stopRight() { m_RightPressed = false; }
void Character::moveTop() { m_TopPressed = true; }
void Character::stopTop() { m_TopPressed = false; }
void Character::moveDown() { m_DownPressed = true; }
void Character::stopDown() { m_DownPressed = false; }
