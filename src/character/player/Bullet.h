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
    Texture b_Texture;
    float b_speed;
    Vector2f b_direction;
    String b_type;
    int dammage;
public:
    Bullet();
    String getTypeBullet();
    void setPosition(float x, float y);

    void move(float elapsedTime);
    void setTarget(float x, float y);

    bool isOutOfBounds(unsigned int windowWidth, unsigned int windowHeight);

    int demage() const;

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

class DefaultBullet : public Bullet {
    protected:
    public:
    DefaultBullet();
};

#endif //BULLET_H
