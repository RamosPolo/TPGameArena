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
    std::vector<float> angle;
    Sprite b_Sprite;
    Texture b_Texture;
public:
    Bullet();
    Sprite getSprite();
    void setPosition(float x, float y);
    void move(float elapsedTime);
};



#endif //BULLET_H
