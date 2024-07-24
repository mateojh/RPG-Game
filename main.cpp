#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Movement.hpp"
sf::Clock PlayerClock;
sf::Clock EnemyClock;
sf::Text text;
void drawingWindow(Player &player1, Enemy &enemy1, sf::RenderWindow &window);
void loadingTextures(sf::Texture &player1Texture, sf::Sprite &player1Sprite, sf::Texture &enemy1Texture, sf::Sprite &enemy1Sprite);
int main()
{

    Player player1("Mateo", Mage, 100);
    Enemy enemy1("enemy1",Mage);

    vector <Player> players;
    vector <Enemy> enemies;

    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // loading textures
    sf::Texture player1Texture;
    sf::Sprite player1Sprite;

    
    sf::Texture enemy1Texture;
    sf::Sprite enemy1Sprite;

    loadingTextures(player1Texture,player1Sprite,enemy1Texture,enemy1Sprite);

    player1Sprite.setPosition(100,200);
    enemy1Sprite.setPosition(200,500);
   
    enemy1.setSprite(enemy1Sprite);
    player1.setSprite(player1Sprite);

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
        Movement::upMovement(player1,enemy1,window);

        Movement::leftMovement(player1,enemy1,window);

        Movement::downMovement(player1,enemy1,window);

        Movement::rightMovement(player1,enemy1,window);

        bool click_lock = false;

        Movement::attack(player1,enemy1,PlayerClock,click_lock);

        if(sf::Event::MouseButtonReleased)
        {
            click_lock = false;
        }
        Movement::enemyTracking(player1,enemy1,window,EnemyClock);
        
        // clear the window with black color
        // draw section
        drawingWindow(player1,enemy1,window);
       
    }

    return 0;
}

void drawingWindow(Player &player1, Enemy &enemy1, sf::RenderWindow &window)
{
     window.clear(sf::Color::Black);

        window.draw(*player1.getSprite());

        if(enemy1.getHealth() > 0)
        {
            window.draw(*enemy1.getSprite());
        }
        else
        {
            enemy1.getSprite()->setScale(0.0f,0.0f);
        }

        if(player1.getHealth() > 0)
        {
            window.draw(*player1.getSprite());
        }
        else
        {
            sf::Vector2f dimentions = player1.getSprite()->getScale();
            player1.setHealth(50);
            player1.getSprite()->setScale(0.0f,0.0f);
            player1.getSprite()->setPosition(100,200);
            enemy1.getSprite()->setPosition(200,500);
            player1.getSprite()->setScale(dimentions);
        }
        window.display();
}

void loadingTextures(sf::Texture &player1Texture, sf::Sprite &player1Sprite, sf::Texture &enemy1Texture, sf::Sprite &enemy1Sprite)
{
    if(player1Texture.loadFromFile("assests/Players/Textures/EnemyMage.png"))
    {
        std::cout << "Player image Loaded!" << std::endl;
        player1Sprite.setTexture(player1Texture);
    }
    else
    {
       std::cout << "Player image failed to load!" << std::endl;
    }

    if(enemy1Texture.loadFromFile("assests/Players/Textures/Enemy1.png"))
    {
        std::cout << "Player image Loaded!" << std::endl;
        enemy1Sprite.setTexture(enemy1Texture);
    }
    else
    {
       std::cout << "Player image failed to load!" << std::endl;
    }
}