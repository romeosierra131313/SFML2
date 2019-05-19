#ifndef PAWN_H
#define PAWN_H
#include <iostream>
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
        sf::Vector2i location;
        sf::Vector2i destination;
        sf::RectangleShape cursorBox; 
        sf::Texture myTexture;
        sf::Sprite* cursor_Sprite;
        sf::Vector2i movementRange[64];
        

        
       pawn();
       ~pawn(){}
        void  doathin() ;
        sf::Sprite getSprite(float t);
        void  setup(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca);
        void  setupPawn(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca,int range);
        void  setTexture(sf::Texture& myT);
        void  setLocation(sf::Vector2i loca);
        void  setMovementRange();
        void moveTo();
        void  move(sf::Event Event);
      pawn(const pawn&) = delete;
      pawn& operator=(const pawn&) = delete;
      

      
};
}

#endif
