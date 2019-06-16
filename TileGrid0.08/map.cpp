#include "map.h"
#include "Tile.h"
#include <iostream>

namespace romeo{
map::map(){
    
}

void map::initia(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
    Tile_Width=TileWidth;
    Map_Width=MapWidth;
    Map_Height= MapHeight;
    clickPos.x = 0;
    clickPos.y = 0;
         
      for(int i =MapWidth ; i>0; i--){
          for(int j =MapHeight ; j>0; j--){
            int q = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;/////making unique key 
                romeo::Tile t(r->getTexture(4),sf::Vector3i(i,j,0),TileWidth);
                t.TileID = q;
                map_map.insert(std::make_pair( q,t));
                
      // sf::Vector3i converted((Location.x+Location.y)*TileWidth,((Location.x-Location.y)*TileWidth*0.5)+400,0);
        //    ((i+j)*TileWidth, x                ////   conversion to isometric 
        //    ((i-j)*TileWidth*0.5)+400); y     ////    done in tile class
            
              
    }

}

}
void map::changeTile(sf::Vector2i position,romeo::Resource* r){
    
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void map::handleKeys(sf::Event e){
    
    
                
                if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Q)){
                    
                
                }
}
    
void map::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
      for(int i =Map_Width ; i>0; i--){
          for(int j =Map_Height ; j>0; j--){
              int q = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;
           if(clickPos.x != 0 && clickPos.y != 0){
              if(map_map[q].Am_I_Here(clickPos)){
                 map_map[q].setSprite(r->getTexture(2)); 
                  
                clickPos.x = 0;
                clickPos.y = 0;}
               
        }
           map_map[q].render(mywindow,t);
              
    }

}
        
    
    
    
}
;
}
