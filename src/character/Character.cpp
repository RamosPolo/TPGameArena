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
