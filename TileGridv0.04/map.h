 
#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "pawn.h"

namespace mine{
    
class map{
    
   public:
        int tileWidth;
        int Map_Width;
        int Map_Height;
        sf::Vector2u Tileset_Size;
        sf::Texture Tileset_Texture;
        sf::Texture Tile_Texture;
        mine::pawn tile[1024];
        sf::Texture TextureGrass;
        sf::Texture TextureGrass2;

        
       map();
       ~map(){}
        void  setTileSet(const sf::Image TS,int tilewidth);
        void  BuildGrid(int Map_Width,int Map_Height,int tilewidth);//////int Map_Width and int Map_Height;
        sf::Sprite getTile(int i,float t);
        

      map(const map&) = delete;
      map& operator=(const map&) = delete;
      

      
};
}

#endif
