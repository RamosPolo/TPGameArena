//
// Created by PC on 21/11/2024.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Obstacle {
    protected:
    Sprite O_sprite;
    Texture O_Texture;
    Vector2f O_position;

public:
    Obstacle();
    void setPosition(float x, float y);
    Sprite getSprite();
    void setSize(float largeur, float longeur);
};



#endif //OBSTACLE_H
