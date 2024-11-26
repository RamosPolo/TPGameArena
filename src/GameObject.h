//
// Created by PC on 26/11/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/String.hpp>


class GameObject {
private:
    sf::String type;
    public:
    GameObject();
    sf::String getType();
    void setType(const sf::String& type);

};



#endif //GAMEOBJECT_H
