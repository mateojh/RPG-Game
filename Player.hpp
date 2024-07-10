#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>


class Player : public Entity
{
public:

    Player(std::string userName, Type chosenType, int mana): Entity(userName,chosenType), playerMana(mana)
    {
        setDamage(7);
    };

    int getMana() const;
    void setMana(int updatedMana);

private:
    int playerMana;
};

#endif