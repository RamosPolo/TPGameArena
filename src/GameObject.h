//
// Created by PC on 26/11/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>

using namespace sf;

class GameObject {
private:
    Sprite o_sprite;
    String type;
    public:
    GameObject();
    String getType();
    void setType(const String& type);
    Sprite *getSprite();
    void setSprite(Sprite *sprite);

};



#endif //GAMEOBJECT_H
