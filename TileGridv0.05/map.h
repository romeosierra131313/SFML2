 
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
        sf::Vector2i tileLocation[256];
        int  tileLocationCounter = 0;
        sf::Texture TextureGrass;
        sf::Texture TextureGrass2;
        mine::pawn pawns[32];
        int pawncount = 0;
        int tmpcounter = 0;

        
       map();
       ~map(){}
        void  setTileSet(const sf::Image TS,int tilewidth);
        void  BuildGrid(int Map_width,int Map_height,int tilewidth);//////int Map_Width and int Map_Height;
        void handleInput(sf::Event Event,sf::Vector2i cursor_location);
        sf::Sprite getTile(int i,float t);
        void AddTileAt(int x,int y);
        bool does_tileLocationContain(sf::Vector2i a);
        void discoverNode(sf::Vector2i a);
        void discoverRange(int a,sf::Vector2i loc);
        

      map(const map&) = delete;
      map& operator=(const map&) = delete;
      

      
};
}

#endif
