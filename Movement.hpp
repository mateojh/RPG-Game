#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

using namespace std;


class Movement {
    public:
        
        static bool entityToBounds(Player &currentEntity, int x, int y);
    

        static bool entityToEntity(Player &entity1, Enemy &entity2);

};

#endif