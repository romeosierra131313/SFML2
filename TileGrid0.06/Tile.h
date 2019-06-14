#ifndef TILE_H
#define TILE_H
#include "Resource.h"
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Tile{
    
    private:
    
    sf::Texture T;
    sf::Sprite S;
    sf::Vector3i location;
    int TileWidth;
    
    public:
 
    Tile();
    Tile(sf::Texture*,sf::Vector3i,int);
    void setTexture(sf::Texture);
    sf::Texture getTexture();
    void setSprite(sf::Texture);
    sf::Vector3i convert_to_Iso(sf::Vector3i);
    void setLocation(int,int,int);
    void setLocation(sf::Vector3i);
    sf::Vector3i getLocation();
    
    void render(sf::RenderWindow*,float); 
    
    
};
}
#endif


