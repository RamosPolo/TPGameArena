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
        Texture b_Texture;
        String bonustype;
    public:
    Bonus();
        void setPos(float x, float y);
        void setTextureBonus(const Texture &t);
        String getTypeBonus();

        void positionnerBonus(int WinWidth, int WinHeight);
};

class FireBonus : public Bonus {
    public:
    FireBonus();
};

class SnowBonus : public Bonus {
    public:
    SnowBonus();
};

class DefaultBonus : public Bonus {
public:
    DefaultBonus();
};


#endif //BONUS_H
