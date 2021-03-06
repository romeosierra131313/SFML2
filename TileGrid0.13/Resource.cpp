#include "include/Resource.h"
#include <iostream>

namespace romeo{
Resource::Resource(){
    std::cout<<"RESOUCR" << std::endl;
    
    
bool done = false;
        if (!Back_Image.loadFromFile("assets/stand.jpg")){
             std::cout<<"Failed to load terra" << std::endl;}
                    Cut_Image(return_Image("assets/terra.png"),TileWidth);
        if (!fnt.loadFromFile("assets/arial.ttf")){
             std::cout<<"Failed to load font" << std::endl;}
    
}
void Resource::load_TileSet(std::string g){
            std::cout<<"Getting Resouces" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;  
        }
        
    
}
sf::Image Resource::return_Image(std::string g){   ////////////returning image from TileSet
            std::cout<<g << std::endl;
        if (!Tileset_Image.loadFromFile(g)){
             std::cout<<"Failed to load terra" << std::endl; 
             
        }
        
        return  Tileset_Image;
    
}
sf::Image Resource::return_Back(std::string g){   ////////////returning image from TileSet
            std::cout<<g << std::endl;
        if (!Back_Image.loadFromFile(g)){
             std::cout<<"Failed to load terra" << std::endl; 
             
        }
        
        return  Back_Image;
    
}
void Resource::addView(sf::View* gui_v,sf::View* map_v){
 
    gui_view = gui_v;
    map_view = map_v;
 
}
sf::View Resource::getGUIView(){ return *gui_view;}
sf::View Resource::getMapView(){ return *map_view;}
void Resource::Cut_Image(sf::Image Tileset_Image,int TileWidth ){///////////dividing TileSet into tiles and assigning to pointer array///////////
    if(Tileset_Image.getSize().x <=1){
        load_TileSet("assets/terra.png");
         std::cout<<"Tileset_Image was not loaded ,loading from cutup" << std::endl;
    }
    TilesetDim.x = Tileset_Image.getSize().x;
    TilesetDim.y = Tileset_Image.getSize().y;
    bool done = false;
    while(!done){
       // int TileWidth = 64;
    int count =0;
     for (int i  = 0 ; i < TilesetDim.x/TileWidth; i++){
            for (int j  = 0 ; j < TilesetDim.y/TileWidth; j++){
               if (!Textures[count].loadFromImage(Tileset_Image,sf::IntRect(i*TileWidth,j*TileWidth,TileWidth,TileWidth))){
                    std::cout<<"Failed to load tex" << std::endl;
                        }   count++;
                   }
             }
             done = true;
            std::cout<<"cutting" << std::endl;   
        
       std::cout<<"done" << std::endl; 
    }
}
void Resource::handleKeys(sf::Event e){///////////////////////for reloading assets/////////////
    if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::R)){
    std::cout<<"Reloading Terra" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;
            
        }Cut_Image(return_Image("assets/terra.png"),64);
    
        
        
    }
}
sf::Texture* Resource::getTexture(int i){ //////////////returning chosen texture pointer////////////
    return &Textures[i] ;
    
}
sf::Vector2i Resource::getTilesetDim(){
     return TilesetDim;
    
}

sf::Font* Resource::getFont(){
    return &fnt;
    
}
int Resource::getTileWidth(){
    return TileWidth;
    
}
;
}
 
