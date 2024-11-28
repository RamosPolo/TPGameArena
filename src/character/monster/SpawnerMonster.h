#ifndef SPAWNERMONSTER_H
#define SPAWNERMONSTER_H

#include "./Monster.h"
#include <SFML/Graphics.hpp>

class SpawnerMonster {
private:

    int sm_niveau;
    std::vector<Monster> s_monsterList;
    sf::Texture s_golemTexture; 
    void generateGolem(int nbGolem);


public:
    SpawnerMonster();
    std::vector<Monster> generateWave(int niveau);
};

#endif