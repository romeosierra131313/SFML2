 
#ifndef GAME_H
#define GAME_H
#include "screen.h"
#include "screena.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class Game{

    
    public:

    romeo::screen* screen;
    romeo::Resource Resource_Manager;
        
    Game();
    void setScreen(romeo::screen* current_screen);
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow*,float); 
    
};
}
#endif
