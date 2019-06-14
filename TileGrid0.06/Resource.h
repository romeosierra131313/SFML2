#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Resource{
    
    private:
      sf::Texture t;
    sf::Image Tileset_Image;
    sf::Texture* Textures[64];
    public:
 
    Resource();
    void handleKeys(sf::Event e);
    sf::Texture* getTexture(int);
    
};
}
#endif

