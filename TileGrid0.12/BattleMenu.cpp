 #include "include/BattleMenu.h"
#include <iostream>

namespace romeo{   
       
BattleMenu::BattleMenu(){
    std::cout<<"BattleMenu called";
     
}



void BattleMenu::initi(int TileWdth,romeo::Resource* r,sf::RenderWindow* window){
     TileWidth = TileWdth;
     Background.setSize(sf::Vector2f(TileWidth*8,TileWidth*6));
     Background.setPosition(TileWidth,TileWidth);
     Background.setFillColor(sf::Color::White);
     clickPos.x = 0;
     clickPos.y = 0;
     
     
     myTextBoxes[0].setResource(r); 
     myTextBoxes[1].setResource(r);
     myTextBoxes[2].setResource(r);
     myTextBoxes[3].setResource(r);
     
     
     myTextBoxes[0].ResetTextBox(0,0,2,1,"Move");
     myTextBoxes[1].ResetTextBox(0,1,2,1,"Attack");
     myTextBoxes[2].ResetTextBox(0,2,2,1,"Item");
     myTextBoxes[3].ResetTextBox(0,3,2,1,"Menu");
     
     hasFocus = false;

    
}
void BattleMenu::setWindow(sf::RenderWindow* window,int window_Wdth,int window_Heght,sf::View* gui_v){
     mywindow = window;
     gui_view = gui_v;
     window_Width = window_Wdth;
     window_Height =window_Heght;
}

void BattleMenu::setFocus(bool b){hasFocus = b;}
bool BattleMenu::getFocus(){return hasFocus;}

void BattleMenu::setClickPos(sf::Vector2i position){
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void BattleMenu::handleKeys(sf::Event e){
                if(hasFocus){
                   if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                            sf::Vector2i position = sf::Mouse::getPosition();
                            sf::Vector2i position2(mywindow->mapPixelToCoords(position,*gui_view)) ; 
                            setClickPos(position2);
                               
                    }
                }     
                    
}
    
void BattleMenu::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
 std::cout<<"GUI render";
    
          if(hasFocus){
             if(clickPos.x != 0 && clickPos.y != 0){
                  for(int i = 0 ; i < 4 ; i++){
                     if( myTextBoxes[i].Am_I_Here(clickPos)){
                         myTextBoxes[i].ResetTextBox(myTextBoxes[i].GetX(),
                         myTextBoxes[i].GetY(),
                         myTextBoxes[i].GetWidth(),myTextBoxes[i].GetHeight(),"Clicked");
                         std::cout <<"checking click";
                         clickPos.x = 0;/////////////////reset the clickpos 
                         clickPos.y = 0;
                    }
                      
                }
                 
            }
            for(int i = 0 ; i < 4 ; i++){
                myTextBoxes[i].render(mywindow,t);
                
            }

    }
   }

;
}
 
