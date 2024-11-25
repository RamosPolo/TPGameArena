//
// Created by PC on 25/11/2024.
//

#include "BonusFactory.h"
#include <memory>

BonusFactory::BonusFactory() {

}

Bonus BonusFactory::createRandomBonus() {
    int bonusType  = rand()%2   +0;
    if (bonusType == 0) {
        return SnowBonus();
    }
    if(bonusType == 1) {
        return FireBonus();
    } else {
        return Bonus();
    }
}