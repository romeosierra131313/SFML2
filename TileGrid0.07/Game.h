 
#ifndef GAME_H
#define GAME_H
#include "screen.h"
#include "screena.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>

namespace romeo{
 

class Game{
    private:
        
        sf::Vector2f newCenter;
    
    public:
    
    romeo::Resource Resource_Manager;
    romeo::screen* screen;
    
        
    Game();
    void setScreen(romeo::screen* current_screen);
    void handleKeys(sf::Event e,sf::View*,sf::RenderWindow*);
    void render(sf::RenderWindow*,float); 
    
};
}
#endif
