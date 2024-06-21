#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>


enum Type 
{
    Mage = 1,
    Assassin = 2,
    Tank = 3,
};

class Movement;

class Entity {
    public:
        Entity(std::string entityName, Type chosenType);
        std::string getName() const;

        int getLevel() const;
       
        void setLevel(int updatedLevel);
        
        
        Type getType() const;
        
        int getHealth() const;
       
        void setHealth(int updatedHealth);
       
        int getDamage() const;
       
        void setDamage(int updatedDamage);

        void incrementLevel(Entity &character);

        void incrementHealth(Entity &character, int increasedHealth);


        void decrementHealth(Entity &character, int decreasedHealth);


        void attack(Entity &attacker, Entity &target);
        sf::Sprite* getSprite();
        void setSprite(sf::Sprite &updatedSprite);


    private:
        std::string name;
        int level = 1;
        int health = 50;
        int attackDmg;
        Type entityClass;
        friend class Movement;
        sf::Sprite *entitySprite;
        sf::Texture entityTexture;    
};

#endif