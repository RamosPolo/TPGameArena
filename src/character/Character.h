#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Character {
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

public:
    // Constructeur de base, utilisé par les classes dérivées
    Character(float speed = 400);

    // Méthode virtuelle pure qui devra être définie dans les classes dérivées
    virtual void update(float elapsedTime, unsigned int windowWidth, unsigned int windowHeight) = 0;

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

    std::vector<std::string> m_Frames;  

    Sprite getSprite();
};

#endif
