
#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>

namespace mine{
    
class animation{
    
   public:
        int frameNumber;
        int number_of_frames;
        float frame_Speed;
        int tileWidth;
        float last_time;
        sf::Texture myTexture;
        
       animation();
       ~animation(){}
        void  setup(sf::Texture& myT,int& tilewidth,float frameS);
        sf::Texture animation::StepToNext(float t);
        void  setTexture(sf::Texture& myT);
        void setSpeed(float newSpeed);
      animation(const animation&) = delete;
      animation& operator=(const animation&) = delete;
      

      
};
}

#endif
