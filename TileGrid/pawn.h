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
        sf::Vector2i location;
        sf::RectangleShape cursorBox; 
        sf::Texture myTexture;
        sf::Sprite* cursor_Sprite;
        

        
       pawn();
       ~pawn(){}
        void  doathin() ;
        sf::Sprite getSprite(float t);
        void  setup(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca);
        void      move(sf::Event Event);
      pawn(const pawn&) = delete;
      pawn& operator=(const pawn&) = delete;
      

      
};
}

#endif
