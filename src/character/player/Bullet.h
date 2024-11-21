//
// Created by PC on 19/11/2024.
//

#ifndef BULLET_H
#define BULLET_H
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;


class Bullet {
private:
    Vector2f b_position;
    Vector2f b_target;
    std::vector<float> angle;
    Sprite b_Sprite;
    Texture b_Texture;
    float b_speed;
    Vector2f b_direction;
public:
    Bullet();
    Sprite getSprite();
    void setPosition(float x, float y);
    void move(float elapsedTime);
    void setTarget(float x, float y);
    bool isOutOfBounds(unsigned int windowWidth, unsigned int windowHeight) const;
};



#endif //BULLET_H
