 

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
         destination = location;
          myTexture = myT;
         tileWidth =  tilewidth;
         frame_Speed =  frameS;   
         number_of_frames = myTexture.getSize().x/tileWidth;
         
         cursorBox.setSize(sf::Vector2f(tileWidth,tileWidth));
         cursorBox.setPosition(location.x*tileWidth,location.y*tileWidth);
         cursorBox.setFillColor(sf::Color::Transparent);
         
         cursor_Sprite = new sf::Sprite();
         cursor_Sprite->setTexture(myTexture);
         cursor_Sprite->setTextureRect(sf::IntRect(0, 0, tileWidth, tileWidth));
         cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
         
             
        }
         void pawn::setupPawn(sf::Texture& myT,int& tilewidth,float frameS,sf::Vector2i loca,int range){
         frameNumber = 0;
         last_time = 0;
         location.x = loca.x;
         location.y = loca.y; 
         destination = location;
          myTexture = myT;
         tileWidth =  tilewidth;
         frame_Speed =  frameS;   
         number_of_frames = myTexture.getSize().x/tileWidth;
         
         cursorBox.setSize(sf::Vector2f(tileWidth,tileWidth));
         cursorBox.setPosition(location.x*tileWidth,location.y*tileWidth);
         cursorBox.setFillColor(sf::Color::Transparent);
         
         cursor_Sprite = new sf::Sprite();
         cursor_Sprite->setTexture(myTexture);
         cursor_Sprite->setTextureRect(sf::IntRect(0, 0, tileWidth, tileWidth));
         cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
         
         myRange = range;
         movementRange[64] = sf::Vector2i(100,100);
         setMovementRange();
             
        }
        void  pawn::setMovementRange(){
            int count = 0;
            for(int i = 0; i <= myRange ; i ++){
                 movementRange[count] = sf::Vector2i(location.x,location.y+i);
                 count++;
                 movementRange[count] = sf::Vector2i(location.x,location.y-i);
                 count++;
                 movementRange[count] = sf::Vector2i(location.x+i,location.y);
                 count++;
                 movementRange[count] = sf::Vector2i(location.x-i,location.y);
                 count++;
                
            }
            int count2 = count+1;
            for(int j = 0; j <= count ; j ++){
                 if(movementRange[j].x > location.x || movementRange[j].x < location.x){
                      movementRange[count2] = sf::Vector2i(movementRange[j].x,movementRange[j].y+1);
                      count2++;
                      movementRange[count2] = sf::Vector2i(movementRange[j].x,movementRange[j].y-1);
                      count2++;
                } 
                else if(movementRange[j].y < location.y || movementRange[j].y > location.y){
                      movementRange[count2] = sf::Vector2i(movementRange[j].x+1,movementRange[j].y);
                      count2++;
                      movementRange[count2] = sf::Vector2i(movementRange[j].x-1,movementRange[j].y);
                      count2++;
                }
                
            }
            
        }
        void  pawn::setTexture(sf::Texture& myT){
         myTexture = myT;  
         cursor_Sprite = new sf::Sprite();
         cursor_Sprite->setTexture(myTexture);
         cursor_Sprite->setTextureRect(sf::IntRect(0, 0, tileWidth, tileWidth));
         cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
            
        }
        void  pawn::setLocation(sf::Vector2i loca){
            location.x = loca.x;
            location.y = loca.y; 
            cursorBox.setPosition(location.x*32,location.y*32);   
            cursor_Sprite->setPosition(location.x*32,location.y*32);
            
        }
         void pawn::doathin(){
            
            
             
        } 
        void pawn::moveTo(){
            
//             if(destination != dest){
//                 destination = dest;
//             }
            if(location.x*32 != destination.x*32){
                    std::cout << " rloca"<<location.x*32+traveled<<std::endl;
                    std::cout << " rdtravekled"<<destination.x*32<<std::endl;
                  
//                 if(destination.x > location.x){
                   cursorBox.setPosition((location.x*32 +traveled),location.y*32);   
                   cursor_Sprite->setPosition(location.x*32+traveled,location.y*32);
                   traveled += 4;
                    if(traveled >= 32){
                        location.x += 1;
                        traveled = 0;
                        setMovementRange();
                        
                 }
                    
                 }
//             }
            
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
