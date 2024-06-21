#include "Enemy.hpp"

Enemy::Enemy(std::string userName, Type chosenType) : Entity(userName,chosenType)
{
    setDamage(5);
}

