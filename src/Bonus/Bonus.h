//
// Created by PC on 25/11/2024.
//

#ifndef BONUS_H
#define BONUS_H
#include <SFML/Graphics.hpp>

#include "../GameObject.h"

using namespace sf;


class Bonus : public GameObject {
    protected:
        Vector2f b_position;
        //Sprite b_Sprite;
        Texture b_Texture;
        String bonustype;
    public:
    Bonus();

        void setPosition(Vector2f v);

        //Sprite *getSprite();
        void setTextureBonus(const Texture &t);
        String getTypeBonus();

};

class FireBonus : public Bonus {
    public:
    FireBonus();
};

class SnowBonus : public Bonus {
    public:
    SnowBonus();
};


#endif //BONUS_H
