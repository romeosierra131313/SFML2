#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Resource{
    
    private:
    sf::Image Tileset_Image;
    sf::Image Back_Image;
    sf::Texture Textures[64];
    sf::Vector2i TilesetDim;
    sf::Font fnt;
    
    
    public:
     
        int TileWidth = 64;
        
    Resource();
    void load_TileSet(std::string g);
    sf::Image return_Image(std::string g);
    sf::Image return_Back(std::string g);
    void Cut_Image(sf::Image,int);
    void handleKeys(sf::Event e);
    sf::Texture* getTexture(int);
    sf::Vector2i getTilesetDim();
    sf::Font* getFont();
    int getTileWidth();
    
};
}
#endif

