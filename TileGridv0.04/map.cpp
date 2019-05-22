#include <SFML/Graphics.hpp>
#include "map.h"
#include "pawn.h"
#include <iostream>

namespace mine{
  map::map(){   
    };     
    
    void map::setTileSet(const sf::Image TS,int tilewidth){
        
         Tileset_Size = TS.getSize();
        if (!Tileset_Texture.loadFromImage(TS,sf::IntRect(0,0,Tileset_Size.x,Tileset_Size.y))){
           std::cout << " failed loading TileSet_Texture";}
           std::cout<< "building count "  << tilewidth << std::endl;
            TextureGrass.loadFromImage(TS,sf::IntRect(2*tilewidth,0,2*tilewidth,2*tilewidth));
              
    }
    void map::BuildGrid(int Map_Width, int Map_Height,int tilewidth){
             tileWidth = tilewidth;
             
             int count = 0;
                for (int i = 0;i< Map_Width; i++){   ///////setup grid to draw on////
                    for (int j = 0;j< Map_Height; j++){
    
                        tile[count].myType = 1;
                        tile[count].setup(TextureGrass,tileWidth,2.0f,sf::Vector2i(i,j));
                  
                        count++;
 
                                }    
    
                    }
        
    }
    sf::Sprite map::getTile(int i,float t){
        
      return tile[i].getSprite(t);
    }
}
