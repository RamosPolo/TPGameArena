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
        generateGolem(1);
    }
    if(niveau == 2){
        generateGolem(2);
    }
    if(niveau == 3){
        generateGolem(3);
    } 
    if(niveau == 4){
        generateGolem(4);
    }

    return s_monsterList;
}

void SpawnerMonster::generateGolem(int nbGolem){
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(100.f, s_golemGlaceTexture, 30);
        s_monsterList.push_back(*monster);
    }
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(100.f, s_golemFeuTexture, 30);
        s_monsterList.push_back(*monster);
    }
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(100.f, s_golemTerreTexture, 30);
        s_monsterList.push_back(*monster);
    }
}



