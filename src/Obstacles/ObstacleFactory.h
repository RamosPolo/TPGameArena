//
// Created by PC on 21/11/2024.
//

#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Obstacle.h"


class ObstacleFactory {
private:
    int nbObstacle;
    std::vector<Obstacle> obstacles;
    public:
    ObstacleFactory();
    int getNbObstacles() const;
    std::vector<Obstacle> getObstacles() const;
    void generateObstacles();
    void addObstacle(const Obstacle& ob);
    void drawObstacles(RenderWindow& win);
};



#endif //OBSTACLEFACTORY_H
