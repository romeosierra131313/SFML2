#include "screen.h"
#include "screena.h"
#include <map>
#include <iostream>

namespace romeo{
screena::screena(){


}
void screena::nit(romeo::Resource r){
     resource_manager = r;
    
}
screena::screena(int TileWidth,int MapWidth,int MapHeight){
         T_Width=TileWidth;
         M_Width=MapWidth;
         M_Height  =MapHeight;
         
         std::cout<<"Inserting Tiles" << std::endl;
      for(int i =MapWidth ; i>0; i--){
          for(int j =MapHeight ; j>0; j--){
           
            int q = (i*100) + j ;/////making unique key 

           romeo::Tile t(resource_manager.getTexture(1),sf::Vector3i(i,j,0),T_Width);
         
        //    ((i+j)*TileWidth, x
        //    ((i-j)*TileWidth*0.5)+400); y
            
            map.insert(std::make_pair( q,t));
              
    }

}

}

void screena::handleKeys(sf::Event e){
                if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Q)){//////escape!!//////
                std::cout<<"hi";}
    
    
}
    
void screena::render(sf::RenderWindow* mywindow,float t){ 
      for(int i =M_Width ; i>0; i--){
          for(int j =M_Height ; j>0; j--){
             int q = (i*100) + j ;
           
           map[q].render(mywindow,t);
              
    }

}
        
    
    
    
}
;
}
