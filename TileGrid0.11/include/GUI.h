 
#ifndef GUI_H
#define GUI_H
#include "include/TextBox.h"
#include "include/Tile.h"
#include "include/map.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class GUI{
    private:
        bool hasFocus;
        bool Editmode;
        
        int window_Width;
        int window_Height;
        int TileWidth;
        sf::Vector2i clickPos;
        sf::RenderWindow* mywindow;
        sf::View* gui_view;
        int selected;
        romeo::map* mapa;
        romeo::TextBox my_TextBox;
        romeo::TextBox myTextBoxes[4];
        romeo::Tile myTiles[64];
        sf::RectangleShape Background;
        
    public:
     
        
        
    GUI();
    void initi(int,romeo::Resource*,sf::RenderWindow*);
    void setWindow(sf::RenderWindow*,int,int,sf::View*);
    void setTiles(romeo::Resource* r);
    
    void setEditmode(bool b);
    bool getEditmode();
    void setFocus(bool b);
    bool getFocus();
    
    void setSelected(int);
    int getSelected();
    
    void setClickPos(sf::Vector2i);
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*);  
    
};
}
#endif
