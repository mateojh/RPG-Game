# RPG-Game
This project is a 2D-Adventure RPG that uses c++ and SFML. 

## Game Setup
1. In order to run the game, You must pull from this project into an IDE and download C++. 

1. Download SFML and the mingw32 compiler on SFML's website (https://www.sfml-dev.org/download/sfml/2.6.1/). 

1. Follow the instructions given on the website and ensure that both the mingw compiler and SFML are added as paths on your computer.

1. Restart your IDE. 

## Dependencies and Compiling Notes
 
Currently the dependencies include an outside texture linked here (https://github.com/mateojh/Project-Game-1/assets/158978579/4491bbca-7207-4e22-aaaa-26e46217668b). 
 
### Compiling and running the code is as follows: 

#### Windows:
g++ -I"File path to SFML include file" -c main.cpp -o game.o

g++ -L"File path to SFML library file" .\game.o -o game.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main 

.\game.exe
#### Linux/MacOS:
g++ -I"File path to SFML include file" -c main.cpp -o game.o

g++ -L"File path to SFML library file" ./game.o -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main

./game
