 #include "include/BattleMenu.h"
#include <iostream>

namespace romeo{   

   
BattleMenu::BattleMenu(){

}



void BattleMenu::initi(int TileWdth,romeo::Resource* rm){
    r = rm;
    
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
     setMenu_Position(sf::Vector2i(0,0));
     myTextBoxes[0].setFocus(true);
     menuselection = -1;
     hasFocus = false;
    
     
     text_hp.setFont(*rm->getFont());
     text_hp.setString("HP");
     text_hp.setCharacterSize(15);
     text_hp.setFillColor(sf::Color::White);
     text_hp.setPosition(32,300);
     
     
     text_attack.setFont(*rm->getFont());
     text_attack.setString("attack");
     text_attack.setCharacterSize(15);
     text_attack.setFillColor(sf::Color::White);
     text_attack.setPosition(32,330);
     
     text_inputmode.setFont(*rm->getFont());
     text_inputmode.setString("attack");
     text_inputmode.setCharacterSize(15);
     text_inputmode.setFillColor(sf::Color::White);
     text_inputmode.setPosition(32,360);
    
}
void BattleMenu::setWindow(int window_Wdth,int window_Heght,sf::View* gui_v){
     gui_view = gui_v;
     window_Width = window_Wdth;
     window_Height =window_Heght;
}
void BattleMenu::setMenu_Position(sf::Vector2i newPosition){Menu_Position = newPosition;}
sf::Vector2i BattleMenu::getMenu_Position(){return Menu_Position; }
void BattleMenu::setFocus(bool b){hasFocus = b;}
bool BattleMenu::getFocus(){return hasFocus;}

void BattleMenu::setClickPos(sf::Vector2i position){
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void BattleMenu::handleKeys(sf::Event e){
                    if(hasFocus){
                  if (e.type == sf::Event::KeyPressed){  
                   if (e.key.code == sf::Keyboard::Numpad2){  
                     if(getMenu_Position().x <= 3 ) {  
                      setMenu_Position(sf::Vector2i(getMenu_Position().x+1,0));
                        }
                   }
                   if (e.key.code == sf::Keyboard::Numpad8){
                    if(getMenu_Position().x >= 0) {  
                      setMenu_Position(sf::Vector2i(getMenu_Position().x-1,0));
                        }
                    }
                     for(int i = 0 ; i < 4 ; i++){myTextBoxes[i].setFocus(false); }
                      myTextBoxes[getMenu_Position().x].setFocus(true); 
                   }
                   if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::X){//////
                      setFocus(false);  
                  
                }/*
                          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                            sf::Vector2i position = sf::Mouse::getPosition();
                            sf::Vector2i position2(mywindow->mapPixelToCoords(position,*gui_view)) ; 
                            setClickPos(position2);
                               
                    }
                }  */ 
                 if ( e.type == sf::Event::KeyReleased){
                   if (e.key.code == sf::Keyboard::Z){
                       menuselection = getMenu_Position().x; 
                        std::cout << "set menuselection to-- "<<getMenu_Position().x <<std::endl;
                       setFocus(false);
                }
                 }
}
}
    
void BattleMenu::render(sf::RenderWindow* mywindow,float t){ 
     mywindow->setView((r->getGUIView()));
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
         mywindow->draw(text_hp);
         
         mywindow->draw(text_attack);
         
         mywindow->draw(text_inputmode);
             
        }


    
    
     mywindow->setView((r->getMapView()));
   }

;
}
 
