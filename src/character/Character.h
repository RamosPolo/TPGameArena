#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../GameObject.h"

using namespace sf;

class Character : public GameObject {
protected:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_TopPressed;
    bool m_DownPressed;
    float m_Speed;
    int m_CurrentFrame;
    bool m_IsFacingRight; 
    int m_FrameWidth;  
    int m_FrameHeight;
    int m_life;

public:
    // Constructeur de base, utilisé par les classes dérivées
    Character(float speed, int life);

    // Méthodes de contrôle du mouvement (à définir dans les classes dérivées)
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void stopLeft() = 0;
    virtual void stopRight() = 0;
    virtual void moveTop() = 0;
    virtual void stopTop() = 0;
    virtual void moveDown() = 0;
    virtual void stopDown() = 0;
    virtual float getPositionX();
    virtual float getPositionY();
    virtual void updateSprite() = 0;
    virtual void setTexture(const Texture& t);

    std::vector<std::string> m_Frames;  

    Sprite* getSprite();

    static const Texture& getDefaultTexture();

};

#endif
