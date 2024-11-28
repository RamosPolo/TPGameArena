#include <vector>
#include "SpawnerMonster.h"


SpawnerMonster::SpawnerMonster(){
    s_golemGlaceTexture.loadFromFile("./assets/image/Golem/Glace.png");
    s_golemFeuTexture.loadFromFile("./assets/image/Golem/Feu.png");
    s_golemTerreTexture.loadFromFile("./assets/image/Golem/Terre.png");
}

std::vector<Monster> SpawnerMonster::generateWave(int niveau){
    s_monsterList.clear();
    if(niveau < 10){
        generateGolem(niveau);
    }
    return s_monsterList;
}

void SpawnerMonster::generateGolem(int nbGolem){
    float vitesse = nbGolem*50.f;
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(vitesse, s_golemGlaceTexture, 30+(i*15), 0.2f+(i*0.1f));
        s_monsterList.push_back(*monster);
    }
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(vitesse, s_golemFeuTexture, 30+(i*15), 0.2f+(i*0.1f));
        s_monsterList.push_back(*monster);
    }
    for (int i = 0; i < nbGolem; ++i) {
        Monster* monster = new Monster(vitesse, s_golemTerreTexture, 30+(i*15), 0.2f+(i*0.1f));
        s_monsterList.push_back(*monster);
    }
}



