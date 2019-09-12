#include "include/Tile.h"
#include <map>
#include <iostream>

namespace romeo{
     
     
Tile::Tile(){

}
Tile::Tile(int T_Type,sf::Vector3i loca,romeo::Resource* rm){
    
    //////////////////////////////////////////////////////////////////
    ///////////ISO TILE
    /////////////////////////////////////////////////////////////////
    
    TileWidth = rm->TileWidth;
    r = rm;
    TileType = T_Type;
    hitbox.setSize(sf::Vector2f(TileWidth,TileWidth));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2);
    
    setLocation(loca);
    S.setTexture(*(r->getTexture(TileType)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    
    
}

Tile::Tile(sf::Texture* tex,sf::Vector3i loca,int& Tile_Width,int i){
    
    //////////////////////////////////////////////////////////////////
    ///////////GRID TILE---------NON ISO//////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    TileWidth = Tile_Width;
    
    hitbox.setSize(sf::Vector2f(Tile_Width,Tile_Width));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Black);
    hitbox.setOutlineThickness(2);
    
    setLocation(loca);
    S.setTexture(*tex);
    S.setPosition(location.x*Tile_Width,location.y*Tile_Width);
    hitbox.setPosition(location.x*Tile_Width,location.y*Tile_Width);
    
    
}

void Tile::ResetTile(int T_Type){
    TileType = T_Type;
    S.setTexture(*(r->getTexture(TileType)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    
}
void         Tile::setHighlighted(bool b){showHitbox = b; }
bool         Tile::getHighlighted(){return showHitbox;}
void         Tile::setType(int i){ TileType = i;}
int          Tile::getType(){return TileType;}
void         Tile::setTileID(int id){TileID = id;}
int          Tile::getTileID(){return TileID ;}
void         Tile::setTexture(sf::Texture* Tex){T= Tex;}
sf::Texture* Tile::getTexture(){return T;}
void         Tile::setSprite(sf::Texture* T){ S.setTexture(*T);}
sf::Sprite*  Tile::getSprite(){return &S;}
void         Tile::setLocationZ(int z){location.z = z;}

sf::Vector3i Tile::convert_to_Iso(sf::Vector3i Location){
        sf::Vector3i converted((Location.x+Location.y)*TileWidth/2,
                               ((Location.x-Location.y)*(TileWidth*-0.25))-(TileWidth/4)*Location.z,Location.z);
        
        return converted;
        
    }
void Tile::setLocation(sf::Vector3i loca){
        location = loca;
        
    }
sf::Vector3i Tile::getLocation(){
        return location;
        
    }
bool Tile::Am_I_Here(sf::Vector2i here){
        
         if(S.getGlobalBounds().contains(here.x,here.y)){
            return true;
        }
        return false;
    }
void Tile::render(sf::RenderWindow* mywindow,float t){
        
        mywindow->draw(S);
         if(getHighlighted()){
              mywindow->draw(hitbox);
             
        }
        
    }
;
} 
