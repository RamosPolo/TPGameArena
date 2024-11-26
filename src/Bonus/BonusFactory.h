//
// Created by PC on 25/11/2024.
//

#ifndef BONUSFACTORY_H
#define BONUSFACTORY_H

#include "Bonus.h"


class BonusFactory {
    protected:
    Clock b_clock;
    public:
    BonusFactory();
    static Bonus createRandomBonus();
};



#endif //BONUSFACTORY_H
