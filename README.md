﻿# Project-Game-1
This project is a 2D Adventure RPG that uses c++ and SFML.
In order to run it, You must pull from this project into an IDE and download C++.
Download SFML and the mingw32 compiler on SFML's website (https://www.sfml-dev.org/download/sfml/2.6.1/).
Follow the instructions given on the website and ensure that the mingw compiler is in the correct path.
Restart your IDE.
Currently the dependencies include an outside texture linked here (https://github.com/mateojh/Project-Game-1/assets/158978579/4491bbca-7207-4e22-aaaa-26e46217668b).
Compiling and running the code is as follows:
g++ -IC:\SFML-2.6.1\include -c main.cpp -o game.o
g++ -LC:\SFML-2.6.1\lib .\game.o -o game.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main
.\game.exe