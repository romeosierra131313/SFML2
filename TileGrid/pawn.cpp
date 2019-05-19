 

#include <SFML/Graphics.hpp>
#include "pawn.h"
#include <iostream>

namespace mine{
  pawn::pawn(){

         

         
    };    
    
         sf::Sprite pawn::getSprite(float t){
              if(t - last_time > frame_Speed){   ////////checking if frame_Speed has elapsed//////
                  last_time = t;                 ///////yes , then set las time to current time (for next time around)///
                if(frameNumber < number_of_frames -1 ){             ///////checking limits of number of frames//////
                      frameNumber++;
                      
                }
                 else if(frameNumber == number_of_frames-1){
                      frameNumber = 0;
                     
                }
                  
            cursor_Sprite->setTextureRect(sf::IntRect(frameNumber*tileWidth, 0, tileWidth, tileWidth));   
           
            }  
            
            
             return *cursor_Sprite;
        }
         void pawn::setup(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca){
                   frameNumber = 0;
         last_time = 0;
         location.x = loca.x;
         location.y = loca.y;   
          myTexture = myT;
         tileWidth =  tilewidth;
         frame_Speed =  frameS;   
             

         std::cout << myTexture.getSize().x/tileWidth << std::endl;;
         number_of_frames = myTexture.getSize().x/tileWidth;
         
         cursorBox.setSize(sf::Vector2f(tileWidth,tileWidth));
         cursorBox.setPosition(location.x*tileWidth,location.y*tileWidth);
         cursorBox.setFillColor(sf::Color::Transparent);
         
         cursor_Sprite = new sf::Sprite();
         cursor_Sprite->setTexture(myTexture);
         cursor_Sprite->setTextureRect(sf::IntRect(0, 0, tileWidth, tileWidth));
         cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
         
             
        }
         void pawn::doathin(){
            
            
             
        } 
         void pawn::move(sf::Event Event){
              if(Event.key.code == sf::Keyboard::Up){ 
                  location.y -= 1;
                  
            }
              if(Event.key.code == sf::Keyboard::Right){ 
                  location.x += 1;
                  
            }
              if(Event.key.code == sf::Keyboard::Down){ 
                  location.y += 1;
                  
            }
              if(Event.key.code == sf::Keyboard::Left){ 
                  location.x -= 1;
                  
            }
             
         cursorBox.setPosition(location.x*32,location.y*32);   
         cursor_Sprite->setPosition(location.x*32,location.y*32);
        }
             
             

}
