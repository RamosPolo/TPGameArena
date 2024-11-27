//
// Created by PC on 19/11/2024.
//

#ifndef BULLET_H
#define BULLET_H
#include <vector>
#include <SFML/Graphics.hpp>

#include "../../GameObject.h"

using namespace sf;


class Bullet : public GameObject {
protected:
    Vector2f b_position;
    Vector2f b_target;
    std::vector<float> angle;
    Sprite b_Sprite;
    Texture b_Texture;
    float b_speed;
    Vector2f b_direction;
    int dammage;
public:
    Bullet();

    /*Sprite *getSprite();*/
    void setPosition(float x, float y);
    void move(float elapsedTime);
    void setTarget(float x, float y);
    bool isOutOfBounds(unsigned int windowWidth, unsigned int windowHeight) const;
    void setTextureBullet(const Texture &t);
};

// Type boule de feu
class FireBullet : public Bullet {
    protected:
    public:
        FireBullet();
};

// Type boule de glace
class SnowBullet : public Bullet {
    protected:
    public:
        SnowBullet();
};

#endif //BULLET_H
