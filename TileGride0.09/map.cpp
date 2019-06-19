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
    showHitbox = false;
    layer = 0;
    
    romeo::Tile cursor(0,sf::Vector3i(MapWidth/2,MapHeight/2,4),TileWidth,r);
    map_map.insert(std::make_pair( 0,cursor));
         
      for(int i =MapWidth ; i>0; i--){
          for(int j =MapHeight ; j>0; j--){
            int q = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;/////making unique key 
                romeo::Tile t(4,sf::Vector3i(i,j,layer),TileWidth,r);
                t.setTileID(q);
                map_map.insert(std::make_pair( q,t));
                }
            }
        }
        
void map::setWindow(sf::RenderWindow* window,sf::View* map_v){
     mywindow = window;
     Map_View = map_v;
}
void map::setClickPos(sf::Vector2i position){
   
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void map::handleKeys(sf::Event e){
              if (e.type == sf::Event::MouseMoved ){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                  sf::Vector2i position = sf::Mouse::getPosition();
                  sf::Vector2i position2(mywindow->mapPixelToCoords (position,*Map_View)) ; 
                  setClickPos(position2);
                        
                    
                    }

                }
               if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::H)){//////
                  if(!showHitbox){
                   showHitbox = true;}else{showHitbox = false;}
               
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::M)){//////
                 layer += 1;
               
            }
            
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::N)){//////
                layer -= 1;
               
            }
            
            
            sf::Vector3i temploca(map_map[0].getLocation());
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Numpad8)){//////
                
                temploca.y -= 1;
                temploca.z = map_map[((temploca.x+temploca.y)*Tile_Width) + temploca.x-temploca.y*Tile_Width*0.5].getLocation().z+1;
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].getTileID());
               
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Numpad2)){//////
               temploca.y += 1;
               temploca.z = map_map[ ((temploca.x+temploca.y)*Tile_Width) + temploca.x-temploca.y*Tile_Width*0.5].getLocation().z+1;
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].getTileID());
               
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Numpad4)){//////
                temploca.x -= 1;
                temploca.z = map_map[ ((temploca.x+temploca.y)*Tile_Width) + temploca.x-temploca.y*Tile_Width*0.5].getLocation().z+1;
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].getTileID());
               
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Numpad6)){//////
                 temploca.x += 1;
                 temploca.z = map_map[ ((temploca.x+temploca.y)*Tile_Width) + temploca.x-temploca.y*Tile_Width*0.5].getLocation().z+1;
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].getTileID());
               
            }
           
    
}
int map::getSelected(){
    return selected;
    
}
void map::setSelected(int sel){
    selected = sel;
    
}    
void map::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
      for(int i =Map_Width ; i>0; i--){
          for(int j =0 ; j<Map_Height; j++){
              int q = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;
           if(clickPos.x != 0 && clickPos.y != 0){
              if(map_map[q].Am_I_Here(clickPos)){
                  
                 map_map[q].setLocationZ(layer);
                 map_map[q].ResetTile(selected);

                  
                clickPos.x = 0;
                clickPos.y = 0;}
               
                            }
           map_map[q].render(mywindow,t);
           map_map[0].render(mywindow,t); /////cursor////
                if(showHitbox){
                    map_map[q].renderHitbox(mywindow,t);
               
                        }
                    }
                }
            }
;
}
