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
    Obstacle(float x, float y);
};



#endif //OBSTACLE_H
