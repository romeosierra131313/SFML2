#ifndef SCREENA_H
#define SCREENA_H
#include "include/map.h"
#include "include/GUI.h"
#include "include/screen.h"
#include "include/Tile.h"
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <fstream>
#include <string>

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
        romeo::Resource* Resource;
        std::ofstream mapWriter;
        std::ifstream mapReader;
        
        
    screena();
    void initi(int,int,int,romeo::Resource*);
    void setWindow(sf::RenderWindow* window,int,int,sf::View*,sf::View*);
    void loadMap();
    void loadMap(std::string);
    void saveMap(romeo::map*);
    void handleKeys(sf::Event e)override;
    void render(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    void renderGUI(sf::RenderWindow* mywindow,float,romeo::Resource*)override; 
    
};
}
#endif
