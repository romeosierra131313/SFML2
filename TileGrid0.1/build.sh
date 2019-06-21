#!/bin/bash

clear
 g++ -c  Tile.h Tile.cpp map.h map.cpp GUI.cpp GUI.h Resource.h  Game.h  screen.h screena.h screena.cpp Resource.cpp Game.cpp main.cpp -I/home/stefan/Desktop/SFML-2.5.1/include/ 
 
 
 g++ main.o Tile.o GUI.o map.o screena.o Game.o Resource.o -o sfml-app -L/home/stefan/Desktop/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
 
 
 export LD_LIBRARY_PATH=/home/stefan/Desktop/SFML-2.5.1/lib && ./sfml-app
 
