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
        
        static bool entityToBounds(Entity &currentEntity, int x, int y);

        static bool entityToEntity(Player &entity1, Enemy &entity2);

        static void upMovement(Player &player1,Enemy &enemy2, sf::RenderWindow &window);
        static void leftMovement(Player &player1,Enemy &enemy2, sf::RenderWindow &window);
        static void downMovement(Player &player1,Enemy &enemy2, sf::RenderWindow &window);
        static void rightMovement(Player &player1,Enemy &enemy2, sf::RenderWindow &window);
        static void attack(Player &player1,Enemy &enemy1,sf::Clock PlayerClock, bool &click_Lock);
        static void enemyTracking(Player &player1, Enemy &enemy1, sf::RenderWindow &window, sf::Clock &EnemyClock);

};

#endif