#include "screena.h"
#include <iostream>

namespace romeo{   
       
screena::screena(){
    std::cout<<"default screena called";
}



void screena::initi(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
     mapa.initia(TileWidth,MapWidth,MapHeight,r);
    
}
void screena::setWindow(sf::RenderWindow* window,sf::View* gui_v,sf::View* map_v){
    mywindow = window;
    gui_view = gui_v;
    map_view = map_v;
}
void screena::handleKeys(sf::Event e){
     mapa.handleKeys(e);
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Q)){//////escape!!/////
                }
}
    
void screena::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
            mapa.render(mywindow,t,r);
    
    
    
}
void screena::renderGUI(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
            mapa.render(mywindow,t,r);
    
    
    
}
;
}
