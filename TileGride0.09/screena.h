#ifndef SCREENA_H
#define SCREENA_H
#include "map.h"
#include "GUI.h"
#include "screen.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class screena:public screen{
    private:
        sf::RenderWindow* mywindow;
        sf::Texture* selected;
    public:
        int window_Width;
        int window_Height;
        romeo::map mapa;
        romeo::GUI gui;
        
        
    screena();
    void initi(int,int,int,romeo::Resource*);
    void setWindow(sf::RenderWindow* window,int,int,sf::View*,sf::View*);
    void handleKeys(sf::Event e)override;
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    void renderGUI(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    
};
}
#endif
