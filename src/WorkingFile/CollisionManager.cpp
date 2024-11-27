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
                // suprimer objects[i] et objects[j] du vecteur, en libérant la memoire
                collisions.emplace_back(objects[i].get(), objects[j].get());

                // Supprimer les objets du vecteur
                objects.erase(objects.begin() + j);
                objects.erase(objects.begin() + i);

                // Réduire les indices après suppression
                --i;
                break;
            }
        }
    }
    return collisions;
}

void CollisionManager::AddObject(GameObject *obj) {
    objects.push_back(std::unique_ptr<GameObject>(obj));
}

void CollisionManager::handleCollisions() {
    auto collisions = CheckCollision();

    for(auto& obj : collisions) {
        GameObject *obj1 = obj.first;
        GameObject *obj2 = obj.second;

        if(obj1->getType() == "bullet" && obj2->getType() == "monster") {
            std::cout << "Collision entre un projectile et on monstre" << std::endl;

        }
        if(obj1->getType() == "monster" && obj2->getType() == "player") {
            std::cout << "Collision entre un monster et on player" << std::endl;
        }
    }
}



