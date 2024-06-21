#include "Movement.hpp"
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

bool Movement::entityToBounds(Player &entity1, int xBound, int yBound)
{
    sf::Vector2f spritePosition = entity1.getSprite()->getPosition();
    float x = spritePosition.x;
    float y = spritePosition.y;

    if(x < 0)
    {
        return true;
    }
    if(x > xBound - entity1.getSprite()->getGlobalBounds().width)
    {
        return true;
    }
    if(y < 0)
    {
        return true;
    }
    if(y > yBound - entity1.getSprite()->getGlobalBounds().height)
    {
        return true;
    }
    return false;
}

bool Movement::entityToEntity(Player &entity1, Enemy &entity2)
{

    if(entity1.getSprite()->getGlobalBounds().intersects(entity2.getSprite()->getGlobalBounds()))
    {
        return true;
    }
    return false;
}