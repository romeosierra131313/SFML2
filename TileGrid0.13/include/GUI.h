 
#ifndef GUI_H
#define GUI_H
#include "include/revt.h"
#include "include/TextBox.h"
#include "include/Entity.h"
#include "include/Tile.h"
#include "include/Calndar.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class GUI{
    private:
        bool hasFocus;
        bool Editmode;
        bool hasSelectedEntity;
        bool hasMenuSelection;
        sf::Vector2i Menu_Position;
        int TileWidth;
        sf::Vector2i clickPos;
        sf::RenderWindow* mywindow;
        sf::View* gui_view;
        int selected;
       
        romeo::TextBox my_TextBox;
        romeo::TextBox myTextBoxes[4];
        romeo::Tile myTiles[64];
        romeo::Entity* Selected_Entity;
        sf::RectangleShape Background;
        float Time;
        float LastPressTime;
        
        
    public:
         romeo::Calndar cCalndar;
        
    int menuselection ;
    std::queue<romeo::revt> event;    
        
    GUI();
    void initi(int,romeo::Resource*,sf::RenderWindow*);
    void setWindow(sf::RenderWindow*,sf::View*);
    void setTiles(romeo::Resource* r);
    void setSelected_Entity(romeo::Entity*); 
    romeo::Entity* getSelected_Entity(); 
    void setEditmode(bool b);
    bool getEditmode();
    void sethasMenuSelection(bool b);
    bool gethasMenuSelection();
    
    void setFocus(bool b);
    bool getFocus();
    void sethasSelectedEntity(bool);
    bool gethasSelectedEntity();
    
    void setMenu_Position(sf::Vector2i);
    sf::Vector2i getMenu_Position();
    void setSelected(int);
    int getSelected();
    void setClickPos(sf::Vector2i);
    void setTime(float);
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*);  
    
};
}
#endif
