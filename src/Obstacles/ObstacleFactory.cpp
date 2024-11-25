//
// Created by PC on 21/11/2024.
//

#include "ObstacleFactory.h"

#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

ObstacleFactory::ObstacleFactory() {
    nbObstacle = 0;
}

void ObstacleFactory::addObstacle(const Obstacle& ob) {
    obstacles.push_back(ob);
    nbObstacle++;
}

int ObstacleFactory::getNbObstacles() const {
    return nbObstacle;
}

std::vector<Obstacle> ObstacleFactory::getObstacles() const {
    return obstacles;
}

void ObstacleFactory::generateObstacles() {
    Obstacle obs1;
    obs1.setSize(5,2);
    obs1.setPosition(400,520);
    addObstacle(obs1);

    Obstacle obs2;
    obs2.setSize(2,5);
    obs2.setPosition(10,50);
    addObstacle(obs2);

    /*
    Obstacle obs3;
    obs3.setSize(7,2);
    obs3.setPosition(100,50);
    addObstacle(obs3);

    Obstacle obs4;
    obs4.setSize(6,8);
    obs4.setPosition(15,30);
    addObstacle(obs4);
    */
}

void ObstacleFactory::drawObstacles(RenderWindow& win) {
    generateObstacles();
    for(Obstacle obs : obstacles) {
        win.draw(obs.getSprite());
    }
}


