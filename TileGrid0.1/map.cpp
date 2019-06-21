#include "map.h"
#include "Tile.h"
#include <iostream>

namespace romeo{
    
    
map::map(){
    
}
map::map(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
    
    
    Tile_Width=TileWidth;
    Map_Width=MapWidth;
    Map_Height= MapHeight;
    
    BackGround_D_X = 1;
    BackGround_D_Y = 1;
    BackGround_D_Offeset_X = 0;
    BackGround_D_Offeset_Y = 0;
    clickPos.x = 0;
    clickPos.y = 0;
    showHitbox = false;
    layer = 0;   
    
}

void map::initia(romeo::Resource* r){


//////
    int count = 0;
      for(int i =Map_Width ; i>0; i--){
          for(int j =0 ; j<Map_Height; j++){
            int q = makeTileID(i,j);/////making unique key 
                romeo::Tile t(4,sf::Vector3i(i,j,layer),Tile_Width,r);
                t.setTileID(q);
                map_map.insert(std::make_pair( q,t));
                TileIDList[count] = q;
                count++;
                }
            }
            
                    romeo::Tile cursor(0,sf::Vector3i(Map_Width/2,Map_Height/2,2),Tile_Width,r);
                    map_map.insert(std::make_pair( 0,cursor));
                    cid = makeTileID(map_map[0].getLocation().x,map_map[0].getLocation().y);
                    
                    BackGround_T.loadFromImage(r->return_Back("assets/stand.jpg"));
                    BackGround_X=cursor.S.getPosition().x - BackGround_T.getSize().x/2 *5;
                    BackGround_Y=cursor.S.getPosition().y - BackGround_T.getSize().y/2 *5;
                    
                    BackGround_S.setPosition( BackGround_X,BackGround_Y);
                    BackGround_S.setScale(5.f,5.f);
                    BackGround_S.setTexture(BackGround_T);  
                        

    

        }
        
void map::setWindow(sf::RenderWindow* window,sf::View* map_v){
     mywindow = window;
     Map_View = map_v;
     windowDim = mywindow->getSize();
       Map_View->setCenter(map_map[0].S.getPosition().x,map_map[0].S.getPosition().y);
     
}
void map::setCamera(int x,int y){
    Map_View->setCenter(x,y);
    
}
void map::setClickPos(sf::Vector2i position){
   
    clickPos.x = position.x;
    clickPos.y = position.y;
    
    
}
void map::SetCursor(sf::Vector3i temploca){
    /////////update the location of cursor //////////
                temploca.z += 2; ////////////2 here is the elevation above tile expected to be const regardless of tilewidth////////
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].TileType);
    ////////reset center of the camera to cursor ///////////
                Map_View->setCenter(map_map[0].S.getPosition().x,map_map[0].S.getPosition().y);
    ////////update the cid for corrext draw order /////////
                cid = makeTileID(temploca.x,temploca.y);
    
    
}
void map::handleKeys(sf::Event e){
              if (e.type == sf::Event::MouseMoved ){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
                  sf::Vector2i position = sf::Mouse::getPosition();
                  sf::Vector2i position2(mywindow->mapPixelToCoords (position,*Map_View)) ; 
                  setClickPos(position2);
                   /*   
                    get mouse position , convert it world coords and set the clickpos for comparison
                    */     
                    
                    }

                }

        if (e.type == sf::Event::KeyPressed){
            if (e.key.code == sf::Keyboard::H){//////
                if(!showHitbox){
                    showHitbox = true;
                        }else{showHitbox = false;
                             }
            }  
        
            
            if (e.key.code == sf::Keyboard::M){//////
                 layer += 1;
               
            }
            
            if (e.key.code == sf::Keyboard::N){//////
                layer -= 1;
               
            }
            
            
            
            
            sf::Vector3i temploca(map_map[0].getLocation());
            if (e.key.code == sf::Keyboard::Numpad8){//////
                
                temploca.y -= 1;
                temploca = map_map[ makeTileID(temploca.x,temploca.y)].getLocation();
                
                
                SetCursor(temploca);
               
            }
            if (e.key.code == sf::Keyboard::Numpad2){//////
               temploca.y += 1;
               temploca = map_map[ makeTileID(temploca.x,temploca.y)].getLocation();
                
                SetCursor(temploca);
                
               
            }
            if (e.key.code == sf::Keyboard::Numpad4){//////
                temploca.x -= 1;
                temploca = map_map[makeTileID(temploca.x,temploca.y)].getLocation();
                
                SetCursor(temploca);
               
            }
            if (e.key.code == sf::Keyboard::Numpad6){//////
                temploca.x += 1;
                temploca = map_map[makeTileID(temploca.x,temploca.y)].getLocation();
                
                SetCursor(temploca);

                
               
            }
        }
           
    
}
int map::getSelected(){
    return selected;
    
}
void map::setSelected(int sel){
    selected = sel;
    
}   
int map::makeTileID(int i , int j){
    int id = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;
        return id;
}
void map::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
    
    
    
    
   BackGround_S.move(BackGround_D_X,BackGround_D_Y);
   BackGround_D_Offeset_X = BackGround_D_Offeset_X + BackGround_D_X;
   BackGround_D_Offeset_Y = BackGround_D_Offeset_Y + BackGround_D_Y;
   std::cout<<"X" <<BackGround_D_Offeset_X <<std::endl;
   std::cout<<"Y" <<BackGround_D_Offeset_X <<std::endl;
    if(BackGround_D_Offeset_X <= -100 ){
        BackGround_D_X = 1;
  }
    if(BackGround_D_Offeset_X >=100){
  BackGround_D_X = -1;
        
    }
    
        if(BackGround_D_Offeset_Y <= -50 ){
        BackGround_D_Y = 1;
  }
    if(BackGround_D_Offeset_Y >=50){
  BackGround_D_Y = -1;
        
    }
    
    
    mywindow->draw(BackGround_S);
int count  = 0;
      for(int i =Map_Width ; i>0; i--){/////////iterating through tiles/////////
          for(int j =0 ; j<Map_Height; j++){
                int q = TileIDList[count];
                    if(clickPos.x != 0 && clickPos.y != 0){/////////do i need to check for click ??
                        if(map_map[q].Am_I_Here(clickPos)){//////////yes,then for each tile compare
                                                           //////////a tile responded yes 
                                    map_map[q].setLocationZ(layer);//set its layer
                                    map_map[q].ResetTile(selected);//reset it 
                                    
                                    clickPos.x = 0;/////////////////reset the clickpos 
                                    clickPos.y = 0;
                                
                                            }
               
                                        }
                                    map_map[q].render(mywindow,t);/////////draw the tile
                             if(map_map[q].getTileID() == cid){  /////////is the cursor here ??
                                        map_map[0].render(mywindow,t); /////yes cursor will draw here as well
                                        map_map[0].renderHitbox(mywindow,t);}
                                if(showHitbox){
                                            map_map[q].renderHitbox(mywindow,t);
               
                                                }
                        
                                        count++;
                                        }
                                    }
                            }
;
}
