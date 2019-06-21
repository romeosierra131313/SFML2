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
    sf::Vector2i clickPos;///////used to compare with tile location for ident
    int selected;//////used as reference to get texture from refernce
    int layer;////////used to raise and lower tiles by this*.25*tilewidth
    bool showHitbox;
    sf::Vector2u windowDim;
    int cid;//////////used to compare with tiles so cursor can be drawn behind tiles 
    sf::Texture BackGround_T;
    sf::Sprite  BackGround_S;
    int BackGround_X;
    int BackGround_Y;
    int BackGround_D_X;
    int BackGround_D_Y;
    int BackGround_D_Offeset_X;
    int BackGround_D_Offeset_Y;
    
    
    
    public:
        std::map<int,romeo::Tile> map_map;
        int TileIDList[4096];
        
        
    map();
    map(int,int,int,romeo::Resource*);
    void initia(romeo::Resource*);
    void setWindow(sf::RenderWindow*,sf::View*);
    void setCamera(int,int);
    void SetCursor(sf::Vector3i);
    void handleKeys(sf::Event e);
    void setSelected(int);
    int  getSelected();
    void setClickPos(sf::Vector2i); 
    int  makeTileID(int,int);
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*); 
    
};
}
#endif
 
