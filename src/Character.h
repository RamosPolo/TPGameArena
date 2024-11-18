#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

using namespace sf;

#include <iostream>

class Character {

private:

    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_TopPressed;
    bool m_DownPressed;

 
    float m_Speed;

public:
    // We will set Bob up in the constructor
    Character();
 
    Sprite getSprite();
 
    void moveLeft();
 
    void moveRight();
 
    void stopLeft();
 
    void stopRight();

    void moveTop();

    void stopTop();

    void moveDown();

    void stopDown();
 
    // We will call this function once every frame
    void update(float elapsedTime);
};

#endif
