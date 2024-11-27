#ifndef BARVIE_H
#define BARVIE_H

#include <SFML/Graphics.hpp>
#include "Character.h"
using namespace sf;

class Barvie {
protected:
    RectangleShape b_rec;
    Vector2f b_position;
    int b_vie;
    Text b_text;
    Font b_font;

public:
    Barvie(const Character& c);

    RectangleShape getRectangle();

    void update(const Character& c);
};

#endif
