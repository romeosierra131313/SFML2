#include <SFML/Graphics.hpp>
#include "animation.h"
#include <iostream>

namespace mine{
  animation::animation(){    
    };    
    
    animation::setup(sf::Texture& myT,int& tilewidth,float frameS){
        myTexture = myT;
        tileWidth = tilewidth;
        frame_Speed = frameS;
        myTexture.setTextureRect(sf::IntRect(0, 0, tileWidth, tileWidth));
    }
    sf::Texture animation::StepToNext(float t){
          if(t - last_time > frame_Speed){   ////////checking if frame_Speed has elapsed//////
                  last_time = t;                 ///////yes , then set las time to current time (for next time around)///
                  if(frameNumber < number_of_frames -1 ){             ///////checking limits of number of frames//////
                      frameNumber++;
                   }
                  else if(frameNumber == number_of_frames-1){
                      frameNumber = 0;
                } 
            myTexture.setTextureRect(sf::IntRect(frameNumber*tileWidth, 0, tileWidth, tileWidth));   
            }   
             return myTexture;
    }
    
    void animation::setSpeed(float newSpeed){
        frame_Speed = newSpeed;
    }
    void animation::setTexture(sf::Texture& myT){
        myTexture = myT;
    }
    sf::Texture animation::getKeyFrame(){
        return myTexture();
    }
