//
// Created by PC on 26/11/2024.
//
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() = default;

std::vector<std::pair<Sprite *, Sprite *> > CollisionManager::CheckCollision() {
    // liste des paires de collsions
    std::vector<std::pair<Sprite*, Sprite*>> collisions;

    for(int i=0; i < objects.size(); i++) {
        for(int j=i; j < objects.size(); j++) {
            if(objects[i]->getGlobalBounds().intersects(objects[j]->getGlobalBounds())) {
                collisions.emplace_back(objects[i], objects[j]);
            }
        }
    }
    return collisions;
}

void CollisionManager::AddObject(Sprite *obj) {
    objects.push_back(obj);
}

void CollisionManager::handleCollisions() {
    auto collisions = CheckCollision();

    for(auto& obj : collisions) {
        Sprite *obj1 = obj.first;
        Sprite *obj2 = obj.second;

        // gérer les collisions ici entre les différents types
        std::cout << "Collision detected between objects!" << std::endl;

    }
}



