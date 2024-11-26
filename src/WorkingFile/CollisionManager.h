//
// Created by PC on 26/11/2024.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;


class CollisionManager {
private:
    std::vector<Sprite*> objects;
public:
    CollisionManager();
    void AddObject(Sprite* obj);
    // renvoie une liste de paires de Sprites
    std::vector<std::pair<Sprite*, Sprite*>> CheckCollision();
    void handleCollisions();

};



#endif //COLLISIONMANAGER_H
