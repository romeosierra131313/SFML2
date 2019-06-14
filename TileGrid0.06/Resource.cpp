#include "Resource.h"
#include <iostream>

namespace romeo{
      
         
Resource::Resource(){
      bool done = false;
while(!done){      
        std::cout<<"Getting Resouces" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;
            
        } done = true;}
        
          
    sf::Texture tt.loadFromImage(Tileset_Image,sf::IntRect(0,0,64,64));
    Textures[0] = &tt; 
}

void Resource::handleKeys(sf::Event e){
    if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::R)){
    std::cout<<"Reloading Terra" << std::endl;
        if (!Tileset_Image.loadFromFile("assets/terra.png")){
             std::cout<<"Failed to load terra" << std::endl;
            
        }
    
        
        
    }
}
sf::Texture* Resource::getTexture(int i){
    std::cout<<"GETTING TEX" << std::endl;

    return Textures[0] ;
    
}

;
}
 
