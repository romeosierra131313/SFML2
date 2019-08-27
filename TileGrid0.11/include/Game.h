 
#ifndef GAME_H
#define GAME_H
#include "include/screen.h"
#include "include/screena.h"
#include "include/Resource.h"
#include <SFML/Graphics.hpp>

namespace romeo{

        
        

class Game{
    private:
        romeo::screen* screen ;
        sf::RenderWindow* mywindow;
        sf::View* gui_view;
        sf::View* map_view;
        sf::Vector2f newCenter;
    
    public:
    int Tilewidth=64;
    romeo::Resource rm;
    romeo::screena a;
    
        
    Game();
    void setWindow(sf::RenderWindow* window,sf::View* gui_v,
sf::View* map_v);
    void setScreen(romeo::screen* current_screen);
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow*,float); 
    
};
}
#endif
