#include "Entity.hpp"
#include "Player.hpp"
#include <iostream>


int Player::getMana() const
{
    return playerMana;
}
void Player::setMana(int updatedMana)
{
    playerMana = updatedMana;
}
