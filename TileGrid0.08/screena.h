#ifndef SCREENA_H
#define SCREENA_H
#include "map.h"
#include "screen.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class screena:public screen{
    private:
        sf::RenderWindow* mywindow;
        sf::View* gui_view;
        sf::View* map_view;
    public:
     
        romeo::map mapa;
        
        
    screena();
    void initi(int,int,int,romeo::Resource*);
    void setWindow(sf::RenderWindow* window,sf::View* gui_v,
sf::View* map_v);
    void handleKeys(sf::Event e)override;
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    void renderGUI(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    
};
}
#endif
