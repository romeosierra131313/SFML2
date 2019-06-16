#include "screen.h"
#include "screena.h"
#include <map>
#include <iostream>

namespace romeo{
     
     
Tile::Tile(){

}
Tile::Tile(sf::Texture* tex,sf::Vector3i loca,int Tile_Width){
    TileWidth = Tile_Width;
    bool done = false;
    while(!done){
    
    hitbox.setSize(sf::Vector2f(Tile_Width,Tile_Width));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2);
    
    setLocation(loca);
    S.setTexture(*tex);
   
    sf:: Vector3i temploca = convert_to_Iso(location);
     S.setPosition(temploca.x,temploca.y);
     hitbox.setPosition(temploca.x,temploca.y);
    
    done = true;
    }
    
}
    void Tile::setTexture(sf::Texture* Tex){
        T= Tex;
        
    }
    sf::Texture Tile::getTexture(){
        return *T;
        
    }
    void Tile::setSprite(sf::Texture* T){
        S.setTexture(*T);
        
    }
    sf::Vector3i Tile::convert_to_Iso(sf::Vector3i Location){
        sf::Vector3i converted((Location.x+Location.y)*TileWidth,((Location.x-Location.y)*TileWidth*0.5),0);
        
        return converted;
        
    }
    void Tile::setLocation(int x,int y,int z){
        location.x = x;
        location.y = y;
        location.z = z;
        
    }
    void Tile::setLocation(sf::Vector3i loca){
        location = loca;
        
    }
    sf::Vector3i Tile::getLocation(){
        return location;
        
    }
    bool Tile::Am_I_Here(sf::Vector2i here){
        
         if(S.getGlobalBounds().contains(here.x,here.y-30)){
            std::cout<<S.getPosition().x<<"~~~~" <<S.getPosition().y<<std::endl;
            
            return true;
        }
        return false;
    }
    void Tile::render(sf::RenderWindow* mywindow,float t){
        
        mywindow->draw(S);
        mywindow->draw(hitbox);
        
    }

;
} 
