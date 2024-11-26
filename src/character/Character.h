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
    Character();

    // Méthodes de contrôle du mouvement (à définir dans les classes dérivées)

    std::vector<std::string> m_Frames;  

    Sprite* getSprite();

    float getPositionX();

    float getPositionY();

    void setTexture(const Texture &texture);

    static const Texture& getDefaultTexture();

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void moveTop();

    void stopTop();

    void moveDown();

    void stopDown();
};

#endif
