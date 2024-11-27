//
// Created by PC on 26/11/2024.
//

#include "GameObject.h"

GameObject::GameObject() = default;

String GameObject::getType() {
    return this->type;
}

void GameObject::setType(const String& t) {
    this->type = t;
}

Sprite *GameObject::getSprite() {
    return &this->o_sprite;
}

void GameObject::setSprite(Sprite *s) {
    this->o_sprite = *s;
}

