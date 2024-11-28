#include <vector>
#include "SpawnerMonster.h"


SpawnerMonster::SpawnerMonster(){
    s_golemGlaceTexture.loadFromFile("./assets/image/Golem/Glace.png");
    s_golemFeuTexture.loadFromFile("./assets/image/Golem/Feu.png");
    s_golemTerreTexture.loadFromFile("./assets/image/Golem/Terre.png");
}

std::vector<Monster> SpawnerMonster::generateWave(int niveau){
    s_monsterList.clear();
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
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(100.f, s_golemFeuTexture, 30);
        s_monsterList.push_back(*monster);
    }
}



