//
// Created by PC on 26/11/2024.
//

#include "GameObject.h"

GameObject::GameObject() = default;

sf::String GameObject::getType() {
    return this->type;
}

void GameObject::setType(const sf::String& t) {
    this->type = t;
}

