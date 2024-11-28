//
// Created by PC on 25/11/2024.
//

#include "BonusFactory.h"
#include <memory>

BonusFactory::BonusFactory() = default;

Bonus BonusFactory::createRandomBonus() {
    const int bonusType = rand() % 3;
    if (bonusType == 0) {
        return SnowBonus();
    }
    if(bonusType == 1) {
        return FireBonus();
    }
    if(bonusType == 2) {
        return DefaultBonus();
    }
    else {
        printf("############ Erreur de boucle BonusFactory->createRandomBonus\n");
        return DefaultBonus();
    }
}