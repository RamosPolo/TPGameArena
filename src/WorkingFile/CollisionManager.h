//
// Created by PC on 26/11/2024.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../GameObject.h"

using namespace sf;


class CollisionManager {
private:
    std::vector<std::unique_ptr<GameObject>> objects;
public:
    CollisionManager();
    void AddObject(GameObject* obj);
    // renvoie une liste de paires de Sprites
    std::vector<std::pair<GameObject*, GameObject*>> CheckCollision();
    void handleCollisions();

    int getSpriteHeight() const;
    int getSpriteWidth() const;



};



#endif //COLLISIONMANAGER_H
