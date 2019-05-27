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
            TextureGrass.loadFromImage(TS,sf::IntRect(2*tilewidth,0,2*tilewidth,2*tilewidth));
                
    sf::Texture t2; ////////////pawns//////////
    t2.loadFromImage(TS,sf::IntRect(0,tilewidth,tilewidth*3,tilewidth));

    pawns[0].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(4,4),1);
    pawns[1].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(5,5),2);
    pawns[2].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(6,6),3);
    pawns[3].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(7,7),4);
    pawns[4].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(8,8),5);
    pawns[5].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(9,9),6);
    pawns[6].setupPawn(t2,tilewidth,0.25f,sf::Vector2i(10,10),7);
    pawncount = 7;  
 
    }
    void map::BuildGrid(int Map_width, int Map_height,int tilewidth){
     
            Map_Height = Map_height;
            Map_Width = Map_width;
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
     void map::handleInput(sf::Event Event,sf::Vector2i cursor_location){
         
         if(Event.key.code == sf::Keyboard::Z){
             
              for (int i = 0;i< pawncount; i++){
                  if( pawns[i].Am_I_Here(cursor_location.x,cursor_location.y)==true){  ///pawn here?
                    discoverRange(pawns[i].myRange,pawns[i].location);
                   
                    
                      
                }
                  
            }
        }
        if(Event.key.code == sf::Keyboard::X){
            for (int i = 0;i< pawncount; i++){
                pawns[i].setActive(false);
            }
            for(int u = 0; u < Map_Height*Map_Width; u++){
            tile[u].active = false;  }
            
        }
        
        
    }
    sf::Sprite map::getTile(int i,float t){
      
      return tile[i].getSprite(t);
    }
    
    
     void map::AddTileAt(int x , int y ){
            tileLocation[ tileLocationCounter] = sf::Vector2i(x,y);
                 tileLocationCounter++;
    }
    bool map::does_tileLocationContain(sf::Vector2i a){
        
        for (int i = 0 ; i < 256;i++){
           if(a.x == tileLocation[i].x && a.y == tileLocation[i].y){
               return true;
               break;
            } 
        }
        return false;
    }
    void map::discoverNode(sf::Vector2i a){
            bool done = false; 
       while(!done){ 
         if(!does_tileLocationContain(sf::Vector2i (a.x+1,a.y))){
             AddTileAt(a.x+1,a.y);
             tmpcounter++;
        }else{}
          if(!does_tileLocationContain(sf::Vector2i (a.x-1,a.y))){
              AddTileAt(a.x-1,a.y);
              tmpcounter++;
        }else{}
           if(!does_tileLocationContain(sf::Vector2i (a.x,a.y+1))){
               AddTileAt(a.x,a.y+1);
               tmpcounter++;
        }else{}
            if(!does_tileLocationContain(sf::Vector2i (a.x,a.y-1))){
                AddTileAt(a.x,a.y-1);
                tmpcounter++;
        }else{}
       done = true;}
    }
    void map::discoverRange(int a,sf::Vector2i loc){
       
        for (int j = 0 ; j < 256;j++){ 
            tileLocation[j] = sf::Vector2i(1000,1000);
            tileLocationCounter = 0;
        }
        
       
        AddTileAt(loc.x,loc.y);
        tmpcounter = 1;
        int tmp = tmpcounter;
         for (int i = 0 ; i < a;i++){
            for (int l = 0 ; l < tmp;l++){
              discoverNode(tileLocation[l]);
              
               }tmp = tmpcounter;
    }
       
        
    }
}



