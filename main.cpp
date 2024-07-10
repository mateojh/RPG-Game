#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Movement.hpp"
sf::Clock PlayerClock;
sf::Clock EnemyClock;
sf::Text text;
int main()
{

    Player player1("Mateo", Mage, 100);
    Enemy* enemy1 = new Enemy("enemy1",Mage);

    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // loading textures
    sf::Texture playerTexture;
    sf::Sprite character;


    if(playerTexture.loadFromFile("assests/Players/Textures/EnemyMage.png"))
    {
        std::cout << "Player image Loaded!" << std::endl;
        character.setTexture(playerTexture);
    }
    else
    {
       std::cout << "Player image failed to load!" << std::endl;
    }

    sf::Texture enemyTexture;
    sf::Sprite enemy;


    if(enemyTexture.loadFromFile("assests/Players/Textures/Enemy1.png"))
    {
        std::cout << "Player image Loaded!" << std::endl;
        enemy.setTexture(enemyTexture);
    }
    else
    {
       std::cout << "Player image failed to load!" << std::endl;
    }
    
    enemy.setPosition(200,500);
    character.setPosition(100,200);
   

    enemy1->setSprite(enemy);
    player1.setSprite(character);

    sf::Vector2u size =  player1.getSprite()->getTexture()->getSize();
    std::cout << size.x << " " << size.y << std::endl;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        // events section
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
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
            bool click_lock = false;
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && click_lock != true )
            {
                
                Player copy("Copy", player1.getType(), player1.getMana());
                sf::Sprite copySprite = *player1.getSprite();
                copy.setSprite(copySprite);

                copy.getSprite()->move(1.f, 0.f);

                if(Movement::entityToEntity(copy,enemy1) && PlayerClock.getElapsedTime().asMilliseconds() >= 500)
                {
                    player1.attack(player1,*enemy1);
                    text.setFillColor(sf::Color::Blue);
                    text.setScale(sf::Vector2f(100.f,100.f));
                    text.setString("Hit!");
                    cout << player1.getHealth() << endl;
                    cout << enemy1->getHealth() << endl;
                    PlayerClock.restart();
                }
                else 
                {

                }
                click_lock = true;
            }
            if(sf::Event::MouseButtonReleased)
            {
                click_lock = false;
            }
            if(enemy1->getSprite()->getScale() != sf::Vector2f(0.0f,0.0f))
            {
                Enemy copy("Copy", Mage);
                sf::Sprite copyEnemy = *enemy1->getSprite();
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

                if(Movement::entityToEntity(player1,&copy) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
                {
                    if(Movement::entityToEntity(player1,&copy) && EnemyClock.getElapsedTime().asMilliseconds() >= 1000)
                    {
                        text.setFillColor(sf::Color::Red);
                        text.setScale(sf::Vector2f(100.f,100.f));
                        text.setString("Hit!");
                        enemy1->attack(*enemy1,player1);
                        cout << player1.getHealth() << endl;
                        cout << enemy1->getHealth() << endl;
                        EnemyClock.restart();
                    }
                }
                else 
                {
                    if(copy.getSprite()->getPosition().x < player1.getSprite()->getPosition().x)
                    {
                        enemy1->getSprite()->move(.1f, 0.f);
                    }
                    else if(copy.getSprite()->getPosition().x > player1.getSprite()->getPosition().x)
                    {
                        enemy1->getSprite()->move(-.1f, 0.f);
                    }

                    if(copy.getSprite()->getPosition().y < player1.getSprite()->getPosition().y)
                    {
                        enemy1->getSprite()->move(0.f, .1f);
                    }
                    else if(copy.getSprite()->getPosition().y > player1.getSprite()->getPosition().y)
                    {
                        enemy1->getSprite()->move(0.f, -.1f);
                    }
                }
            }
            
        
        // clear the window with black color
        // draw section
        window.clear(sf::Color::Black);

        window.draw(*player1.getSprite());

        if(enemy1->getHealth() > 0)
        {
            window.draw(*enemy1->getSprite());
        }
        else
        {
            enemy1->getSprite()->setScale(0.0f,0.0f);
        }

        if(player1.getHealth() > 0)
        {
            window.draw(*player1.getSprite());
        }
        else
        {
            player1.getSprite()->setScale(0.0f,0.0f);
        }
        window.draw(text);
        window.display();
    }

    return 0;
}