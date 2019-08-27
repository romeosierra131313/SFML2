#ifndef TILE_H
#define TILE_H
#include "include/Resource.h"
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Tile{
    
    private:
    
    
    
    public:
    int TileID;
    int TileType;
    sf::RectangleShape hitbox;
    sf::Texture* T;
    sf::Sprite S;
    sf::Vector3i location;
    int TileWidth;
    romeo::Resource* r;
    
    Tile();
    Tile(int,sf::Vector3i,romeo::Resource*);
    Tile(sf::Texture*,sf::Vector3i,int&,int);
    void ResetTile(int);
    
    void setTileID(int);
    int getTileID();
    
    void setTexture(sf::Texture*);
    sf::Texture* getTexture();
    void setSprite(sf::Texture*);
    
    sf::Vector3i convert_to_Iso(sf::Vector3i);
    void setLocationZ(int);
    void setLocation(sf::Vector3i);
    sf::Vector3i getLocation();
    bool Am_I_Here(sf::Vector2i);
    
    void render(sf::RenderWindow*,float); 
    void renderHitbox(sf::RenderWindow*,float);
    
    
};
}
#endif


