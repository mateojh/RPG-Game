#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Movement.hpp"


int main()
{

    Player player1("Mateo", Mage, 100);
    Enemy* enemy1 = new Enemy("enemy1",Mage);

    cout << player1.getHealth() << endl;
    cout << enemy1->getHealth() << endl;

    cout << player1.getDamage() << endl;
    cout << enemy1->getDamage() << endl;

    player1.attack(player1,*enemy1);

    cout << player1.getHealth() << endl;
    cout << enemy1->getHealth() << endl;
    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // loading textures
    sf::Texture playerTexture;
    sf::Sprite character;


    if(playerTexture.loadFromFile("assests/Players/Textures/Mock-Sprite.png"))
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

                if(Movement::entityToEntity(copy,*enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
                {
                    cout << " No movement"<< endl;
                }
                else 
                {
                    cout << "movement"<< endl;
                    player1.getSprite()->move(0.f, -1.f);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                Player copy("Copy", player1.getType(), player1.getMana());
                sf::Sprite copySprite = *player1.getSprite();
                copy.setSprite(copySprite);

                copy.getSprite()->move(-1.f, 0.f);

                if(Movement::entityToEntity(copy,*enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
                {
                    cout << " No movement"<< endl;
                }
                else 
                {
                    cout << "movement"<< endl;
                    player1.getSprite()->move(-1.f, 0.f);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                Player copy("Copy", player1.getType(), player1.getMana());
                sf::Sprite copySprite = *player1.getSprite();
                copy.setSprite(copySprite);

                copy.getSprite()->move(0.f, 1.f);

                if(Movement::entityToEntity(copy,*enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
                {
                    cout << " No movement"<< endl;
                }
                else 
                {
                    cout << "movement"<< endl;
                    player1.getSprite()->move(0.f, 1.f);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                Player copy("Copy", player1.getType(), player1.getMana());
                sf::Sprite copySprite = *player1.getSprite();
                copy.setSprite(copySprite);

                copy.getSprite()->move(1.f, 0.f);

                if(Movement::entityToEntity(copy,*enemy1) || Movement::entityToBounds(copy,window.getSize().x,window.getSize().y))
                {
                    cout << " No movement"<< endl;
                }
                else 
                {
                    cout << "movement"<< endl;
                    player1.getSprite()->move(1.f, 0.f);
                }
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Player copy("Copy", player1.getType(), player1.getMana());
                sf::Sprite copySprite = *player1.getSprite();
                copy.setSprite(copySprite);

                copy.getSprite()->move(1.f, 0.f);

                if(Movement::entityToEntity(copy,*enemy1))
                {
                    player1.attack(player1,*enemy1);
                    cout << player1.getHealth() << endl;
                    cout << enemy1->getHealth() << endl;
                }
                else 
                {
                    cout << "missssss" << endl;
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
            window.clear(sf::Color::Black);
            window.draw(*player1.getSprite());
        }

        window.display();
    }

    return 0;
}