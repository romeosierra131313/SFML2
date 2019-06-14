#ifndef SCREENA_H
#define SCREENA_H
#include "screen.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class screena:public screen{
private:
    int T_Width;
    int M_Width;
    int M_Height;
    public:
        romeo::Resource* resource_manager;
        std::map<int,romeo::Tile> map;
        
        
    screena();
    screena(int,int,int);
    void nit(romeo::Resource*);
    void handleKeys(sf::Event e)override;
    void render(sf::RenderWindow* mywindow,float)override; 
    
};
}
#endif
