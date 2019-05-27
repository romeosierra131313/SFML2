#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include "battleMenu.h"
#include <SFML/Graphics.hpp>

namespace mine{
    
class pawn{
    

    
   public:
        int frameNumber;
        int number_of_frames;
        float frame_Speed;
        int tileWidth;
        float last_time;
        int myType;
        int myRange;
        int traveled;
        bool here = false;
        bool active=false;
        sf::Vector2i location;
        sf::Vector2i destination;
        sf::RectangleShape cursorBox; 
        sf::Texture myTexture;
        sf::Sprite* cursor_Sprite;
        sf::Vector2i movementRange[64];
        sf::Vector2i open[128];
        int Opencounter = 0;
        int Closedcounter = 0;
        

        
       pawn();
       ~pawn(){}
        void  doathin() ;
        sf::Sprite getSprite(float t);
        void  setup(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca);
        void  setupPawn(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca,int range);
        void  setTexture(sf::Texture& myT);
        void  setLocation(sf::Vector2i loca);
        void moveTo();
        void  move(sf::Event Event);
        bool Am_I_Here(int x,int y);
        void  setActive(bool b);
        bool  getActive();
        bool inRange(sf::Vector2i pos);
        void discoverRange();
        void discoverNode(sf::Vector2i node);
      pawn(const pawn&) = delete;
      pawn& operator=(const pawn&) = delete;
      
      

 
};
}

#endif
