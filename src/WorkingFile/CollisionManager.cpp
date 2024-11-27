//
// Created by PC on 26/11/2024.
//
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() = default;

std::vector<std::pair<GameObject*, GameObject*> > CollisionManager::CheckCollision() {
    // liste des paires de collsions
    std::vector<std::pair<GameObject*, GameObject*>> collisions;

    for (std::size_t i = 0; i < objects.size(); i++) {
        for (std::size_t j = i; j < objects.size(); j++) {
            if(objects[i]->getSprite()->getGlobalBounds().intersects(objects[j]->getSprite()->getGlobalBounds())) {
                collisions.emplace_back(objects[i], objects[j]);
            }
        }
    }
    return collisions;
}

void CollisionManager::AddObject(GameObject *obj) {
    objects.push_back(obj);
}

void CollisionManager::handleCollisions() {
    auto collisions = CheckCollision();

    for(auto& obj : collisions) {
        //GameObject *obj1 = obj.first;
        //GameObject *obj2 = obj.second;

        // gérer les collisions ici entre les différents types
        std::cout << "Collision detected between objects!" << std::endl;

    }
}



