#ifndef TILE_H
#define TILE_H
#include "include/Resource.h"
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Tile{
    
    private:
    bool showHitbox;
    int TileID;
    int TileType;
    sf::RectangleShape hitbox;
    sf::Texture* T;
    sf::Sprite S;
    sf::Vector3i location;
    int TileWidth;
    romeo::Resource* r;
    
    public:
    
    

    
    Tile();
    Tile(int,sf::Vector3i,romeo::Resource*);
    Tile(sf::Texture*,sf::Vector3i,int&,int);
    void ResetTile(int);
    
    void setTileID(int);
    int getTileID();
    void setType(int);
    int getType();
    void setHighlighted(bool);
    bool getHighlighted();
    void setTexture(sf::Texture*);
    sf::Texture* getTexture();
    void setSprite(sf::Texture*);
    sf::Sprite* getSprite();
    sf::Vector3i convert_to_Iso(sf::Vector3i);
    void setLocationZ(int);
    void setLocation(sf::Vector3i);
    sf::Vector3i getLocation();
    bool Am_I_Here(sf::Vector2i);
    
    void render(sf::RenderWindow*,float); 
    
    
};
}
#endif


