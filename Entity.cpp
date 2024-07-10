#include <iostream>
#include "Entity.hpp"


Entity::Entity(std::string entityName, Type chosenType)
{
    name = entityName;
    entityClass = chosenType;
}

std::string Entity::getName() const
{
    return name;
}

int Entity::getLevel() const
{
    return level;
}
void Entity::setLevel(int updatedLevel)
{
    level = updatedLevel;
}

Type Entity::getType() const
{
    return entityClass;
}

int Entity::getHealth() const
{
    return health;
}
void Entity::setHealth(int updatedHealth)
{
    health = updatedHealth;
    std::cout << this->health << std::endl;
}

int Entity::getDamage() const
{
    return attackDmg;
}
void Entity::setDamage(int updatedDamage)
{
    attackDmg = updatedDamage;
}

void Entity::incrementLevel(Entity &character)
{
    character.setLevel(character.getLevel() + 1);
}
void Entity::incrementHealth(Entity &character, int increasedHealth)
{
    character.setHealth(character.getHealth() + increasedHealth);
}

void Entity::decrementHealth(Entity &character, int decreasedHealth)
{
    std::cout << decreasedHealth << std::endl;
    std::cout << character.getHealth() - decreasedHealth << std::endl;
    character.setHealth(character.getHealth() - decreasedHealth);
}

void Entity::attack(Entity &attacker, Entity &target)
{
    std::cout << attacker.getDamage() << std::endl;
    decrementHealth(target,attacker.getDamage());
}

sf::Sprite* Entity::getSprite ()
{
    return entitySprite;
}

void Entity::setSprite(sf::Sprite &updatedSprite)
{
    entitySprite = &updatedSprite;
}


