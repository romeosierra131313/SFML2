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
    sf::RenderWindow* mywindow;
    sf::View* Map_View;
    sf::Vector2i clickPos;
    int selected;
    int layer;
    bool showHitbox;
    
    
    
    public:
        std::map<int,romeo::Tile> map_map;
        
        
    map();
    void initia(int,int,int,romeo::Resource*);
    void setWindow(sf::RenderWindow*,sf::View*);
    void handleKeys(sf::Event e);
    void setSelected(int);
    int  getSelected();
    void setClickPos(sf::Vector2i); 
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*); 
    
};
}
#endif
 
