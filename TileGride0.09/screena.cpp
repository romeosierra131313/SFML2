#include "screena.h"
#include <iostream>

namespace romeo{   
       
screena::screena(){
    std::cout<<"default screena called";
}



void screena::initi(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
    
    
     mapa.initia(TileWidth,MapWidth,MapHeight,r);
     gui.initi(TileWidth,r,mywindow);
     
   
    
}
void screena::setWindow(sf::RenderWindow* window,int window_Wdth,int window_Heght,sf::View* gui_view,sf::View* map_view){
    mywindow = window;
    window_Width =window_Wdth;
    window_Height=window_Heght; 
    gui.setWindow(mywindow,window_Width,window_Height,gui_view);
    mapa.setWindow(mywindow,map_view);
    
    
}


void screena::handleKeys(sf::Event e){
     mapa.handleKeys(e);
     gui.handleKeys(e);
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::E)){//////escape!!/////
             if(gui.getFocus()){ gui.setFocus(false);}else{ gui.setFocus(true);}
            
                }
}
    
void screena::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
                mapa.render(mywindow,t,r);
                mapa.setSelected(gui.getSelected());
                
                
            
    
}
void screena::renderGUI(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
            gui.render(mywindow,t,r);
    
}
;
}
