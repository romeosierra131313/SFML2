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
     
     
     myTextBoxes[0].setResource(r); 
     myTextBoxes[1].setResource(r);
     myTextBoxes[2].setResource(r);
     myTextBoxes[3].setResource(r);
     
     
     myTextBoxes[0].ResetTextBox(0,0,2,1,"Move");
     myTextBoxes[1].ResetTextBox(0,1,2,1,"Attack");
     myTextBoxes[2].ResetTextBox(0,2,2,1,"Item");
     myTextBoxes[3].ResetTextBox(0,3,2,1,"Menu");

    
}
void GUI::setWindow(sf::RenderWindow* window,int window_Wdth,int window_Heght,sf::View* gui_v){
     mywindow = window;
     gui_view = gui_v;
     window_Width = window_Wdth;
     window_Height =window_Heght;
     std::cout<<window->getSize().x;
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

void GUI::setEditmode(bool b){Editmode = b;}
bool GUI::getEditmode(){return Editmode;}
void GUI::setFocus(bool b){hasFocus = b;}
bool GUI::getFocus(){return hasFocus;}
int  GUI::getSelected(){return selected;}
void GUI::setSelected(int sel){selected = sel;}



void GUI::setClickPos(sf::Vector2i position){
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void GUI::handleKeys(sf::Event e){
                if(hasFocus){
                   if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                            sf::Vector2i position = sf::Mouse::getPosition();
                            sf::Vector2i position2(mywindow->mapPixelToCoords(position,*gui_view)) ; 
                            setClickPos(position2);
                               
                    }
                }     
                    
}
    
void GUI::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
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
          
        if(Editmode){
           mywindow->draw(Background);
           
           for(int i =47 ; i>0; i--){
               myTiles[i].render(mywindow,t);
               myTiles[i].renderHitbox(mywindow,t);
                  if(clickPos.x != 0 && clickPos.y != 0){
                    if(myTiles[i].Am_I_Here(clickPos)){
                      setSelected(myTiles[i].TileID);
                      std::cout<<myTiles[i].TileID <<  std::endl;
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
 
