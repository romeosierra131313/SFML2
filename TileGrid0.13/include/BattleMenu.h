  
#ifndef BATTLEMENU_H
#define BATTLEMENU_H
#include "include/TextBox.h"
#include "include/Resource.h"
#include "include/Tile.h"
#include <string>
#include <SFML/Graphics.hpp>

namespace romeo{
    
class BattleMenu{
    private:
        bool hasFocus;
        int window_Width;
        int window_Height;
        int TileWidth;
        sf::Vector2i clickPos;
        sf::RenderWindow* mywindow;
        sf::View* gui_view;
        romeo::TextBox myTextBoxes[4];
        sf::RectangleShape Background;

        
    public:
        
        sf::Text text_hp;
        sf::Text text_attack;
        sf::Text text_inputmode;
        
     romeo::Resource* r;
     int menuselection ;
     sf::Vector2i Menu_Position;
        
    BattleMenu();        
    void initi(int,romeo::Resource*);
    void setWindow(int,int,sf::View*);
    void setMenu_Position(sf::Vector2i);
    sf::Vector2i getMenu_Position();
    void setFocus(bool b);
    bool getFocus();
    
    void setClickPos(sf::Vector2i);
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow* mywindow,float);  
    
};
}
#endif

