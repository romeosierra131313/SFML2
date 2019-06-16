#ifndef TILE_H
#define TILE_H
#include "Resource.h"
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Tile{
    
    private:
    sf::RectangleShape hitbox;
    sf::Texture* T;
    sf::Sprite S;
    sf::Vector3i location;
    int TileWidth;
    
    
    public:
    int TileID;
    
    Tile();
    Tile(sf::Texture*,sf::Vector3i,int);
    void setTexture(sf::Texture*);
    sf::Texture getTexture();
    void setSprite(sf::Texture*);
    sf::Vector3i convert_to_Iso(sf::Vector3i);
    void setLocation(int,int,int);
    void setLocation(sf::Vector3i);
    sf::Vector3i getLocation();
    bool Am_I_Here(sf::Vector2i);
    
    void render(sf::RenderWindow*,float); 
    
    
};
}
#endif


