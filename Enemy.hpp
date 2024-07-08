#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.hpp"
#include <iostream>

using namespace std;

class Enemy : public Entity
{
    public:

    Enemy(std::string userName, Type chosenType);
};
 
#endif