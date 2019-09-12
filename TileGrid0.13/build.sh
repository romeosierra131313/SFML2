#!/bin/bash

clear

echo clearing

g++ -c Calndar.cpp TextBox.cpp Background.cpp BattleMenu.cpp Entity.cpp Tile.cpp  map.cpp  GUI.cpp screena.cpp Resource.cpp Game.cpp main.cpp -I/home/stefan/Desktop/SFML-2.5.1/include/ -I/home/stefan/Desktop/TileGrid0.1/

echo compiling
 
g++ main.o Calndar.o TextBox.o Background.o BattleMenu.o Entity.o Tile.o  GUI.o map.o screena.o Game.o Resource.o  -o sfml-app -L/home/stefan/Desktop/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system

echo linking headers
echo cleaning up 

rm *.o.gch

echo finished cleaning
echo launching app
 

 export LD_LIBRARY_PATH=/home/stefan/Desktop/SFML-2.5.1/lib  
 ./sfml-app
 
