#include <SFML/Graphics.hpp>
#include <iostream>

bool validIndex(sf::Sprite& character)
{
    sf::Vector2f tempVec = character.getPosition();
    float x = tempVec.x;
    float y = tempVec.y;
    if(x < 0)
    {
        character.setPosition(sf::Vector2f(x+1, y));
        return false;
    }
    if(x > 800 - character.getGlobalBounds().width)
    {
        character.setPosition(sf::Vector2f(x-1, y));
        return false;
    }

    if(y < 0)
    {
        character.setPosition(sf::Vector2f(x, y+1));
        return false;
    }
    if(y > 600 - character.getGlobalBounds().height)
    {
        character.setPosition(sf::Vector2f(x, y-1));
        return false;
    }
    return true;
}

int main()
{
    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // loading textures
    sf::Texture playerTexture;
    sf::Sprite character;

    if(playerTexture.loadFromFile("C:\\Users\\mateo\\Documents\\Game1\\assests\\Players\\Textures\\Mock-Sprite.png"))
    {
        std::cout << "Player image Loaded!" << std::endl;
        character.setTexture(playerTexture);
    }
    else
    {
       std::cout << "Player image failed to load!" << std::endl;
    }
    
   
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
        if(validIndex(character))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                character.move(0.f, -1.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                character.move(-1.f, 0.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                character.move(0.f, 1.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                character.move(1.f, 0.f);
            }
        }
        

        // clear the window with black color
        // draw section
        window.clear(sf::Color::Black);
        window.draw(character);
        window.display();
    }

    return 0;
}