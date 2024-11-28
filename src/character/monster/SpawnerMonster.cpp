#include <vector>
#include "SpawnerMonster.h"


SpawnerMonster::SpawnerMonster(){
    s_golemTexture.loadFromFile("./assets/image/Golem/Walking.png");
}

std::vector<Monster> SpawnerMonster::generateWave(int niveau){
    if(niveau == 1){
        generateGolem(4);
    }
    if(niveau == 2){
        generateGolem(7);
    }
    if(niveau == 3){
        generateGolem(10);
    }

    return s_monsterList;
}

void SpawnerMonster::generateGolem(int nbGolem){
    s_monsterList.clear();
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(100.f, s_golemTexture, 30);
        s_monsterList.push_back(*monster);
    }
}



