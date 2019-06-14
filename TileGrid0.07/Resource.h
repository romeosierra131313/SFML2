#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Resource{
    
    private:
    sf::Image Tileset_Image;
    sf::Texture Textures[64];
    
    public:

    Resource();
    void load_TileSet(std::string g);
    sf::Image return_Image(std::string g);
    bool Cut_Image(sf::Image,int);
    void handleKeys(sf::Event e);
    sf::Texture* getTexture(int);
    
};
}
#endif

