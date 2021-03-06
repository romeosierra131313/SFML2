#include "include/screena.h"
#include <iostream>

namespace romeo{   
       
screena::screena(){
    std::cout<<"default screena called";
}



void screena::initi(int TileWidth,int MapWidth,int MapHeight,romeo::Resource* r){
     Resource = r;
     mapa = romeo::map(TileWidth,MapWidth,MapHeight,r);    
     mapa.initia(r);
     gui.initi(TileWidth,r,mywindow);
     
   
    
}
void screena::setWindow(sf::RenderWindow* window,int window_Wdth,int window_Heght,sf::View* gui_view,sf::View* map_view){
    mywindow = window;
    window_Width =window_Wdth;
    window_Height=window_Heght; 
    gui.setWindow(mywindow,window_Width,window_Height,gui_view);
    mapa.setWindow(mywindow,map_view);
    
    
}

void screena::loadMap(){
    std::string g; 
    int TType;
    int count = 1;
    int TileCount = 1;
    bool reachedTiles = false;
    sf::Vector3i location;       
     
    
            mapReader.open("maps/level1.txt");
            if(!mapReader.is_open()){
                std::cout <<"failed";
                    }
            if(mapReader.is_open()){
                std::cout <<"opened file";
                    while(!mapReader.eof()){
                       mapReader >> g; 
                             
                                switch (count){
                                    case 0:
                                        break;
                                    case 1:
                                         TType = stoi(g);
                                         std::cout <<"type"<< TType<<std::endl;
                                        break;
                                    case 2:
                                         location.x = stoi(g);
                                        break;    
                                    case 3:
                                         location.y = stoi(g);
                                        break;
                                    case 4:
                                        location.z = stoi(g);
                                         
                                        break;
                            }
                            
                        
                                    if(count ==4){
                                         mapa.MakeTile( TType,location,Resource,TileCount);  
                                         TileCount++;
                                         count = 0;
                                          
                                     } count++;
                                  
                        
                    }  
            mapa.addcursor(Resource);
            mapReader.close();
    }
    
}
void screena::loadMap(std::string g){
    
    
}

void screena::saveMap(romeo::map* map){
    std::cout <<"saving Map";
    
    
    mapWriter.open("maps/level1.txt");
    if(!mapWriter.is_open()){
        std::cout <<"loading map failed";
        
        
    }
    if(mapWriter.is_open()){
        std::cout <<"opened";
       
          for(int i = map->getMapWidth(); i >0 ; i --){
             for(int j = 0; j < map->getMapHeight() ; j ++){
            
              romeo::Tile t = map->getTile(i,j);
              mapWriter << t.TileType << std::endl;
              std::cout <<  t.TileType<<std::endl;
              mapWriter << t.getLocation().x << std::endl;
              mapWriter << t.getLocation().y << std::endl;
              mapWriter << t.getLocation().z << std::endl;
             
              
          }
        }
        
         mapWriter.close();
    }
}

void screena::handleKeys(sf::Event e){
     mapa.handleKeys(e);
     gui.handleKeys(e);
     
              if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Q)){//////escape!!/////
             if(gui.getFocus()){ 
                 gui.setFocus(false);
                 
            }else{ 
                gui.setFocus(true);
                
            }
            
                }
     
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::E)){//////escape!!/////
             if(gui.getFocus()){ 
                 gui.setFocus(false);
                 gui.setEditmode(false);
                 
            }else{ 
                gui.setFocus(true);
                gui.setEditmode(true);
                
            }
            
                }
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::B)){//////escape!!/////
             mapa.initia(Resource);
            
                }
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::M)){//////escape!!/////
             saveMap(&mapa);
            
                }
         if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::N)){//////escape!!/////
             loadMap();
            
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
