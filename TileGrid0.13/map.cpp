#include "include/map.h"
#include "include/Tile.h"
#include "include/revt.h"
#include <iostream>

namespace romeo{
    
    
map::map(){
    
}
map::map(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
    rm = r;
    
    Tile_Width=TileWidth;
    Map_Width=MapWidth;
    Map_Height= MapHeight;
    clickPos.x = 0;
    clickPos.y = 0;
    showHitbox = false;
    setGuiIsOpen(false);
    layer = 0; 
    


    
}

void map::initia(romeo::Resource* r){


//////
    int count = 0;
      for(int i =Map_Width ; i>0; i--){
          for(int j =0 ; j<Map_Height; j++){
              sf::Vector3i location(i,j,layer);
                MakeTile(4 ,location,r,count );
                count++;
                }
            }
setEntityCount(0);
MakeEntity(3 ,sf::Vector3i(20,20,3),r,count) ;
MakeEntity(3 ,sf::Vector3i(13,20,3),r,count) ; 
addcursor(r);
             

        }
        

    
void map::MakeTile(int Type,sf::Vector3i location,romeo::Resource* r,int count){
                int q = makeTileID(location.x,location.y);/////making unique key 
                map_map.erase(q);
                romeo::Tile t(Type,location,r);
                t.setHighlighted(false);
                t.setTileID(q);
                map_map.insert(std::make_pair( q,t));
                TileIDList[count] = q;
    
}
void map::MakeEntity(int Type,sf::Vector3i location,romeo::Resource* r,int count){
               
                map_entity.erase(EntityCount);
                romeo::Entity t(Type,location,r);
                map_entity.insert(std::make_pair( EntityCount,t));
                map_entity[EntityCount].ResetEntity(map_entity[EntityCount].getType());
                map_entity[EntityCount].setattack_Range(EntityCount);
                map_entity[EntityCount].setmove_Range(EntityCount + 3);
                map_entity[EntityCount].setmy_map(map_map);
                map_entity[EntityCount].setID(0);
                map_entity[EntityCount].sethp(100);
                map_entity[EntityCount].setAttack(17);
                
                setEntityCount(1);
}


void map::addcursor(romeo::Resource* r){
                romeo::Tile cursor(0,sf::Vector3i(10,15,2),r);
                map_map.insert(std::make_pair( 0,cursor));
                cid = makeTileID(map_map[0].getLocation().x,map_map[0].getLocation().y);  
    }
void map::SetCursor(sf::Vector3i temploca){
    /////////update the location of cursor //////////
                temploca.z += 2; ////////////2 here is the elevation above tile expected to be const regardless of tilewidth////////
                map_map[0].setLocation(temploca) ;
                map_map[0].ResetTile(map_map[0].getType());
    ////////reset center of the camera to cursor ///////////
                Map_View->setCenter(map_map[0].getSprite()->getPosition().x,map_map[0].getSprite()->getPosition().y);
    ////////update the cid for corrext draw order /////////
                cid = makeTileID(temploca.x,temploca.y);
    
    
}
void map::setHighlighted(bool b){ tilesHighlighted = b;}
bool map::getHighlighted(){ return tilesHighlighted;}
void map::setGuiIsOpen(bool b){GuiIsOpen = b;}
bool map::getGuiIsOpen(){return GuiIsOpen;}
void map::setWindow(sf::RenderWindow* window,sf::View* map_v){
     mywindow = window;
     Map_View = map_v;
     windowDim = mywindow->getSize();
     Map_View->setCenter(map_map[0].getSprite()->getPosition().x,map_map[0].getSprite()->getPosition().y);
    }    
void map::setCamera(int x,int y){ Map_View->setCenter(x,y);}
void map::setGUI(romeo::GUI* g){ UI = g;}
void map::setClickPos(sf::Vector2i position){
    clickPos.x = position.x;
    clickPos.y = position.y;}

/////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////EVENT HANDLING///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void map::processEvent(romeo::revt e){

    
}
romeo::revt map::addEvent(sf::Vector3i l , int t , int at){
    romeo::revt e;
    e = {.iDestinationLocation = l,
         .type = t,
         .additionalInformation = at};
      std::cout << "adding e----::::"<< t <<std::endl;  
      std::cout << "adding t----::::"<< t <<std::endl;  
      std::cout << "adding at----::::"<< at <<std::endl;  
        return e;
    
}
void map::handleKeys(sf::Event e){

    
  if(UI->getFocus()){/*  UI->handleKeys(e);*/ }else{
    for(int i = 0; i<map_entity.size(); i++){
      if(map_entity[i].cBattleMenu.getFocus()){
          map_entity[i].handleKeys(e);
          goto endofHandleKeys;
    }
          
          
          
          
    }
    
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
        
            
            if (e.key.code == sf::Keyboard::Add){//////
                 layer += 1;
               
            }
            
            if (e.key.code == sf::Keyboard::Subtract){//////
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

              if (e.key.code == sf::Keyboard::Z){
                  
                     }
                          
                          
           if (e.key.code == sf::Keyboard::X){//////
                 UI->setFocus(false);  
                                            }
                                      
            
            
        }
        
        
        
        
          if (e.type == sf::Event::KeyReleased){
            if (e.key.code == sf::Keyboard::Z){
                int entity_inputmode = 1;
                int entity_additional = 0;
                 for(int j = 0; j<map_entity.size(); j++){
                     if(map_entity[j].getinput_mode() == 1){
                         map_entity[j].setinput_mode(-1);
                         entity_additional = map_entity[j].getAttack();
                    }
                     
                }
                
                for(int i = 0; i<map_entity.size(); i++){  
                // sf::Vector3i tmp =map_map[0].getLocation();
                  map_entity[i].handleEvent(addEvent(map_map[0].getLocation(),entity_inputmode,entity_additional));
                    
                }

                 
      /////////////////////////            

///////////////////////////////
            }
              
              
        }  
            }////////end UI->getFocus else///////
            
endofHandleKeys:;
}

void map::setEntityCount(int i){EntityCount+=i;}
int map::getEntityCount(){return EntityCount;}
void map::setMapWidth(int width){Map_Width = width; }
int  map::getMapWidth(){return Map_Width;}
void map::setMapHeight(int height){Map_Height = height;}
int  map::getMapHeight(){return Map_Height;}
int map::getSelected(){return selected;}
void map::setSelected(int sel){selected = sel;}   
int map::makeTileID(int i , int j){
    int id = ((i+j)*Tile_Width) + i-j*Tile_Width*0.5 ;
        return id;
}
romeo::Tile map::getTile(int i ,int j){return map_map[makeTileID(i,j)];}

void map::renderTiles(sf::RenderWindow* mywindow,float t,romeo::Resource* r){
    int count  = 0;
    for(int i =Map_Width ; i>0; i--){/////////iterating through tiles/////////
    for(int j =0 ; j<Map_Height; j++){
        int q = TileIDList[count];
             if(clickPos.x != 0 && clickPos.y != 0){/////////do i need to check for click ??
               if(map_map[q].Am_I_Here(clickPos)){//////////yes,then for each tile compare
                   map_map[q].setLocationZ(layer);//set its layer
                   map_map[q].ResetTile(selected);//reset it 
                                    }
                                }
 //////////////////////////////////DRAW TILE////////////////////////////////////                                        
                   map_map[q].render(mywindow,t);/////////draw the tile
               if(map_map[q].getTileID() == cid){  /////////is the cursor here ??
//////////////////////////////////DRAW CURSOR////////////////////////////////////
                   map_map[0].render(mywindow,t); /////yes cursor will draw here as well
                                       /// map_map[0].renderHitbox(mywindow,t);
                                  }
                            
    for(int i = 0; i<map_entity.size(); i++){  ///////////entity iterator////////   
       if(map_map[q].getLocation().x == map_entity[i].getLocation().x &&   map_map[q].getLocation().y==map_entity[i].getLocation().y){    
 //////////////////////////////////DRAW ENTITYS//////////////////////////////////// 

           
               map_entity[i].render(mywindow,t);
             
                }
            }/////////end of entity iterator
              
                 if(!tilesHighlighted){
                     map_map[q].setHighlighted(false);
                                    }
                        count++;
                                                }//////////end of map_height loop
                                            }////////end of hap_width loop
    }

    
void map::render(sf::RenderWindow* mywindow,float t,romeo::Resource* r){ 
        mywindow->setView((rm->getMapView()));
        renderTiles(mywindow,t,r);
            for(int i = 0; i<map_entity.size(); i++){ 
             if(map_entity[i].cBattleMenu.getFocus()){
                 map_entity[i].cBattleMenu.render(mywindow,t);
                 
            }   
            }
        
            }
;
}
