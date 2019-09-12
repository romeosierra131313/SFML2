#ifndef MAP_H
#define MAP_H
#include "include/Entity.h"
#include "include/GUI.h"
#include "include/Tile.h"
#include <map>
#include <SFML/Graphics.hpp>

namespace romeo{
    
class map{
private:
    int Tile_Width;
    int Map_Width;
    int Map_Height;
    int EntityCount;
    sf::RenderWindow* mywindow;
    sf::View* Map_View;
    sf::Vector2i clickPos;///////used to compare with tile location for ident
    int selected;//////used as reference to get texture from refernce
    int layer;////////used to raise and lower tiles by this*.25*tilewidth
    bool showHitbox;
    bool GuiIsOpen;
    sf::Vector2u windowDim;
    int cid;//////////used to compare with tiles so cursor can be drawn behind tiles 
    bool tilesHighlighted;
    
    
    
    public:
        std::map<int,romeo::Tile> map_map;
        std::map<int,romeo::Entity> map_entity;
        int TileIDList[4096];
        romeo::Resource* rm;
        romeo::GUI* UI;
        
    map();
    map(int,int,int,romeo::Resource*);
    void initia(romeo::Resource*);
    void setWindow(sf::RenderWindow*,sf::View*);
    void setCamera(int,int);
    void setGUI(romeo::GUI*);
    void MakeTile(int,sf::Vector3i,romeo::Resource* ,int );
    void MakeEntity(int,sf::Vector3i,romeo::Resource* ,int );
    void addcursor(romeo::Resource*);
    void SetCursor(sf::Vector3i);
    void handleKeys(sf::Event e);
    void processEvent(romeo::revt);
    romeo::revt addEvent(sf::Vector3i,int,int);
    void setEntityCount(int);
    int getEntityCount();
    void setMapWidth(int);
    int getMapWidth();
    void setMapHeight(int);
    int getMapHeight();
    void setSelected(int);
    int  getSelected();
    void setGuiIsOpen(bool);
    void setHighlighted(bool);
    bool getHighlighted();
    bool  getGuiIsOpen();
    void setClickPos(sf::Vector2i); 
    int  makeTileID(int,int);
    romeo::Tile getTile(int,int);
    void render(sf::RenderWindow*,float,romeo::Resource*); 
    void renderTiles(sf::RenderWindow*,float,romeo::Resource*); 
    void renderEntities(sf::RenderWindow*,float,romeo::Resource*); 
    
};
}
#endif
 
