//
// Created by PC on 26/11/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>

using namespace sf;

class GameObject {
protected:
    Sprite o_sprite;
    // types différents :
    // - monster (ennemies)
    // - player
    // - bullet (projectiles)
    String type;
    bool destroyed = false;
    public:
    GameObject();
    String getType();
    void setType(const String& type);
    Sprite *getSprite();
    void setSprite(Sprite *sprite);
    void destroy();
    bool isDestroyed() const;
};



#endif //GAMEOBJECT_H
