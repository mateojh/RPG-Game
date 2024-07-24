#include "Movement.hpp"
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "iostream"

using namespace std;

bool Movement::entityToBounds(Entity &entity1, int xBound, int yBound)
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

    if((entity1.getSprite()->getGlobalBounds().intersects(entity2.getSprite()->getGlobalBounds())))
    {
        return true;
    }
    return false;
}

void Movement::upMovement(Player &player1,Enemy &enemy1, sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Player copy("Copy", player1.getType(), player1.getMana());
        sf::Sprite copySprite = *player1.getSprite();
        copy.setSprite(copySprite);

        copy.getSprite()->move(0.f, -1.f);

        if(Movement::entityToEntity(copy,enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
        {

        }
        else 
        {
            player1.getSprite()->move(0.f, -1.f);
        }
    }
}
void Movement::leftMovement(Player &player1,Enemy &enemy1, sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Player copy("Copy", player1.getType(), player1.getMana());
        sf::Sprite copySprite = *player1.getSprite();
        copy.setSprite(copySprite);

        copy.getSprite()->move(-1.f, 0.f);

        if(Movement::entityToEntity(copy,enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
        {
        }
        else 
        {
            player1.getSprite()->move(-1.f, 0.f);
        }
    }
}
void Movement::downMovement(Player &player1,Enemy &enemy1, sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Player copy("Copy", player1.getType(), player1.getMana());
        sf::Sprite copySprite = *player1.getSprite();
        copy.setSprite(copySprite);

        copy.getSprite()->move(0.f, 1.f);

        if(Movement::entityToEntity(copy,enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
        {
        }
        else 
        {
            player1.getSprite()->move(0.f, 1.f);
        }
    }
}
void Movement::rightMovement(Player &player1,Enemy &enemy1, sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Player copy("Copy", player1.getType(), player1.getMana());
        sf::Sprite copySprite = *player1.getSprite();
        copy.setSprite(copySprite);

        copy.getSprite()->move(1.f, 0.f);

        if(Movement::entityToEntity(copy,enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
        {
        }
        else 
        {
            player1.getSprite()->move(1.f, 0.f);
        }
    }
}

void Movement::attack(Player &player1,Enemy &enemy1,sf::Clock PlayerClock, bool &click_lock)
{
    click_lock = false;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && click_lock != true )
        {
            
            Player copy("Copy", player1.getType(), player1.getMana());
            sf::Sprite copySprite = *player1.getSprite();
            copy.setSprite(copySprite);

            copy.getSprite()->move(1.f, 0.f);

            if(Movement::entityToEntity(copy,enemy1) && PlayerClock.getElapsedTime().asMilliseconds() >= 500)
            {
                player1.attack(player1,enemy1);
                cout << player1.getHealth() << endl;
                cout << enemy1.getHealth() << endl;
                PlayerClock.restart();
            }
            else 
            {
                click_lock = true;
            }
            
        }
}

void Movement::enemyTracking(Player &player1, Enemy &enemy1, sf::RenderWindow &window, sf::Clock &EnemyClock)
{
    if(enemy1.getSprite()->getScale() != sf::Vector2f(0.0f,0.0f))
        {
            Enemy copy("Copy", Mage);
            sf::Sprite copyEnemy = *enemy1.getSprite();
            copy.setSprite(copyEnemy);

            if(copy.getSprite()->getPosition().x < player1.getSprite()->getPosition().x)
            {
                copy.getSprite()->move(1.f, 0.f);
            }
            else if(copy.getSprite()->getPosition().x > player1.getSprite()->getPosition().x)
            {
                copy.getSprite()->move(-1.f, 0.f);
            }

            if(copy.getSprite()->getPosition().y < player1.getSprite()->getPosition().y)
            {
                copy.getSprite()->move(0.f, 1.f);
            }
            else if(copy.getSprite()->getPosition().y > player1.getSprite()->getPosition().y)
            {
                copy.getSprite()->move(0.f, -1.f);
            }

            if(Movement::entityToEntity(player1,copy) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
            {
                if(Movement::entityToEntity(player1,copy) && EnemyClock.getElapsedTime().asMilliseconds() >= 1000)
                {
                    enemy1.attack(enemy1,player1);
                    cout << player1.getHealth() << endl;
                    cout << enemy1.getHealth() << endl;
                    EnemyClock.restart();
                }
            }
            else 
            {
                if(copy.getSprite()->getPosition().x < player1.getSprite()->getPosition().x)
                {
                    enemy1.getSprite()->move(.1f, 0.f);
                }
                else if(copy.getSprite()->getPosition().x > player1.getSprite()->getPosition().x)
                {
                    enemy1.getSprite()->move(-.1f, 0.f);
                }

                if(copy.getSprite()->getPosition().y < player1.getSprite()->getPosition().y)
                {
                    enemy1.getSprite()->move(0.f, .1f);
                }
                else if(copy.getSprite()->getPosition().y > player1.getSprite()->getPosition().y)
                {
                    enemy1.getSprite()->move(0.f, -.1f);
                }
            }
        }
}