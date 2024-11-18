#include "Character.h"
 
Character::Character()
{
    // How fast does Character move?
    m_Speed = 400;
 
    // Associate a texture with the sprite
    m_Texture.loadFromFile("../assets/image/Character.png");
    m_Sprite.setTexture(m_Texture);
 
    // Set the Character's starting position
    m_Position.x = 500;
    m_Position.y = 800;
 
}
 
// Make the private spite available to the draw() function
Sprite Character::getSprite()
{
    return m_Sprite;
}
 
void Character::moveLeft()
{
    m_LeftPressed = true;
}
 
void Character::moveRight()
{
    m_RightPressed = true;
}
 
void Character::stopLeft()
{
    m_LeftPressed = false;
}
 
void Character::stopRight()
{
    m_RightPressed = false;
}

void Character::moveTop() {
    m_TopPressed = true;
}
void Character::stopTop() {
    m_TopPressed = false;
}

void Character::moveDown() {
    m_DownPressed = true;
}

void Character::stopDown() {
    m_DownPressed = false;

}
 
// Move Character based on the input this frame,
// the time elapsed, and the speed
void Character::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
 
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_TopPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }
 
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);   
 
}