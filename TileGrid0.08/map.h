#ifndef MAP_H
#define MAP_H
#include "Tile.h"
#include <map>
#include <SFML/Graphics.hpp>

namespace romeo{
    
class map{
private:
    int Tile_Width;
    int Map_Width;
    int Map_Height;
    sf::View Map_View;
    sf::Vector2i clickPos;
    public:
        std::map<int,romeo::Tile> map_map;
        
        
    map();
    void initia(int,int,int,romeo::Resource*);
    void handleKeys(sf::Event e);
    void changeTile(sf::Vector2i,romeo::Resource*); 
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*); 
    
};
}
#endif
 
