 

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
         movementRange[64]; 
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
            cursorBox.setPosition(location.x*tileWidth,location.y*tileWidth);   
            cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
            
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
                        
                 }
                    
                 }
//             }
            
        }
         void pawn::move(sf::Event Event){
             if(active){
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
             
         cursorBox.setPosition(location.x*tileWidth,location.y*tileWidth);   
         cursor_Sprite->setPosition(location.x*tileWidth,location.y*tileWidth);
        }
    }
        
             bool pawn::Am_I_Here(int x , int y){
                 
                 if(location.x == x && location.y == y ){
                      here = true;
                      active = true;
                      std::cout << "i am here" << std::endl;
                      return here;
                     
                }
                return false;
            }
                void  pawn::setActive(bool b){
                    std::cout << b << std::endl;
                    active = b;
        
    }
            bool  pawn::getActive(){
          
                return active;
        
    } 
            bool pawn::inRange(sf::Vector2i pos){
                for (int i = 0 ; i < sizeof(movementRange); i++){
                    if(movementRange[i].x == pos.x && movementRange[i].y == pos.y ){
                        return true;
                        break;
                        
                    }
                    
                } return false;
                
            }
             void pawn::discoverRange(){
                 
                 open[0] = location;
                 Opencounter = 1;
                 discoverNode(open[0]);
                 
                 for(int i = 0; i <= myRange; i++){
                      for(int j = 0; j < Opencounter; j++){
                         discoverNode(open[j] );
                         
                }
                std::cout << i << std::endl;
                 
            }
             }
            void pawn::discoverNode(sf::Vector2i node){
                for(int j = 0; j < Opencounter; j++){
                    
                    if(open[j].x != node.x+1 && open[j].y == node.y){
                          open[Opencounter] = sf::Vector2i( node.x+1,node.y);
                          Opencounter++;}}
                for(int k = 0; k < Opencounter; k++){           
                    if(open[k].x != node.x-1 && open[k].y == node.y){
                          open[Opencounter] = sf::Vector2i( node.x-1,node.y);
                          Opencounter++;}}
                for(int l = 0; l < Opencounter; l++){          
                    if(open[l].x == node.x && open[l].y != node.y+1 ){
                          open[Opencounter] = sf::Vector2i( node.x,node.y+1);
                          Opencounter++;}}
                for(int m = 0; m < Opencounter; m++){
                    if(open[m].y == node.y-1 && open[m].x != node.x){
                          open[Opencounter] = sf::Vector2i( node.x,node.y-1);
                          Opencounter++;}}
                    
                     
                
            }
}
