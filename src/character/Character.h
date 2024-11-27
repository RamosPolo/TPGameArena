#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../GameObject.h"

using namespace sf;

class Character : public GameObject {
protected:
    float m_Speed = 0.f;
    int m_life = 0;
    Vector2f m_Position;
    //Sprite m_Sprite;
    Texture m_Texture;

    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;

    int m_CurrentFrame = 0;
    int m_FrameWidth = 0;
    int m_FrameHeight = 0;
    bool m_IsFacingRight = true;

    static const Texture& getDefaultTexture();

public:
    Character(float speed, int life);

    // Accesseurs
    //Sprite* getSprite();
    float getPositionX() const;
    float getPositionY() const;
    void setTexture(const Texture& texture);
    int getLife() const;

    // Mouvement générique
    virtual void updateSprite() = 0;

    // Mouvement : gestion des états
    virtual void moveLeft();
    virtual void moveRight();
    virtual void stopLeft();
    virtual void stopRight();
    virtual void moveTop();
    virtual void stopTop();
    virtual void moveDown();
    virtual void stopDown();
};

#endif
