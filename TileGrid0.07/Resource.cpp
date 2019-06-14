#include "Resource.h"
#include <iostream>

namespace romeo{
Resource::Resource(){
       
    
}
void Resource::load_TileSet(std::string g){
            std::cout<<"Getting Resouces" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;  
        }
    
}
sf::Image Resource::return_Image(std::string g){   ////////////returning image from TileSet
            std::cout<<"Getting Image" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl; 
             
        }
        
        return  Tileset_Image;
    
}
bool Resource::Cut_Image(sf::Image Tileset_Image,int TileWidth ){///////////dividing TileSet into tiles and assigning to pointer array///////////
    if(Tileset_Image.getSize().x <=1){
        load_TileSet("assets/terra.png");
         std::cout<<"Tileset_Image was not loaded ,loading from cutup" << std::endl;
    }
    bool done = false;
    while(!done){
       // int TileWidth = 64;
    int count =0;
     for (int i  = 0 ; i < Tileset_Image.getSize().x/TileWidth; i++){
            for (int j  = 0 ; j < Tileset_Image.getSize().y/TileWidth; j++){
               if (!Textures[count].loadFromImage(Tileset_Image,sf::IntRect(i*TileWidth,j*TileWidth,64,64))){
                    std::cout<<"Failed to load tex" << std::endl;
                        }   count++;
                         std::cout<<count << std::endl; 
                   }
             }
             done = true;
            std::cout<<"cutting" << std::endl;   
        
       std::cout<<"done" << std::endl; 
    }
    return true;
}
void Resource::handleKeys(sf::Event e){///////////////////////for reloading assets/////////////
    if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::R)){
    std::cout<<"Reloading Terra" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;
            
        }
    
        
        
    }
}
sf::Texture* Resource::getTexture(int i){ //////////////returning chosen texture pointer////////////
    return &Textures[i] ;
    
}

;
}
 
