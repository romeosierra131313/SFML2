#include "include/GUI.h"
#include <iostream>

namespace romeo{   
       
GUI::GUI(){
    std::cout<<"GUI called";
     
}



void GUI::initi(int TileWdth,romeo::Resource* r,sf::RenderWindow* window){
     TileWidth = TileWdth;
     Background.setSize(sf::Vector2f(TileWidth*8,TileWidth*6));
     Background.setPosition(TileWidth,TileWidth);
     Background.setFillColor(sf::Color::White);
     setTiles(r);
     clickPos.x = 0;
     clickPos.y = 0;
     sethasSelectedEntity(false);
     sethasMenuSelection(false);
     menuselection = 0;
     
     cCalndar.initi(r,window);

    
}
void GUI::setWindow(sf::RenderWindow* window,sf::View* gui_v){
     mywindow = window;
     gui_view = gui_v;
}
void GUI::setTiles(romeo::Resource* r){
    int count =0;
          for(int i = r->getTilesetDim().x/TileWidth ; i>0; i--){
          for(int j = r->getTilesetDim().y/TileWidth ; j>0; j--){
                romeo::Tile t(r->getTexture(count),sf::Vector3i(i,j,0),TileWidth,1);
                 t.setTileID(count);
                myTiles[count] = t;
               
                count++;
        }
    }
}
void GUI::setSelected_Entity(romeo::Entity* PassedEntity){ Selected_Entity = PassedEntity;}
romeo::Entity* GUI::getSelected_Entity(){return Selected_Entity; }
void GUI::setEditmode(bool b){Editmode = b;}
bool GUI::getEditmode(){return Editmode;}
void GUI::sethasMenuSelection(bool b){hasMenuSelection = b;}
bool GUI::gethasMenuSelection(){ return hasMenuSelection;}
void GUI::setFocus(bool b){hasFocus = b;}
bool GUI::getFocus(){return hasFocus;}
void  GUI::sethasSelectedEntity(bool b){ hasSelectedEntity = b ;}
bool  GUI::gethasSelectedEntity(){ return hasSelectedEntity;}
void GUI::setMenu_Position(sf::Vector2i newPosition){Menu_Position = newPosition;}
sf::Vector2i GUI::getMenu_Position(){return Menu_Position; }

int  GUI::getSelected(){return selected;}
void GUI::setSelected(int sel){selected = sel;}
void GUI::setClickPos(sf::Vector2i position){
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}

void GUI::setTime(float t){Time += t;}

void GUI::handleKeys(sf::Event e){
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
                    std::cout <<  getMenu_Position().x <<std::endl;
                   }
                   if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::X){//////
                      setFocus(false);  
                  
                }
                
                   if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Z){//////
                       
                      switch (getMenu_Position().x){
                          case 0:
                                 menuselection = 1;
                                 setFocus(false);
                              break; 
                           case 1:
                                 menuselection = 2;
                                 setFocus(false);
                              break; 
                           case 2:
                                 menuselection = 3;
                                 setFocus(false);
                              break; 
                           case 3:
                                 menuselection = 4;
                                 setFocus(false);
                              break; 
                              
                              
                              
                              
                    }
                                
                                
                                
                                
                            }
                         
              
 
                        
                        
                   if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                            sf::Vector2i position = sf::Mouse::getPosition();
                            sf::Vector2i position2(mywindow->mapPixelToCoords(position,*gui_view)) ; 
                            setClickPos(position2);
                               
                    }
                }     
                    
}
    
void GUI::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
      cCalndar.render(mywindow,t)  ;    
             
        
    setTime(t);
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
                
                myTextBoxes[i].setFocus(false);
                myTextBoxes[getMenu_Position().x].setFocus(true);
                myTextBoxes[i].render(mywindow,t);
                
            }
          
        if(Editmode){
           mywindow->draw(Background);
           
           for(int i =47 ; i>0; i--){
               myTiles[i].render(mywindow,t);
                  if(clickPos.x != 0 && clickPos.y != 0){
                    if(myTiles[i].Am_I_Here(clickPos)){
                      setSelected(myTiles[i].getTileID());
                            clickPos.x = 0;
                            clickPos.y = 0;
                      setEditmode(false);      
                      setFocus(false);
                        
                    }
                }
            }
            
            
        }
    }
   }

;
}
 
